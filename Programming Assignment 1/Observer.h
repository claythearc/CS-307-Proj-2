			/*******************************************************************
			*   Source Code Observer.h
			*   Programming Assignment 2 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#pragma once
#include <vector>
#include "Display.h"
class Observer
{
private:
	std::vector<std::string> names;
	std::vector<std::string> subscribed;
	std::vector<int> subscribedint;
	std::vector<int> intlist;
	std::vector<Display> DisVec;
	std::vector<Display> DisSubVec;

public:
	Observer(void);
	~Observer(void);
	void addName(string name);
	void debug();
	bool isSubscribed(string name);
	void addid(int id);
	bool isSubscribed(int id);
	void Subscribe();
	void ManageSub();
	void AddDis(Display d);
	bool isSubscribed(Display d);
};

