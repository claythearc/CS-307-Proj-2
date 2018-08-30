			/*******************************************************************
			*   Source Code Simulation.h
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#ifndef UNTITLED_SIMULATION_H
#define UNTITLED_SIMULATION_H

#include "SensorMount.h"
#include "EnviroSimDataParser.h"
#include "SensorFactory.h"
#include "DisplayFactory.h"

class Simulation {
private:
	SensorMount SensorList;
	SensorFactory SnrFactory;
	DisplayFactory* DispFactory;
	EnviroSimDataParser* fparser;
public:
	Simulation();
	void InitializeSimulation();
	void RunSimulation();
};
#endif