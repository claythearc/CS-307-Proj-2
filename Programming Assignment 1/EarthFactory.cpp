			/*******************************************************************
			*   Source Code EarthFactory.cpp
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#include "stdafx.h"
#include "EarthFactory.h"
#include "SensorFactory.h"

//static variable for singleton
EarthFactory* EarthFactory::instance = nullptr;

EarthFactory::EarthFactory(void)
{
}

//returns the instance of the class
EarthFactory* EarthFactory::getInstance() {
	if (instance == nullptr)
    {
		instance = new EarthFactory();
    }

    return instance;
}

//creates and earth sensor and returns it
EarthSensor EarthFactory::CreateEarthSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	return EarthSensor( time, id,  minValue,  maxValue, name,  material, units);
}


EarthFactory::~EarthFactory(void)
{
	delete instance;
}
