import PyQt5.QtWidgets
from PyQt5 import QtWidgets, uic, QtGui
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtCore import QIODevice, QTimer, QEvent
from PyQt5.QtWidgets import QMessageBox, QWidget


app = QtWidgets.QApplication([])
ui = uic.loadUi("uploader_design.ui")
ui.setWindowTitle("Uploader for remote control")
ui.setWindowIcon(QtGui.QIcon("logo.png"))

serial = QSerialPort()
timer = QTimer()
serial.setBaudRate(115200)
portList = []
ports = QSerialPortInfo().availablePorts()
for port in ports:
    portList.append(port.portName())
ui.comL.addItems(portList)


def on_open():
    if serial.isOpen():
        ui.openB.setText("OPEN")
        ui.labelCOM.setText("COM port closed")
        serial.close()
    else:
        serial.setPortName(ui.comL.currentText())
        serial.open(QIODevice.ReadWrite)
        ui.labelCOM.setText("COM port opened")
        ui.openB.setText("CLOSE")


ui.openB.clicked.connect(on_open)


ui.show()
app.exec()