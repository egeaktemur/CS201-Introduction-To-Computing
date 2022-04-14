#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "date.h"
#include "Reservation.h"
#include <vector>
using namespace std;

int main(){
	string filename;
	cout << "Enter filename for reservation database: "; cin >> filename;
	ifstream file;ifstream boatsfile;ifstream sailorsfile;
	boatsfile.open("Boats.txt");sailorsfile.open("Sailors.txt");file.open(filename.c_str());
	if (file.fail() || boatsfile.fail() || sailorsfile.fail()) {
		cout << "Cannot open the files. Exiting..."<<endl<<endl;
		return 0;
	}
	string line,lines;int id;string name;double rank;double age;vector<Sailor> sailors;string color;vector<Boat> boats;;
	getline(sailorsfile,lines);
	while (getline(sailorsfile,lines)){
		istringstream line(lines);
		string word;
		for (int i=1; i < 5; i++){
			line >> word;
			if (i==1){id=stoi(word);} if (i==2){name=word;} if (i==3){rank=stod(word);} if (i==4){age=stod(word);}
		}
		Sailor s(id,name,rank,age);
		sailors.push_back(s);
	}
	getline(boatsfile,lines);
	while (getline(boatsfile,lines)){
		istringstream line(lines);
		string word;
		for (int i=1; i < 5; i++){
			line >> word;
			if (i==1){id=stoi(word);} if (i==2){name=word;} if (i==3){color=(word);}
		}
		Boat b1(id,name,color);
		boats.push_back(b1);
	}
	int BID;string date;int day,month,year;
	int sid;
	string operation;
	Sailor s;Boat b;Date d;Date d3;
	Sailor s2(0,"",0,0);
	Boat b2(0,"","");
	bool twodates=false;
	Reservations r;
	Reservation print;
	while (getline(file,lines)){
		istringstream line(lines);string word;
		for (int i=1; i < 5; i++){
			line >> word;
			if(i==1){
				operation=word;
			}
			if(i==2){
				sid=stoi(word);
				if (sid==0){s=s2;}
				if (sid!=0){
					Sailor s3(sid,"",0,0);
					s=s3;
					for (unsigned int i=0; i < sailors.size(); i++){
						if (sailors[i].Getid() == sid){		
							s=sailors[i];
						}
					}
				}
			}
			if(i==3){
				BID=stoi(word);
				if (BID==0){b=b2;}
				if (BID!=0){
					Boat b3(BID,"","");
					b=b3;
					for (unsigned int i=0; i < boats.size(); i++){
						if (boats[i].Getid() == BID){
							b=boats[i];
						}
					}
				}
			}
			if(i==4){
				date=word;	
				year=stoi(date.substr(0,4));
				month=stoi(date.substr(5,2));
				day=stoi(date.substr(8,2));
				Date d2(month,day,year);
				d=d2;
				if (s.Getid()==0 && b.Getid()==0){
					line >> word;
					date=word;	
					year=stoi(date.substr(0,4));
					month=stoi(date.substr(5,2));
					day=stoi(date.substr(8,2));
					Date d4(month,day,year);
					d3=d4;
					twodates=true;
				}
			}	
		}
		if (operation =="A"){
			r.AddReservation(s,b,d);
		}
		if (operation =="D"){
			r.DeleteReservation(s,b,d);
		}
		vector<Reservation> Reservationsfound;
		if (operation =="F" && twodates==true){
			Reservationsfound = r.FindReservations(d,d3);
			cout <<"Find Results:" <<endl;
			if (Reservationsfound.size()==0){cout <<"Error: No matching reservation found between dates "<<d.Year();	
				if (d.Month()<10){cout<<"-0"<<d.Month(); }else{cout<<"-"<<d.Month();}
				if (d.Day()<10){cout<<"-0"<<d.Day();} else{cout<<"-"<<d.Day();}
				cout <<" & "<<d3.Year();	
				if (d3.Month()<10){cout<<"-0"<<d3.Month(); }else{cout<<"-"<<d3.Month();}
				if (d3.Day()<10){cout<<"-0"<<d3.Day()<<endl;} else{cout<<"-"<<d3.Day()<<endl;}
			}
			else{
				for (unsigned int i=0; i < Reservationsfound.size(); i++){
					print.Print(Reservationsfound[i]);
				}
				twodates=false;
			}
			cout <<endl;
		}
		if (operation =="F" && s.Getid()==0 && b.Getid()!=0){
			Reservationsfound = r.FindReservations(b,d);
			cout <<"Find Results:" <<endl;
			if (Reservationsfound.size()==0){cout <<"Error: No matching reservation found for boat id "<<b.Getid()<<" on "<<d.Year();	
				if (d.Month()<10){cout<<"-0"<<d.Month(); }else{cout<<"-"<<d.Month();}
				if (d.Day()<10){cout<<"-0"<<d.Day()<<endl;} else{cout<<"-"<<d.Day()<<endl;}
			}
			else{
				for (unsigned int i=0; i < Reservationsfound.size(); i++){
					print.Print(Reservationsfound[i]);
				}
			}
			cout <<endl;
		}
		if (operation =="F" && b.Getid()==0 && s.Getid()!=0){
			Reservationsfound = r.FindReservations(s,d);
			cout <<"Find Results:" <<endl;
			if (Reservationsfound.size()==0){cout <<"Error: No matching reservation found for sailor id "<<s.Getid()<<" on "<<d.Year();	
				if (d.Month()<10){cout<<"-0"<<d.Month(); }else{cout<<"-"<<d.Month();}
				if (d.Day()<10){cout<<"-0"<<d.Day()<<endl;} else{cout<<"-"<<d.Day()<<endl;}
			}
			else{
				for (unsigned int i=0; i < Reservationsfound.size(); i++){
					print.Print(Reservationsfound[i]);
				}
			}
			cout <<endl;
		}	
	}
	return 0;
}