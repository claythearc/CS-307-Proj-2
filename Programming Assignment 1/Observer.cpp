			/*******************************************************************
			*   Source Code Observer.cpp
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/

#include "stdafx.h"
#include "Observer.h"
#include <iostream>
#include <string>
#include <algorithm>

///Default constructor and destructor
Observer::Observer(void)
{
}


Observer::~Observer(void)
{
}


//adds display names to the list of subscribed displays

void Observer::addName(string name) {
	this->names.push_back(name);
	this->subscribed.push_back(name);
}

//adds full Displays to the list of subscribed Displays
void Observer::debug() {
	std::string rmflag;
	std::string in;
	cout << "Which Displays would you like to subscribe to?  \n";
	cout << "-1 to exit \n";
	for(int i = 0; i < this->DisVec.size(); i++) { //For every Display in the list of Display Vectors
		std::cout << i << " " << this->DisVec[i].getName() << "\n"; //print it out
	}

	//Set flags for removing or adding displays
	cout << "Would you like to (0) Remove Display or (1) Subscribe? ";
	cin >> rmflag;
	cout << "Enter Choice: ";
	cin >> in;
	//Check exit condition
	while(in != "-1") {
		if(rmflag == "1") { //Adding displays to subscribe.
		this->DisSubVec.push_back(this->DisVec[ std::stoi(in) ]); //push it
		}
		//removing
		if(rmflag == "0") {
			for(int i = 0; i < DisSubVec.size(); i++) {
				if( DisSubVec[i] == this->DisVec[ std::stoi(in) ]){ //overloaded == between two Displays
					DisSubVec.erase(DisSubVec.begin() + i);
				}
			}
		}
		cout << "Would you like to (0) Remove Display or (1) Subscribe? ";
		cin >> rmflag;
		cout << " Enter another selection: ";
		cin >> in;
	}
}

//Are they subscribed to a display witht he passed string?
bool Observer::isSubscribed(string name) {
	bool sub = false;
	for(int i = 0; i < this->subscribed.size(); i++) {
		if(name == subscribed[i]) {
			sub = true;
		}
	}
	return sub;
}

//Add ids of sensors to the subscribed sensor list
void Observer::addid(int id) {
	this->intlist.push_back(id);
	this->subscribedint.push_back(id);
}

//is the user subscribed to a sensor?
bool Observer::isSubscribed(int id) {
	bool sub = false;
	for(int i = 0; i < this->subscribedint.size(); i++) {
		if(id == this->subscribedint[i]) {
			sub = true;
		}
	}
	return sub;
}

//Command that manages subscribing and removing sensors
void Observer::Subscribe() {
	std::string in;
	std::string rmflag; //input flags
	cout << "Would you like to (1) Subscribe or (0) Remove Sensors from your view? \n";
	cin >> rmflag;
	cout << "Input the corresponding number to subscribe to a specific sensor \n";
	cout << "-1 to exit \n";
	//loop and list the sensor IDs
	for(int i = 0; i < this->intlist.size(); i++) {
		cout << i << " " << this->intlist[i] << "\n";
	}

	cin >> in;
	while(in != "-1") { //check exit condition
		if(rmflag == "1") { //removing or adding sensors to subscription?
		this->subscribedint.push_back(this->intlist[ std::stoi(in) ]);
		}
		if(rmflag == "0") {
			//neat erase trick to erase by value instead of iterating over the entire Vector
			this->subscribedint.erase(std::remove(this->subscribedint.begin(), this->subscribedint.end(), this->intlist[ std::stoi(in) ]), this->subscribedint.end()); 
		}
		cout << "Would you like to (1) Subscribe or (0) Remove Sensors from your view? \n";
		cin >> rmflag;
		cout << "Input a sensor selection or -1 to exit: ";
		cin >> in;
	}
}

//Manages which mode the user is in for subscribing.
void Observer::ManageSub() {
	std::string in;
	cout << "Would you like to manage Subscribed (1) Displays or (2) Sensors? ";
	cin >> in;
	if(in == "1") {
		debug();
	}
	else if(in == "2") {
		Subscribe();
	}
}

//Add a display to the list of subscribed displays
void Observer::AddDis(Display d) {
	this->DisVec.push_back(d);
	this->DisSubVec.push_back(d);
}

//Is the user subscribed to a display?
bool Observer::isSubscribed(Display d) {
	bool sub = false;
	for(int i = 0; i < DisSubVec.size(); i++) {
		if(DisSubVec[i] == d) {
			sub = true;
	}
	}
	return sub;
}