			/*******************************************************************
			*   Source Code WaterFactory.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#pragma once
#include "SensorFactory.h"
#include "stdafx.h"



class WaterFactory : public SensorFactory
{
private:
	static WaterFactory *instance;
	WaterFactory();
public:
	static WaterFactory* getInstance();
	~WaterFactory(void);
	WaterSensor CreateWaterSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
};

