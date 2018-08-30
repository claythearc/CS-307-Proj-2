			/*******************************************************************
			*   Source Code Simulation.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include <iostream>
#include "stdafx.h"
#include "EnviroSimDataParser.h"
#include "Sensor.h"
#include <vector>
#include "SensorMount.h"
#include "Display.h"
#include <stdlib.h>
#include <Windows.h>
#include "Simulation.h"
#include <conio.h>
#include <stdio.h>

    using namespace std;

void Simulation::InitializeSimulation() {
	//Call the file parser
	char* filename = "SensorData2.xml";
	this->fparser = EnviroSimDataParser::getInstance();
	fparser->initDataParser(filename);
	//Create a bunch of temporary pointers
    char* type = new char;
    char *material = new char;
    int* ID = new int;
    char* units = new char;
    double* minVal = new double;
    double* maxVal = new double;
    bool read = true;

	
    char* displaytype = new char;
    int* displayid = new int;
    int* displayidcount = new int;
	this->SensorList = SensorMount();
	this->SnrFactory = SensorFactory::SensorFactory();
	this->SnrFactory.initialize();
	this->DispFactory = DisplayFactory::getInstance();

	//Read the file, pass the sensors to Sensor List

	int* earth = new int;
	int* water = new int;
	int* air = new int;
	this->fparser->getSensorCounts(earth, water, air);
	for(int i = 0; i < *earth; i++) {
		type = "Earth";
		read = this->fparser->getSensorData(type, material, ID, units, minVal, maxVal);
		SensorList.addSensor( SnrFactory.CreateSensor(5, *ID, *minVal, *maxVal, type, material, units) );
	}

	for(int i =0; i < *water; i++) {
		type = "Water";
		read = this->fparser->getSensorData(type, material, ID, units, minVal, maxVal);
		SensorList.addSensor( SnrFactory.CreateSensor(5, *ID, *minVal, *maxVal, type, material, units) );
	}

	for(int i =0; i < *water; i++) {
		type = "Air";
		read = this->fparser->getSensorData(type, material, ID, units, minVal, maxVal);
		SensorList.addSensor( SnrFactory.CreateSensor(5, *ID, *minVal, *maxVal, type, material, units) );
	}

	//Pass the Displays to the Sensor Mount
    while(this->fparser->getDisplayData(displaytype, displayid, displayidcount)) {
		SensorList.addDisplay(this->DispFactory->CreateDisplay(displayid, *displayidcount, displaytype));
        for(int i = 0; i < *displayidcount; i++) {
        }
    }
	//Attach them all
	this->SensorList.attachDisplays();
	this->SensorList.SendDisplays();
	this->SensorList.SendSensors();

}

void Simulation::RunSimulation() {
	int hit;     // key hit flag
     char ch;     // character key which was hit
	while(true) {
	hit = _kbhit(); //See if a key has been pressed
     if (hit)
     {
          ch = _getch();	// Get the key pressed
          // Now you can check ch to see what key was pressed.
		  this->SensorList.ObsSub();
     }
		//Clear screen so its pretty, display the data, make new data, sleep for 5 seconds
		SensorList.DisplayData();
		SensorList.GenerateData();
		Sleep(5000);
		system("cls");
		cout << "Welcome to the Simulation for Sensor Reading! You can press any key to subscribe or remove sensors from the list \n";
		cout << "To start with, all sensors and displays are subscribed \n";
	}
}

Simulation::Simulation() {

}