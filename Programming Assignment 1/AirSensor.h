			/*******************************************************************
			*   Source Code AirSensor.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#pragma once
#include "Sensor.h"
class AirSensor :
	public Sensor
{
private:
	    string units;
    vector<double> value;
    int time;
    int id;
    string name;
    string material;
    double minValue;
    double maxValue;
	vector<Display> output;
public:
	AirSensor(int time, int id, double minValue, double maxValue,char* name, char* material, char* units);
	~AirSensor(void);
	AirSensor();
	vector<double> getSensorData();
    string getSensorUnits();
    double refresh();
    int getID();
    void print();
    bool setDisplay(Display d);
	int getLatestData();
	Message sendData();
	void printDisplay();
};

