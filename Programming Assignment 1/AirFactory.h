			/*******************************************************************
			*   Source Code AirFactory.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#pragma once
#include "SensorFactory.h"
#include "stdafx.h"


class AirFactory : public  SensorFactory
{
private:
	static AirFactory *instance;
	bool created;
	AirFactory();
public:
	static AirFactory* getInstance();
	~AirFactory(void);
	AirSensor CreateAirSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
};
