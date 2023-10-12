/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "socket.h"
#include "dhcp.h"
#include "dns.h"

#define EEPROM_ADRESS_START 0x08030000

char str_rx2[25];
char flag_ok = 0;
uint8_t out1[8];
uint8_t out2[8];
char *get_url;
char post_url[25];
uint8_t flag_usb = 0;
uint8_t flag_ethernet = 0;
char ip1 = 0;
char ip2 = 0;
char ip3 = 0;
char ip4 = 0;
char gw1 = 0;
char gw2 = 0;
char gw3 = 0;
char gw4 = 0;


void USART1_Send (char chr);
void USART1_Send_String (char* str);

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */


void Set_outputs (char* str_rx1)
{
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[3] == '1')) out1[0] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[3] == '0')) out1[0] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[4] == '1')) out1[1] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[4] == '0')) out1[1] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[5] == '1')) out1[2] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[5] == '0')) out1[2] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[6] == '1')) out1[3] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[6] == '0')) out1[3] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[7] == '1')) out1[4] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[7] == '0')) out1[4] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[8] == '1')) out1[5] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[8] == '0')) out1[5] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[9] == '1')) out1[6] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[9] == '0')) out1[6] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[10] == '1')) out1[7] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[10] == '0')) out1[7] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[11] == '1')) out2[0] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[11] == '0')) out2[0] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[12] == '1')) out2[1] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[12] == '0')) out2[1] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[13] == '1')) out2[2] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[13] == '0')) out2[2] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[14] == '1')) out2[3] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[14] == '0')) out2[3] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[15] == '1')) out2[4] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[15] == '0')) out2[4] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[16] == '1')) out2[5] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[16] == '0')) out2[5] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[17] == '1')) out2[6] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[17] == '0')) out2[6] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[18] == '1')) out2[7] = 1;
	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(str_rx1[2] == '1')&&(str_rx1[18] == '0')) out2[7] = 0;

	if ((str_rx1[0] == 'A')&&(str_rx1[1] == 'M')&&(flag_ok ==1)){ USART1_Send_String ("OK"); flag_ok=0;}

		if (out1[0] ==1) LL_GPIO_SetOutputPin(OUT1_GPIO_Port, OUT1_Pin); else LL_GPIO_ResetOutputPin(OUT1_GPIO_Port, OUT1_Pin);
		if (out1[1] ==1) LL_GPIO_SetOutputPin(OUT2_GPIO_Port, OUT2_Pin); else LL_GPIO_ResetOutputPin(OUT2_GPIO_Port, OUT2_Pin);
		if (out1[2] ==1) LL_GPIO_SetOutputPin(OUT3_GPIO_Port, OUT3_Pin); else LL_GPIO_ResetOutputPin(OUT3_GPIO_Port, OUT3_Pin);
		if (out1[3] ==1) LL_GPIO_SetOutputPin(OUT4_GPIO_Port, OUT4_Pin); else LL_GPIO_ResetOutputPin(OUT4_GPIO_Port, OUT4_Pin);
		if (out1[4] ==1) LL_GPIO_SetOutputPin(OUT5_GPIO_Port, OUT5_Pin); else LL_GPIO_ResetOutputPin(OUT5_GPIO_Port, OUT5_Pin);
		if (out1[5] ==1) LL_GPIO_SetOutputPin(OUT6_GPIO_Port, OUT6_Pin); else LL_GPIO_ResetOutputPin(OUT6_GPIO_Port, OUT6_Pin);
		if (out1[6] ==1) LL_GPIO_SetOutputPin(OUT7_GPIO_Port, OUT7_Pin); else LL_GPIO_ResetOutputPin(OUT7_GPIO_Port, OUT7_Pin);
		if (out1[7] ==1) LL_GPIO_SetOutputPin(OUT8_GPIO_Port, OUT8_Pin); else LL_GPIO_ResetOutputPin(OUT8_GPIO_Port, OUT8_Pin);

		if (out2[0] ==1) LL_GPIO_SetOutputPin(OUT9_GPIO_Port, OUT9_Pin); else LL_GPIO_ResetOutputPin(OUT9_GPIO_Port, OUT9_Pin);
		if (out2[1] ==1) LL_GPIO_SetOutputPin(OUT10_GPIO_Port, OUT10_Pin); else LL_GPIO_ResetOutputPin(OUT10_GPIO_Port, OUT10_Pin);
		if (out2[2] ==1) LL_GPIO_SetOutputPin(OUT11_GPIO_Port, OUT11_Pin); else LL_GPIO_ResetOutputPin(OUT11_GPIO_Port, OUT11_Pin);
		if (out2[3] ==1) LL_GPIO_SetOutputPin(OUT12_GPIO_Port, OUT12_Pin); else LL_GPIO_ResetOutputPin(OUT12_GPIO_Port, OUT12_Pin);
		if (out2[4] ==1) LL_GPIO_SetOutputPin(OUT13_GPIO_Port, OUT13_Pin); else LL_GPIO_ResetOutputPin(OUT13_GPIO_Port, OUT13_Pin);
		if (out2[5] ==1) LL_GPIO_SetOutputPin(OUT14_GPIO_Port, OUT14_Pin); else LL_GPIO_ResetOutputPin(OUT14_GPIO_Port, OUT14_Pin);
		if (out2[6] ==1) LL_GPIO_SetOutputPin(OUT15_GPIO_Port, OUT15_Pin); else LL_GPIO_ResetOutputPin(OUT15_GPIO_Port, OUT15_Pin);
		if (out2[7] ==1) LL_GPIO_SetOutputPin(OUT16_GPIO_Port, OUT16_Pin); else LL_GPIO_ResetOutputPin(OUT16_GPIO_Port, OUT16_Pin);

}


unsigned const char SVG[] = "<svg version=\"1.0\" xmlns=\"http://www.w3.org/2000/svg\""
		"width=\"99.000000pt\" height=\"35.000000pt\" viewBox=\"0 0 790.000000 284.000000\""
		 "preserveAspectRatio=\"xMidYMid meet\">"
		"<g transform=\"translate(0.000000,284.000000) scale(0.100000,-0.100000)\""
		"fill=\"#000000\" stroke=\"none\">"
		"<path d=\"M0 1420 l0 -1420 910 0 910 0 0 1420 0 1420 -910 0 -910 0 0 -1420z "
		"m1620 0 l0 -1220 -710 0 -710 0 0 1220 0 1220 710 0 710 0 0 -1220z\"/>"
		"<path d=\"M392 1983 l3 -458 103 -3 102 -3 0 161 0 160 270 0 c176 0 277 -4 "
		"293 -11 39 -18 47 -50 47 -184 l0 -125 106 0 106 0 -4 153 c-3 173 -15 206 "
		"-80 241 l-35 20 31 21 c69 46 101 130 93 241 -8 110 -54 181 -142 221 -36 16 "
		"-81 18 -468 21 l-427 3 2 -458z m789 244 c48 -37 53 -115 10 -158 l-29 -29 "
		"-281 0 -281 0 0 100 0 100 283 0 c206 -1 286 -4 298 -13z\"/>"
		"<path d=\"M394 1294 c-4 -14 -4 -164 -1 -332 4 -275 7 -314 25 -372 25 -76 71 "
		"-127 147 -162 49 -23 57 -23 453 -26 l402 -3 0 460 0 461 -105 0 -105 0 0 "
		"-366 0 -366 -258 4 c-375 5 -350 -27 -351 451 l-1 277 -100 0 c-99 0 -100 0 "
		"-106 -26z\"/>"
		"<path d=\"M2210 1980 l0 -460 100 0 100 0 0 315 c0 173 3 315 6 315 4 0 62 -52 "
		"131 -116 123 -116 124 -117 145 -98 12 11 69 63 127 117 l106 98 3 -315 2 "
		"-316 100 0 100 0 0 460 0 460 -56 0 c-96 0 -129 -16 -233 -114 -53 -50 -113 "
		"-106 -133 -125 l-38 -35 -119 117 c-138 135 -175 156 -273 157 l-68 0 0 -460z\"/>"
		"<path d=\"M3530 2433 c-102 -17 -166 -63 -197 -143 -15 -39 -17 -93 -21 -407 "
		"l-4 -363 106 0 106 0 0 155 0 155 250 0 250 0 0 -155 0 -155 105 0 105 0 0 "
		"460 0 460 -337 -1 c-186 -1 -349 -4 -363 -6z m490 -303 l0 -110 -250 0 -250 0 "
		"1 78 c1 142 -1 141 282 142 l217 0 0 -110z\"/>"
		"<path d=\"M4410 1980 l0 -461 353 3 c400 5 420 8 481 79 55 64 61 104 61 379 0 "
		"275 -6 315 -61 379 -61 71 -81 74 -481 79 l-353 3 0 -461z m644 249 c14 -7 30 "
		"-25 36 -42 13 -39 13 -375 0 -414 -17 -48 -41 -53 -265 -53 l-205 0 0 260 0 "
		"260 205 0 c131 0 213 -4 229 -11z\"/>"
		"<path d=\"M5680 2433 c-106 -18 -176 -72 -200 -156 -17 -60 -25 -449 -11 -533 "
		"15 -83 41 -136 83 -167 66 -48 84 -51 426 -55 l322 -3 0 100 0 101 -292 0 "
		"c-161 0 -298 4 -305 8 -19 12 -33 60 -33 113 l0 49 250 0 250 0 0 95 0 95 "
		"-250 0 -250 0 0 44 c0 49 15 96 33 108 7 4 137 8 290 8 l277 0 0 100 0 100 "
		"-282 -1 c-156 -1 -294 -4 -308 -6z\"/>"
		"<path d=\"M6580 1980 l0 -460 105 0 105 0 0 460 0 460 -105 0 -105 0 0 -460z\"/>"
		"<path d=\"M6980 1980 l0 -460 100 0 100 0 2 302 3 302 101 -125 c55 -68 140 "
		"-173 188 -234 173 -216 202 -236 339 -243 l87 -4 0 461 0 461 -100 0 -100 0 0 "
		"-301 c0 -187 -4 -298 -9 -294 -9 5 -48 52 -310 377 -56 70 -119 141 -139 158 "
		"-49 40 -112 60 -194 60 l-68 0 0 -460z\"/>"
		"<path d=\"M2217 1314 c-4 -4 -7 -211 -7 -461 l0 -453 105 0 105 0 0 161 0 160 "
		"226 -3 226 -3 24 -28 c23 -27 24 -35 24 -158 l0 -129 105 0 105 0 0 143 c0 "
		"166 -14 213 -75 248 l-36 22 34 23 c19 13 45 45 58 71 20 40 24 63 24 143 0 "
		"105 -16 149 -72 202 -62 59 -84 62 -478 66 -198 2 -364 0 -368 -4z m672 -209 "
		"c34 -17 41 -33 41 -89 0 -33 -6 -49 -26 -70 l-27 -26 -228 0 -229 0 0 100 0 "
		"100 220 0 c174 0 227 -3 249 -15z\"/>"
		"<path d=\"M3310 992 c0 -191 5 -353 11 -388 16 -90 48 -137 116 -171 l58 -28 "
		"368 -3 367 -3 0 460 0 461 -105 0 -105 0 0 -366 0 -366 -217 4 c-120 3 -226 8 "
		"-236 12 -44 20 -47 47 -47 391 l0 325 -105 0 -105 0 0 -328z\"/>"
		"<path d=\"M4625 1315 c-5 -2 -26 -6 -46 -9 -54 -9 -126 -62 -157 -115 -25 -42 "
		"-27 -55 -27 -146 0 -83 4 -107 22 -140 28 -52 57 -79 118 -107 47 -22 63 -23 "
		"295 -26 135 -1 255 -5 268 -7 62 -14 82 -90 38 -142 l-24 -28 -336 -3 -336 -3 "
		"0 -95 0 -95 368 3 c349 3 369 4 412 24 101 47 145 124 145 254 0 137 -51 217 "
		"-164 262 -51 19 -79 22 -306 25 -289 5 -295 6 -295 77 0 28 6 48 17 57 12 11 "
		"86 15 342 19 l326 5 3 75 c2 41 0 85 -3 97 l-5 23 -323 -1 c-177 0 -326 -2 "
		"-332 -4z\"/>"
		"<path d=\"M5653 1306 c-130 -32 -201 -138 -191 -287 6 -82 46 -161 99 -196 70 "
		"-46 116 -53 349 -53 126 0 230 -4 247 -10 49 -17 68 -84 38 -127 -26 -37 -76 "
		"-43 -377 -43 l-288 0 0 -95 0 -95 322 0 c370 0 407 5 482 72 58 50 80 109 81 "
		"208 0 93 -17 141 -67 196 -71 77 -112 86 -397 92 -221 4 -245 6 -262 23 -26 "
		"26 -25 83 1 109 19 19 33 20 320 20 l300 0 0 100 0 100 -302 -1 c-207 0 -319 "
		"-5 -355 -13z\"/>"
		"<path d=\"M6580 860 l0 -460 105 0 105 0 0 460 0 460 -105 0 -105 0 0 -460z\"/>"
		"<path d=\"M7189 1310 c-93 -16 -158 -67 -190 -150 -10 -26 -14 -125 -17 -397 "
		"l-3 -363 105 0 106 0 0 155 0 155 250 0 250 0 0 -155 0 -155 105 0 105 0 0 "
		"460 0 460 -332 -1 c-183 -1 -354 -5 -379 -9z m501 -300 l0 -110 -250 0 -250 0 "
		"0 75 c0 82 12 118 44 133 12 6 111 11 239 11 l217 1 0 -110z\"/>"
		"</g>"
		"</svg>";

unsigned const char javaScript[] = "<SCRIPT>\n"
		"var xmlHttp=createXmlHttpObject();\n"
		"function createXmlHttpObject(){\n"
		" if(window.XMLHttpRequest){\n"
		"    xmlHttp=new XMLHttpRequest();\n"
		" }else{\n"
		"    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');\n"
		" }\n"
		" return xmlHttp;\n"
		"}\n"
		"function process(){\n"
		" if(xmlHttp.readyState==0 || xmlHttp.readyState==4){\n"
		"   xmlHttp.open('PUT','xml',true);\n"
		"   xmlHttp.onreadystatechange=handleServerResponse;\n"
		"   xmlHttp.send(null);\n"
		" }\n"
		" setTimeout('process()',0.1);\n"
		"}\n"
		"function handleServerResponse(){\n"
		" if(xmlHttp.readyState==4 && xmlHttp.status==200){\n"
		"   xmlResponse=xmlHttp.responseXML;\n"
		"   xmldoc = xmlResponse.getElementsByTagName('response');\n"
		"   message = xmldoc[0].firstChild.nodeValue;\n"
		"   document.getElementById('runtime').innerHTML=message;\n"
		" }\n"
		"}\n"
		"</SCRIPT>\n";


uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);
#define HTTP_SOCKET     0
#define PORT_TCPS		5000
#define DATA_BUF_SIZE   8196
char gDATABUF[DATA_BUF_SIZE];

wiz_NetInfo gWIZNETINFO = { .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                            .ip = {192, 168, 000, 230},
                            .sn = {255, 255, 255, 000},
                            .gw = {192, 168, 000, 001},
                            .dns = {8, 8, 8, 8},
                            .dhcp = NETINFO_STATIC };



void UART_Printf(const char* fmt, ...) {
    char buff[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buff, sizeof(buff), fmt, args);
    CDC_Transmit_FS((uint8_t*)buff, strlen(buff));
    va_end(args);
}

uint8_t stat;
uint8_t reqnr;
char msg[10];
const char http_200_header[] =
        "HTTP/1.0 200 OK\r\n"
        "Content-Type: text/html; charset=windows-1251\r\n"
        "Server: STM32\r\n"
        "\r\n";


const char http_404_header[] =
        "HTTP/1.0 404 Not Found\r\n"
        "Content-Type: text/html;"
        "Server: STM32\r\n"
        "\r\n"
        "<pre>Page not found\r\n\r\n";

char webPage[]="<h1>Start page Remote console</h1>";

char startPage[]=
		"<h1>Start page Remote console</h1>"
		"<p><a href='/wifi'>Config the wifi connection</a></p>"
		"<p><a href='/switch'>Antenna switch</a></p>"
		"<p><a href='/toggle'>Toggle switch</a></p>"
		"<p><a href='/label'>Config name of labels</a></p>";


void BuildStartPage (char* buf){
	strcpy(buf,http_200_header);
	strcat(buf, (char *)startPage);
	strcat(buf, (char *)SVG);

}


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */
void W5500_Select(void)
{
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);
}

void W5500_Unselect(void)
{
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);
}

void W5500_ReadBuff(uint8_t* buff, uint16_t len)
{
    HAL_SPI_Receive(&hspi1, buff, len, HAL_MAX_DELAY);
}

void W5500_WriteBuff(uint8_t* buff, uint16_t len)
{
    HAL_SPI_Transmit(&hspi1, buff, len, HAL_MAX_DELAY);
}

uint8_t W5500_ReadByte(void)
{
    uint8_t byte;
    W5500_ReadBuff(&byte, sizeof(byte));
    return byte;
}

void W5500_WriteByte(uint8_t byte)
{
    W5500_WriteBuff(&byte, sizeof(byte));
}


int32_t loopback_tcps(uint8_t sn, char *buf, uint16_t port) {
	int32_t ret;
	uint32_t size = 0, sentsize = 0;
	char *url;

	switch (getSn_SR(sn)) {
	case SOCK_ESTABLISHED:
		if (getSn_IR(sn) & Sn_IR_CON) {
			UART_Printf("%d:Connected\r\n", sn);
			setSn_IR(sn, Sn_IR_CON);
		}
		if ((size = getSn_RX_RSR(sn)) > 0) {
			if (size > DATA_BUF_SIZE)
				size = DATA_BUF_SIZE;
			ret = recv(sn, buf, size);
			if (ret <= 0)
				return ret;
			sentsize = 0;
//=============================================
			if (memcmp(buf, "GET ", 4) == 0) {
				url = buf + 4;

				if (memcmp(url, "/status", 7) == 0) {
					strcpy(buf, (char *)post_url);
				} else if ((memcmp(url, "/ H", 3) == 0)) {
					BuildStartPage(buf);
				} else if (memcmp(url, "/AM1", 4) == 0) {
					get_url = url + 1;
					strncpy(post_url, (char *)get_url,19);
					Set_outputs(get_url);
					BuildStartPage(buf);
				}else

				{
					strcpy(buf, http_404_header);
				}
				//======================================================
				size = strlen(buf);
				while (size != sentsize) {
					ret = send(sn, buf + sentsize, size - sentsize);
					if (ret < 0) {
						close(sn);
						return ret;
					}
					sentsize += ret;
				}
			}
			disconnect(sn);
		}
		break;
	case SOCK_CLOSE_WAIT:
		UART_Printf("%d:CloseWait\r\n", sn);
		if ((ret = disconnect(sn)) != SOCK_OK)
			return ret;
		UART_Printf("%d:Closed\r\n", sn);
		break;
	case SOCK_INIT:
		UART_Printf("%d:Listen, port [%d]\r\n", sn, port);
		if ((ret = listen(sn)) != SOCK_OK)
			return ret;
		break;
	case SOCK_CLOSED:
		UART_Printf("%d:LBTStart\r\n", sn);
		if ((ret = socket(sn, Sn_MR_TCP, port, 0x00)) != sn)
			return ret;
		UART_Printf("%d:Opened\r\n", sn);
		break;
	default:
		break;
	}
	return 1;
}

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM10_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */


void USART1_Send (char chr){
	while (!(USART1->SR & USART_SR_TC));
	USART1->DR = chr;
}

void USART1_Send_String (char* str){
	uint8_t i = 0;
	while(str[i])
	USART1_Send (str[i++]);
}

void WriteToEEPROM (uint32_t address, wiz_NetInfo value)
{
     HAL_FLASH_Unlock();
     __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );
     FLASH_Erase_Sector(FLASH_SECTOR_5, VOLTAGE_RANGE_3);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address, value.ip[0]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+4, value.ip[1]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+8, value.ip[2]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+12, value.ip[3]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+16, value.gw[0]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+20, value.gw[1]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+24, value.gw[2]);
     HAL_FLASH_Program(TYPEPROGRAM_WORD, address+28, value.gw[3]);

     HAL_FLASH_Lock();
}

uint32_t ReadFromEEPROM (uint32_t address)
{
  return (*(__IO uint32_t *)address);
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM10_Init();
  MX_USB_DEVICE_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	LL_TIM_EnableIT_UPDATE(TIM10);
	LL_TIM_EnableCounter(TIM10);
	LL_USART_Enable(USART1);
	LL_USART_EnableIT_RXNE(USART1);
	HAL_GPIO_WritePin(SPI_RST_GPIO_Port, SPI_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(SPI_RST_GPIO_Port, SPI_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);

	reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
	reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
	reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);

	uint8_t rx_tx_buff_sizes[] = { 2, 2, 2, 2, 2, 2, 2, 2 };

	wizchip_init(rx_tx_buff_sizes, rx_tx_buff_sizes);

	//WriteToEEPROM(EEPROM_ADRESS_START, gWIZNETINFO);

	gWIZNETINFO.ip[0] = ReadFromEEPROM(EEPROM_ADRESS_START);
	gWIZNETINFO.ip[1] = ReadFromEEPROM(EEPROM_ADRESS_START+4);
	gWIZNETINFO.ip[2] = ReadFromEEPROM(EEPROM_ADRESS_START+8);
	gWIZNETINFO.ip[3] = ReadFromEEPROM(EEPROM_ADRESS_START+12);

	gWIZNETINFO.gw[0] = ReadFromEEPROM(EEPROM_ADRESS_START+16);
	gWIZNETINFO.gw[1] = ReadFromEEPROM(EEPROM_ADRESS_START+20);
	gWIZNETINFO.gw[2] = ReadFromEEPROM(EEPROM_ADRESS_START+24);
	gWIZNETINFO.gw[3] = ReadFromEEPROM(EEPROM_ADRESS_START+28);


	wizchip_setnetinfo(&gWIZNETINFO);

	ctlnetwork(CN_SET_NETINFO, (void*) &gWIZNETINFO);
	HAL_Delay(1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	while (1) {
		UART_Printf("Creating socket...\r\n");
		stat = socket(HTTP_SOCKET, Sn_MR_TCP, 80, 0);
		if (stat != HTTP_SOCKET)
			UART_Printf("socket() failed, code = %d\r\n", stat);
		else
			UART_Printf("Socket created, connecting...\r\n");
		stat = listen(HTTP_SOCKET);
		if (stat != SOCK_OK)
			UART_Printf("listen() failed, code = %d\r\n", stat);
		else
			UART_Printf("listen() OK\r\n");
		while (getSn_SR(HTTP_SOCKET) == SOCK_LISTEN) {
			HAL_Delay(5);
			if (flag_usb == 1) {
				flag_usb = 0;
				strcpy(post_url,(char *) str_rx2);
				USART1_Send(ip1);
				USART1_Send('.');
				USART1_Send(ip2);
				USART1_Send('.');
				USART1_Send(ip3);
				USART1_Send('.');
				USART1_Send(ip4);
				USART1_Send('\r');
				USART1_Send(gw1);
				USART1_Send('.');
				USART1_Send(gw2);
				USART1_Send('.');
				USART1_Send(gw3);
				USART1_Send('.');
				USART1_Send(gw4);
				Set_outputs(str_rx2);
			}
		}
		UART_Printf("Input connection\r\n");
		if (getSn_SR(HTTP_SOCKET) != SOCK_ESTABLISHED)
			UART_Printf("Error socket status\r\n");
		uint8_t rIP[4];
		getsockopt(HTTP_SOCKET, SO_DESTIP, rIP);
		UART_Printf("IP:  %d.%d.%d.%d\r\n", rIP[0], rIP[1], rIP[2], rIP[3]);

		loopback_tcps(HTTP_SOCKET, gDATABUF, 80);

		close(HTTP_SOCKET);

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM10 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM10_Init(void)
{

  /* USER CODE BEGIN TIM10_Init 0 */

  /* USER CODE END TIM10_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM10);

  /* TIM10 interrupt Init */
  NVIC_SetPriority(TIM1_UP_TIM10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

  /* USER CODE BEGIN TIM10_Init 1 */

  /* USER CODE END TIM10_Init 1 */
  TIM_InitStruct.Prescaler = 41999;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 499;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM10, &TIM_InitStruct);
  LL_TIM_EnableARRPreload(TIM10);
  /* USER CODE BEGIN TIM10_Init 2 */

  /* USER CODE END TIM10_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  LL_USART_InitTypeDef USART_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  /**USART1 GPIO Configuration
  PA9   ------> USART1_TX
  PA10   ------> USART1_RX
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_9|LL_GPIO_PIN_10;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USART1 interrupt Init */
  NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(USART1_IRQn);

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  USART_InitStruct.BaudRate = 115200;
  USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
  USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
  USART_InitStruct.Parity = LL_USART_PARITY_NONE;
  USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
  USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
  USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
  LL_USART_Init(USART1, &USART_InitStruct);
  LL_USART_ConfigAsyncMode(USART1);
  LL_USART_Enable(USART1);
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

  /**/
  LL_GPIO_ResetOutputPin(LED_GPIO_Port, LED_Pin);

  /**/
  LL_GPIO_ResetOutputPin(GPIOA, SPI_RST_Pin|SPI1_CS_Pin|OUT16_Pin);

  /**/
  LL_GPIO_ResetOutputPin(GPIOB, OUT1_Pin|OUT2_Pin|OUT3_Pin|OUT11_Pin
                          |OUT12_Pin|OUT13_Pin|OUT14_Pin|OUT15_Pin
                          |OUT4_Pin|OUT5_Pin|OUT6_Pin|OUT7_Pin
                          |OUT8_Pin|OUT9_Pin|OUT10_Pin);

  /**/
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = BTN_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(BTN_GPIO_Port, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = SPI_RST_Pin|SPI1_CS_Pin|OUT16_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /**/
  GPIO_InitStruct.Pin = OUT1_Pin|OUT2_Pin|OUT3_Pin|OUT11_Pin
                          |OUT12_Pin|OUT13_Pin|OUT14_Pin|OUT15_Pin
                          |OUT4_Pin|OUT5_Pin|OUT6_Pin|OUT7_Pin
                          |OUT8_Pin|OUT9_Pin|OUT10_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
