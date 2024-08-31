#include "TicketBooker.h"
#include <bits/stdc++.h>
#include<queue>
using namespace std;

int TicketBooker :: aLB = 1;
int TicketBooker :: aMB = 1;
int TicketBooker :: aUB = 1;
int TicketBooker :: aRAC = 1;
int TicketBooker :: aWL = 1;

vector<Passenger> TicketBooker :: bookedTickets;
queue<Passenger> TicketBooker :: RACList;
queue<Passenger> TicketBooker :: WaitingList;

void TicketBooker :: bookticket(Passenger p,string berth){
	p.alloted = berth;
	p.number = 1;
	bookedTickets.push_back(p);
}

void TicketBooker :: addtoRAC(Passenger p,string berth){
	p.alloted = berth;
	p.number = 1;
	RACList.push(p);
}

void TicketBooker :: addtoWL(Passenger p,string berth){
	p.alloted = berth;
	p.number = 1;
	WaitingList.push(p);
}
