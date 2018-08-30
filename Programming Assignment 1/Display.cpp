			/*******************************************************************
			*   Source Code Display.cpp
			*   Programming Assignment 1 and Sensor Readings
			*   Author: Clayton Turner
			*   Date: July 2018
			*   
			*   This program is entirely my own work
			*******************************************************************/
#include "stdafx.h"
#include "Display.h"
#include <iostream>
#include <string>

using namespace std;

//Debug function to make sure each display was reachable.
void Display::WriteData(char *message) {
    cout << message;
}

//Constructor to store the ids it wants to read in a vector, the size of the vector, and the name of the meter.
Display::Display(int* ids, int size, char* name) {
    for (int i = 0; i < size; i++) {
		this->idlist.push_back(ids[i]);
	}
	this->size = size;
	this->name = name;
}

//Returns the whole vector of IDs
std::vector<int> Display::getIDList() {
    return this->idlist;
}

//Returns size of vector.
int Display::getSize(){
    return this->size;
}

//Sets the size of the size variable
void Display::setSize(int size) {
    this->size = size;
}

//Gets the name string
string Display::getName(){
	return this->name;
}

//Debug function to print all the IDs it holds
void Display::printID() {
	for(int i = 0; i < idlist.size(); i++) {
		cout << "ID# : " << i << " " << idlist[i] << "\n";
	}
}

//Push a message onto the vector of messages it has
void Display::StoreMessages(string message) {
	this->messages.push_back(message);
}

//Once the program tells them to output, it outputs all the messages and then clears the vector
void Display::WriteMessages() {
	if(!this->messages.empty()) {
	cout << "Display " << name << "\n";
	}
	for(int i = 0; i < this->messages.size(); i++) {
		cout << this->messages[i] << "\n";
	}
	this->messages.clear();
}

//Overloaded equality sign, it compares both the name string and the vector of id's they are holding
bool Display::operator==(Display& rhs) {
	if( this->name == rhs.getName()) {
		if(this->idlist == rhs.getIDList()) {
			return true;
		}
	}
	return false;
}

//returns ID of a specific vector index
int Display::getIDList(int x) {
	return this->idlist[x];
}
