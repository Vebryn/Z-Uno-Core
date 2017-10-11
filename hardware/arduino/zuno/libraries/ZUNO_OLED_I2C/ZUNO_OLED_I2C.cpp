/*
  OLED_I2C.cpp - Arduino/chipKit library support for 128x64 pixel SSD1306 OLEDs
  Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
  
  This library has been made to make it easy to use 128x64 pixel OLED displays
  based on the SSD1306 controller chip with an Arduino or a chipKit.

  You can always find the latest version of the library at 
  http://www.RinkyDinkElectronics.com/

  This library is free software; you can redistribute it and/or
  modify it under the terms of the CC BY-NC-SA 3.0 license.
  Please see the included documents for further information.

  Commercial use of this library requires you to buy a license that
  will allow commercial use. This includes using the library,
  modified or not, as a tool to sell products.

  The license applies to all part of the library including the 
  examples and tools supplied with the library.
*/

#include "ZUNO_OLED_I2C.h"
#include "Wire.h"


// Macroses to make code clean
// ----------------------------------------------------------------------------------------------------------------
#define _sendTWIcommand(D) g_oled_command = D; OLED_writeCommand();
#define _sendTWIAddr(a1,a2,a3,a4) g_oled_addr1=a1;g_oled_addr2=a2;g_oled_addr3=a3;g_oled_addr4=a4;OLED_SetAdress();
//-----------------------------------------------------------------------------------------------------------------
extern byte g_oled_command;
extern word g_oled_count;
extern byte g_oled_cb;
extern byte g_oled_addr1;
extern byte g_oled_addr2;
extern byte g_oled_addr3;
extern byte g_oled_addr4;
// -----------------------------------------------------
// GLOBAL variables
byte g_oled_command = 0;
byte g_oled_addr1 = 0;
byte g_oled_addr2 = 0;
byte g_oled_addr3 = 0;
byte g_oled_addr4 = 0;
byte g_oled_cb;
word g_oled_count;
// -----------------------------------------------------
// -----------------------------------------------------
// Auxilary functions to reduce stack & memory usage
// -----------------------------------------------------
void OLED_writeCommand() {
	Wire.beginTransmission(SSD1306_ADDR);
  	Wire.write(SSD1306_COMMAND);
  	Wire.write(g_oled_command);
  	Wire.endTransmission();	
}
void OLED_SetAdress() {
	_sendTWIcommand(SSD1306_SET_COLUMN_ADDR);
	_sendTWIcommand(g_oled_addr1);
	_sendTWIcommand(g_oled_addr2);
	_sendTWIcommand(SSD1306_SET_PAGE_ADDR);
	_sendTWIcommand(g_oled_addr3);
	_sendTWIcommand(g_oled_addr4);
}
// -----------------------------------------------------
OLED::OLED(){ 
}
void OLED::begin()
{
	

	Wire.begin();

	_sendTWIcommand(SSD1306_DISPLAY_OFF);
    _sendTWIcommand(SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO);
    _sendTWIcommand(0x80);
    _sendTWIcommand(SSD1306_SET_MULTIPLEX_RATIO);
    _sendTWIcommand(0x3F);
    _sendTWIcommand(SSD1306_SET_DISPLAY_OFFSET);
    _sendTWIcommand(0x0);
    _sendTWIcommand(SSD1306_SET_START_LINE | 0x0);
    _sendTWIcommand(SSD1306_CHARGE_PUMP);
	_sendTWIcommand(0x14);
    _sendTWIcommand(SSD1306_MEMORY_ADDR_MODE);
    _sendTWIcommand(0x00);
    _sendTWIcommand(SSD1306_SET_SEGMENT_REMAP | 0x1);
    _sendTWIcommand(SSD1306_COM_SCAN_DIR_DEC);
    _sendTWIcommand(SSD1306_SET_COM_PINS);
    _sendTWIcommand(0x12);
    _sendTWIcommand(SSD1306_SET_CONTRAST_CONTROL);
	_sendTWIcommand(0xCF);
    _sendTWIcommand(SSD1306_SET_PRECHARGE_PERIOD);
	_sendTWIcommand(0xF1);
    _sendTWIcommand(SSD1306_SET_VCOM_DESELECT);
    _sendTWIcommand(0x40);
    _sendTWIcommand(SSD1306_DISPLAY_ALL_ON_RESUME);
    _sendTWIcommand(SSD1306_NORMAL_DISPLAY);
	_sendTWIcommand(SSD1306_DISPLAY_ON);

	cx = 0; 
	cy = 0;

}
void OLED::clrscr()
{
	_sendTWIAddr(0,127,0,7);
	Wire.beginTransmission(SSD1306_ADDR);
  	Wire.write(SSD1306_DATA_CONTINUE);
  	g_oled_count = 1024;
  	while(g_oled_count--)
		Wire.write(0x00);
	Wire.endTransmission();	


}
// It's a bad idea to take there a lot of variables
// Just pass pointer to structure like this
// struct OLED_SPRITE_IMAGE { byte w; byte h; byte data[MAX_DATA]};
// NOTICE: structure uses a native format of the display 
// 		   w has pixel units,
// 		   h has 8-pixel block units
//         data  packed by columns. Each byte contains 8 verticals pixels of current column
void OLED::writeData(byte * pdata) {
	_sendTWIAddr(cx,cx+pdata[0],cy,cy+pdata[1]);
	// Write data consiquently
	Wire.beginTransmission(SSD1306_ADDR);
  	Wire.write(SSD1306_DATA_CONTINUE);
  	g_oled_count = pdata[0]*pdata[1];
  	// Shift to the beginning of the image data
  	pdata += 2;
  	// Go->>>
  	while(g_oled_count--) {
		Wire.write(*pdata);
		pdata++;
	}
	Wire.endTransmission();	
}
//static 
byte SmallFont[]  =
	{
		0x06, 0x08, 0x20, 0x5f,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // sp
		0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,   // !
		0x00, 0x00, 0x07, 0x00, 0x07, 0x00,   // "
		0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,   // #
		0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,   // $
		0x00, 0x23, 0x13, 0x08, 0x64, 0x62,   // %
		0x00, 0x36, 0x49, 0x55, 0x22, 0x50,   // &
		0x00, 0x00, 0x05, 0x03, 0x00, 0x00,   // '
		0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,   // (
		0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,   // )
		0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,   // *
		0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,   // +
		0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,   // ,
		0x00, 0x08, 0x08, 0x08, 0x08, 0x08,   // -
		0x00, 0x00, 0x60, 0x60, 0x00, 0x00,   // .
		0x00, 0x20, 0x10, 0x08, 0x04, 0x02,   // /

		0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,   // 0
		0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,   // 1
		0x00, 0x42, 0x61, 0x51, 0x49, 0x46,   // 2
		0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,   // 3
		0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,   // 4
		0x00, 0x27, 0x45, 0x45, 0x45, 0x39,   // 5
		0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,   // 6
		0x00, 0x01, 0x71, 0x09, 0x05, 0x03,   // 7
		0x00, 0x36, 0x49, 0x49, 0x49, 0x36,   // 8
		0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,   // 9
		0x00, 0x00, 0x36, 0x36, 0x00, 0x00,   // :
		0x00, 0x00, 0x56, 0x36, 0x00, 0x00,   // ;
		0x00, 0x08, 0x14, 0x22, 0x41, 0x00,   // <
		0x00, 0x14, 0x14, 0x14, 0x14, 0x14,   // =
		0x00, 0x00, 0x41, 0x22, 0x14, 0x08,   // >
		0x00, 0x02, 0x01, 0x51, 0x09, 0x06,   // ?

		0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,   // @
		0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,   // A
		0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,   // B
		0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,   // C
		0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,   // D
		0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,   // E
		0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,   // F
		0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,   // G
		0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,   // H
		0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,   // I
		0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,   // J
		0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,   // K
		0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,   // L
		0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,   // M
		0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,   // N
		0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,   // O

		0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,   // P
		0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,   // Q
		0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,   // R
		0x00, 0x46, 0x49, 0x49, 0x49, 0x31,   // S
		0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,   // T
		0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,   // U
		0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,   // V
		0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,   // W
		0x00, 0x63, 0x14, 0x08, 0x14, 0x63,   // X
		0x00, 0x07, 0x08, 0x70, 0x08, 0x07,   // Y
		0x00, 0x61, 0x51, 0x49, 0x45, 0x43,   // Z
		0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,   // [
		0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,   // Backslash (Checker pattern)
		0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,   // ]
		0x00, 0x04, 0x02, 0x01, 0x02, 0x04,   // ^
		0x00, 0x40, 0x40, 0x40, 0x40, 0x40,   // _

		0x00, 0x00, 0x03, 0x05, 0x00, 0x00,   // `
		0x00, 0x20, 0x54, 0x54, 0x54, 0x78,   // a
		0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,   // b
		0x00, 0x38, 0x44, 0x44, 0x44, 0x20,   // c
		0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,   // d
		0x00, 0x38, 0x54, 0x54, 0x54, 0x18,   // e
		0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,   // f
		0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,   // g
		0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,   // h
		0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,   // i
		0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,   // j
		0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,   // k
		0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,   // l
		0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,   // m
		0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,   // n
		0x00, 0x38, 0x44, 0x44, 0x44, 0x38,   // o

		0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,   // p
		0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,   // q
		0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,   // r
		0x00, 0x48, 0x54, 0x54, 0x54, 0x20,   // s
		0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,   // t
		0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,   // u
		0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,   // v
		0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,   // w
		0x00, 0x44, 0x28, 0x10, 0x28, 0x44,   // x
		0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,   // y
		0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,   // z
		0x00, 0x00, 0x10, 0x7C, 0x82, 0x00,   // {
		0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,   // |
		0x00, 0x00, 0x82, 0x7C, 0x10, 0x00,   // }
		0x00, 0x00, 0x06, 0x09, 0x09, 0x06    // ~ (Degrees)
	};
void OLED::write(uint8_t value) {
	// Process carrage return
	if(value == '\r')
	{	
		// Carrage return
		cx = 0;	
		return;
	}
	// Process NEWLINE
	if(value == '\n') {
		// Next line
		cy = (cy + 1)%8;
		// Carrage return
		cx = 0;	
		return;
	}
	// We use small font and it uses only 6 raws of data
	g_oled_cb = 6;
	// Calculate start "pixel" of the symbol
	// Font starts from the "space" symbol (CODE = 0x20)
	// Every sybol uses 6 bytes of font 
	g_oled_count = 6*(value - 0x20)+4;
	// Setting up working area columns cx..cx+5, row = cy
	_sendTWIAddr(cx,cx+5,cy,cy);
	// Send data to display consiquently
	Wire.beginTransmission(SSD1306_ADDR);
  	Wire.write(SSD1306_DATA_CONTINUE);
  	while(g_oled_cb--) {
		Wire.write(SmallFont[g_oled_count]);
		g_oled_count++;
	}
	Wire.endTransmission();	
	// Increase the current position 
	cx += 6;
	// Increase the current line
	if((cx + 6) > 127){
		cx = 0;
		cy = (cy + 1)%8;
	}

}
void OLED::on() {
	_sendTWIcommand(SSD1306_DISPLAY_ON);
}
void OLED::off() {
	_sendTWIcommand(SSD1306_DISPLAY_OFF);
}
void OLED::gotoXY(byte x, byte y) {
	cx = x;
	cy = y;
}
void OLED::setBrightness(uint8_t value) {
	_sendTWIcommand(SSD1306_SET_CONTRAST_CONTROL);
	_sendTWIcommand(value);
}
void OLED::invert(bool mode) {
	if (mode) {
		_sendTWIcommand(SSD1306_INVERT_DISPLAY);
	}
	else {
		_sendTWIcommand(SSD1306_NORMAL_DISPLAY);
	}
}

