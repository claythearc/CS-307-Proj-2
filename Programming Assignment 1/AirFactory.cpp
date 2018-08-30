			/*******************************************************************
			*   Source Code AirFactory.cpp
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#pragma once
#include "stdafx.h"
#include "AirFactory.h"
#include "SensorFactory.h"

//static variable for pointer to singleton
AirFactory* AirFactory::instance = nullptr;
//returns the instance of the class
AirFactory* AirFactory::getInstance() {
	if (!instance)
    {
		instance = new AirFactory();
    }

    return instance;
}

//constructor with boolean flag for debugging output
AirFactory::AirFactory()
{
	AirFactory::created = true;
}

//calls the air sensor constructor
AirSensor AirFactory::CreateAirSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	return AirSensor( time, id,  minValue,  maxValue, name,  material, units);
}


AirFactory::~AirFactory(void)
{
}