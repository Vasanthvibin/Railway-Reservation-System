#include "Passenger.h"
#include <bits/stdc++.h>
using namespace std;

int Passenger :: id = 1;

Passenger :: Passenger(string name,int age, string berthPref){
	this->name = name;
	this->age = age;
	this->berthPref = berthPref;
	this->passengerId = id++;
	alloted = " ";
	number = -1;
}
