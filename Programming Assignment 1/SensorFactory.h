			/*******************************************************************
			*   Source Code SensorFactory.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#pragma once
#include "EarthSensor.h"
#include "WaterSensor.h"
#include "AirSensor.h"
#include "stdafx.h"
#include "Sensor.h"

class EarthFactory;
class WaterFactory;
class AirFactory;

class SensorFactory
{
private:
	EarthFactory* m_earthfactory;
	WaterFactory* m_waterfactory;
	AirFactory*   m_airfactory;
public:
	SensorFactory(void);
	~SensorFactory(void);
	EarthSensor CreateEarthSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
	WaterSensor CreateWaterSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
	AirSensor   CreateAirSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
	Sensor CreateSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
	void initialize();
};

