#include <bits/stdc++.h>
#include<string>
#include<queue>
#include "Passenger.h"
#include "TicketBooker.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void BookTicket(Passenger p){
	TicketBooker t;
	if(t.aWL==0){
		cout<<"All tickets are booked"<<endl;
		return;	
	}
	if((p.berthPref =="L" && t.aLB>0)||(p.berthPref=="M" && t.aMB>0)||(p.berthPref=="U" && t.aUB>0)){
		if(p.berthPref=="L"){
			cout<<"Preferred Berth Available"<<endl;
			t.bookticket(p,"L");
			t.aLB--;
		}
		else if(p.berthPref=="M"){
			cout<<"Preferred Berth Available"<<endl;
			t.bookticket(p,"M");
			t.aMB--;	
		}
		else if(p.berthPref=="U"){
			cout<<"Preferred Berth Available"<<endl;
			t.bookticket(p,"U");
			t.aUB--;
		}
	}
		else if(t.aLB>0){
			cout<<"Lower Berth Given"<<endl;
			t.bookticket(p,"L");
			t.aLB--;
		}
		else if(t.aMB>0){
			cout<<"Middle Berth Given"<<endl;
			t.bookticket(p,"M");
			t.aMB--;
		}
		else if(t.aUB>0){
			cout<<"Upper Berth Given"<<endl;
			t.bookticket(p,"U");
			t.aUB--;
		}
		else if(t.aRAC>0){
			cout<<"RAC Given"<<endl;
			t.addtoRAC(p,"RAC");
			t.aRAC--;
		}
		else{
			cout<<"Moved to Waiting list..."<<endl;
			t.addtoWL(p,"WL");
			t.aWL--;
		}
}

void CancelTicket(int passengerid){
		TicketBooker t;
		for(int i=0; i<t.bookedTickets.size(); i++){
			if(t.bookedTickets[i].passengerId==passengerid){
				if(t.bookedTickets[i].alloted=="L"){
					t.aLB++;
				}
				else if(t.bookedTickets[i].alloted=="M"){
					t.aMB++;
				}
				else if(t.bookedTickets[i].alloted=="U"){
					t.aUB++;
				}
				else if(t.bookedTickets[i].alloted=="RAC"){
					t.aRAC++;
				}
				else if(t.bookedTickets[i].alloted=="WL"){
					t.aWL++;
				}
				Passenger p = t.bookedTickets[i];
				t.bookedTickets.erase(t.bookedTickets.begin()+i);
				if(!t.RACList.empty()>0){
					t.bookticket(t.RACList.front(),p.alloted);
					if(p.alloted=="L"){
						t.aLB--;
					}
					else if(p.alloted=="M"){
						t.aMB--;
					}
					else{
						t.aUB--;
					}
					t.RACList.pop();
					t.aRAC++;
				}
				cout<<"Ticket Cancelled"<<endl;
				return;
			}	
		}
		cout<<"Passenger ID Not Found !!"<<endl;
}

void BookedTickets(){
	TicketBooker t;
	
	if(t.bookedTickets.size()==0){
		cout<<"No bookings"<<endl;
	}
	cout<<"Confirmed Passengers : "<<endl;;
	for(int i=0; i<t.bookedTickets.size(); i++){
		cout<<"--------------------------------------------------"<<endl;
		cout<<"Passenger Id   : "<<t.bookedTickets[i].passengerId<<endl;
		cout<<"Passenger Name : "<<t.bookedTickets[i].name<<endl;
		cout<<"Passenger Age  : "<<t.bookedTickets[i].age<<endl;
		cout<<"Alloted        : "<<t.bookedTickets[i].number<<t.bookedTickets[i].alloted<<endl;
		cout<<"--------------------------------------------------"<<endl;
	}
	
	if(!t.RACList.empty()){
		cout<<"RAC Passengers : "<<endl;
		queue<Passenger> copy = t.RACList;
		while(!copy.empty()){
			cout<<"--------------------------------------------------"<<endl;
			cout<<"Passenger Id   : "<<copy.front().passengerId<<endl;
			cout<<"Passenger Name : "<<copy.front().name<<endl;
			cout<<"Passenger Age  : "<<copy.front().age<<endl;
			cout<<"Alloted        : "<<copy.front().number<<copy.front().alloted<<endl;
			cout<<"--------------------------------------------------"<<endl;
			copy.pop();
		}
	}
	
		if(!t.WaitingList.empty()){
		cout<<"Waiting List Passengers : "<<endl;
		queue<Passenger> copy = t.WaitingList;
		while(!copy.empty()){
			cout<<"--------------------------------------------------"<<endl;
			cout<<"Passenger Id   : "<<copy.front().passengerId<<endl;
			cout<<"Passenger Name : "<<copy.front().name<<endl;
			cout<<"Passenger Age  : "<<copy.front().age<<endl;
			cout<<"Alloted        : "<<copy.front().number<<copy.front().alloted<<endl;
			cout<<"--------------------------------------------------"<<endl;
			copy.pop();
		}
	}
}

void AvailableTickets(){
	TicketBooker t;
	cout<<"Lower Berth : "<<t.aLB<<endl;
	cout<<"Middle Berth : "<<t.aMB<<endl;
	cout<<"Upper Berth : "<<t.aUB<<endl;
	cout<<"RAC : "<<t.aRAC<<endl;
	cout<<"Waiting List : "<<t.aWL<<endl;
}

int main(int argc, char** argv) {
	
	int n,val=1;

	while(val){
		cout<<"1.Book ticket\n2.Cancel ticket\n3.Available tickets\n4.Booked tickets\n5.Exit"<<endl;
		cin>>n;
		switch(n){
			case 1:{
				string name,berthPref;
				int age;
				cout<<"Enter your name : ";
				cin>>name;
				cout<<"Enter your age : ";
				cin>>age;				
				cout<<"Enter your Berth Preference (L,M,U) : ";
				cin>>berthPref;
				Passenger p(name,age,berthPref);
				BookTicket(p);
				break;
			}
			case 2:{
				int passengerid;
				cout<<"Enter Passenger Id : ";
				cin>>passengerid;
				CancelTicket(passengerid);
				break;
			}
			case 3:{
				AvailableTickets();
				break;
			}
			case 4:{
				BookedTickets();
				break;
			}
			case 5:{
				val=0;
				break;
			}
			default:
				cout<<"Invalid Input"<<endl;;
				
		}	
	}
	return 0;
}
