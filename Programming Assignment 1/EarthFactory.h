			/*******************************************************************
			*   Source Code EarthFactory.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#pragma once
#include "SensorFactory.h"
#include "stdafx.h"



class EarthFactory : public SensorFactory
{
private:
	static EarthFactory* instance;
	EarthFactory();
public:
	static EarthFactory* getInstance();
	~EarthFactory(void);
	EarthSensor CreateEarthSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
};


