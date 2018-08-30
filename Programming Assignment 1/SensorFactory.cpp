			/*******************************************************************
			*   Source Code SensorFactory.cpp
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "SensorFactory.h"
#include "EarthSensor.h"
#include "WaterSensor.h"
#include "AirSensor.h"
#include "EarthFactory.h"
#include "AirFactory.h"
#include "WaterFactory.h"



//constructor
SensorFactory::SensorFactory(void)
{

}

//Initialize function that creates one of each of the singletons. this is important because otherwise it made my computer sad
void SensorFactory::initialize() {
	this->m_airfactory =  AirFactory::getInstance();
	this->m_earthfactory =  EarthFactory::getInstance();
	this->m_waterfactory =  WaterFactory::getInstance();
}

SensorFactory::~SensorFactory(void)
{
}

//creates an air, water, or earth sensor by calling the constructor.

AirSensor SensorFactory::CreateAirSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	return this->m_airfactory->CreateAirSensor( time, id,  minValue,  maxValue, name,  material, units);
}

WaterSensor SensorFactory::CreateWaterSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	return this->m_waterfactory->CreateWaterSensor( time, id,  minValue,  maxValue, name,  material, units);
}

EarthSensor SensorFactory::CreateEarthSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	return this->m_earthfactory->CreateEarthSensor( time, id,  minValue,  maxValue, name,  material, units);
}

//"Smart" sensor creation, checks the type and sees if it's a water earth or air sensor, then calls that specific method
Sensor SensorFactory::CreateSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units) {
	if (strcmp(name, "Air") == 0) {
		return this->m_airfactory->CreateAirSensor( time, id,  minValue,  maxValue, name,  material, units);
	}
	else if (strcmp(name, "Water")  == 0 ) {
		return this->m_waterfactory->CreateWaterSensor( time, id,  minValue,  maxValue, name,  material, units);
	}
	else if (strcmp(name, "Earth")  == 0 ) {
		return  this->m_earthfactory->CreateEarthSensor( time, id,  minValue,  maxValue, name,  material, units);
	}
	
}




