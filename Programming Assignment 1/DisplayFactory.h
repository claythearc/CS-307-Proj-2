			/*******************************************************************
			*   Source Code DisplayFactory.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#pragma once
#include "Display.h"
class DisplayFactory
{
	static DisplayFactory* instance;
	DisplayFactory();
public:
	static DisplayFactory* getInstance();
	~DisplayFactory(void);
	Display CreateDisplay(int* ids, int size, char* name);
};

