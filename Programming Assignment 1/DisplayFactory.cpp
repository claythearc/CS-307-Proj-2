			/*******************************************************************
			*   Source Code DisplayFactory.cpp
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#include "stdafx.h"
#include "DisplayFactory.h"

//static variable for singleton
DisplayFactory* DisplayFactory::instance = nullptr;

//returns the instance of the class
DisplayFactory* DisplayFactory::getInstance() {
	if(!instance) {
		instance = new DisplayFactory();
	}
	return instance;
}

//private constructor
DisplayFactory::DisplayFactory(void)
{
}

//destructor
DisplayFactory::~DisplayFactory(void)
{
}

//calls the Display() constructor and retruns the object
Display DisplayFactory::CreateDisplay(int* ids, int size, char* name) {
	return Display(ids, size, name);
}
