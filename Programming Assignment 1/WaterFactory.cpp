			/*******************************************************************
			*   Source Code WaterFactory.cpp
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "WaterFactory.h"
#include "SensorFactory.h"

//Static variable for singleton
WaterFactory* WaterFactory::instance = nullptr; 

//private constructor
WaterFactory::WaterFactory(void)
{
}

//returns the instance of the water factory class
WaterFactory* WaterFactory::getInstance() {
	if (instance == nullptr)
    {
		instance = new WaterFactory();
    }

    return instance;
}

//calls water sensor constructor.
WaterSensor WaterFactory::CreateWaterSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	return WaterSensor( time, id,  minValue,  maxValue, name,  material, units);
}


WaterFactory::~WaterFactory(void)
{
	delete instance;
}