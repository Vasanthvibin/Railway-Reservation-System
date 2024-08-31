#ifndef TICKETBOOKER_H
#define TICKETBOOKER_H
#include "Passenger.h"
#include<queue>
#include <bits/stdc++.h>
using namespace std;

class TicketBooker
{
	public:
		static int aLB;
		static int aMB;
		static int aUB;
		static int aRAC;
		static int aWL;
		
		static vector<Passenger> bookedTickets;
		static queue<Passenger> RACList;
		static queue<Passenger> WaitingList;
		
		void bookticket(Passenger p,string berth);
		void addtoRAC(Passenger p, string berth);
		void addtoWL(Passenger p, string berth);
	protected:
};

#endif
