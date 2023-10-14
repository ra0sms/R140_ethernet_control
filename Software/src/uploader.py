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


def show_file_messagebox():
    msg = QMessageBox()
    msg.setIcon(QMessageBox.Warning)
    msg.setText("Config file not found!")
    msg.setWindowTitle("Warning")
    msg.setStandardButtons(QMessageBox.Ok)
    retval = msg.exec_()


def read_from_config_file():
    try:
        with open("ip_config.ini", "r") as f:
            text = f.readline()
            text = text.split(sep=":")
            print(text)
            config_ip = text[1].strip().rstrip()
            print(config_ip)
            ui.configIPL.setText("Config IP address: " + config_ip)
            return True
    except FileNotFoundError:
        show_file_messagebox()
        ui.labelIP.setText("Config IP address: None")
        return False


def on_read():
    if not serial.canReadLine():
        print("not a line")
        return
    rx = serial.readLine()
    rxs = str(rx, 'utf-8').strip()
    print(rxs)
    read_from_config_file()
    ui.consoleIPL.setText("Console IP address: " + rxs)


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


def get_ip():
    get = "GET\r"
    serial.write(get.encode())


serial.readyRead.connect(on_read)
ui.openB.clicked.connect(on_open)
ui.getB.clicked.connect(get_ip)


ui.show()
app.exec()