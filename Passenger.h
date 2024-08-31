#ifndef PASSENGER_H
#define PASSENGER_H
#include <bits/stdc++.h>
using namespace std;

class Passenger
{
	public:
		static int id;
		string name;
		int age;
		int passengerId;
		string berthPref;
		string alloted;
		int number;
		
		Passenger(string name,int age,string berthPref);
	protected:
};

#endif
