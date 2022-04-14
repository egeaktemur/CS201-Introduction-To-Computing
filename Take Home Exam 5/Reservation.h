#include <iostream>
#include <vector>
#include <string>
#include "date.h"
using namespace std;

void SelectSort(vector<Date> & a){
	int j, k, minIndex, numElts = a.size();
	Date temp;
	for(k=0; k < numElts - 1; k++){
		minIndex = k;             // minimal element index
		for(j=k+1; j < numElts; j++)
			if (a[j] < a[minIndex])
				minIndex = j;     // new min, store index
		temp = a[k];         // swap min and k-th elements
		a[k] = a[minIndex];
		a[minIndex] = temp;
	}
}

class Boat{
	public:
		Boat(){
			id = 0;
			name = "Default";
			color = "Default";
		}
		Boat(int a,string b,string c);
		int Getid() const;
		string Getname() const;
		string Getcolor() const;
	private:
		int id;
		string name;  
		string color;
};
Boat::Boat(int a,string b,string c){
	id=a;
	name=b;
	color=c;
}
int Boat::Getid() const{return id;}
string Boat::Getname() const {return name;}
string Boat::Getcolor() const {return color;}

class Sailor{
	public:
		Sailor(){
			id = 0;
			name = "Jane Doe";
			age = 0;
			rank = 0;
		}
		Sailor(int a,string b,double c,double d);
		int Getid() const;
		string Getname() const;
		double Getage() const;
		double Getrank() const;

	private:
		int id;
		string name;
		double age;
		double rank;
};
Sailor::Sailor(int a,string b,double c,double d){
	id=a;
	name=b;
	age=c;
	rank=d;
}
int Sailor::Getid() const{return id;}
string Sailor::Getname() const{return name;}
double Sailor::Getage() const{return age;}
double Sailor::Getrank() const{return rank;}

class Reservation{
	public:
		Reservation(){
			Sailor s;
			sailor = s;
			Boat b;
			boat = b;
			Date d(1,1,1900);
			resDate = d;
		}
		Reservation(Sailor a,Boat b,Date c);
		Sailor Getsailor()const;
		Boat Getboat()const;
		Date Getdate()const;
		void Print(Reservation Reservation) const{
			cout << Reservation.Getdate()<<" -> "<<Reservation.Getsailor().Getname()<<"("
					<<Reservation.Getsailor().Getrank()<<","<<Reservation.Getsailor().Getage()<<") has reserved "
					<<Reservation.Getboat().Getname()<<"("<<Reservation.Getboat().Getcolor()<<")"<<endl;
		}

		// Add here the Print function

	private:
		Date resDate;
		Sailor sailor;
		Boat boat;
};
Reservation::Reservation(Sailor a,Boat b,Date c){
	sailor=a;
	boat=b;
	resDate=c;
}
Sailor Reservation::Getsailor()const{return sailor;}
Boat Reservation::Getboat()const{return boat;}
Date Reservation::Getdate()const{return resDate;}

bool operator == (Boat const& r1, Boat const& r2){
	return ((r1.Getcolor()==r2.Getcolor()) && (r1.Getid() == r2.Getid()) && (r1.Getname() ==r2.Getname()));
}
bool operator != (Boat const& r1, Boat const& r2){
	return !(r1 == r2);
}

bool operator == (Sailor const& r1, Sailor const& r2){
	return ((r1.Getrank()==r2.Getrank()) && (r1.Getid() == r2.Getid()) && (r1.Getname() ==r2.Getname()) && (r1.Getage() ==r2.Getage()));
}
bool operator != (Sailor const& r1, Sailor const& r2){
	return !(r1 == r2);
}

bool operator == (Reservation const& r1, Reservation const& r2){
	return ((r1.Getsailor()==r2.Getsailor()) && (r1.Getboat() == r2.Getboat()) && (r1.Getdate() == r2.Getdate()));
}
bool operator != (Reservation const& r1, Reservation const& r2){
	return !(r1 == r2);
}

class Reservations{
	public:
		// Fill this part with the member functions
		// 1. Add a Reservation
		void AddReservation (Sailor s,Boat b,Date d){
			Reservation reservation(s,b,d);
			reservations.push_back(reservation);
		}
		// 2. Delete a Reservation
		void DeleteReservation (Sailor s,Boat b,Date d){
			Reservation reservation(s,b,d);
			vector<Reservation> reservations2;
			if (s.Getid() == 0 && d.Absolute()==-364){
				for (unsigned int i=0; i < reservations.size(); i++){
					if (reservations[i].Getboat() != b){
						reservations2.push_back(reservations[i]);
					}
				}
				if (reservations2.size() == reservations.size()){
					cout<< "Error: Could not delete reservation for boat id "<<b.Getid()<<endl;
					cout <<endl;
				}
			}
			else if (b.Getid() == 0 && d.Absolute()==-364){
				for (unsigned int i=0; i < reservations.size(); i++){
					if (reservations[i].Getsailor().Getid() != s.Getid()){
						reservations2.push_back(reservations[i]);
					}
				}
				if (reservations2.size() == reservations.size()){
					cout<< "Error: Could not delete reservation for sailor id "<<s.Getid()<<endl;
					cout <<endl;
				}
			}
			else if (s.Getid() != 0 && b.Getid() != 0 && d.Absolute()!=-364){

				for (unsigned int i=0; i < reservations.size(); i++){
					if ((reservations[i].Getboat() != b) || (reservations[i].Getsailor() != s) || (reservations[i].Getdate() != d)){
						reservations2.push_back(reservations[i]);
					}
				}
				if (reservations2.size() == reservations.size()){
					cout<< "Error: Could not delete reservation \""<<s.Getid()<<" "<< b.Getid()<<" "<<d.Year();	
					if (d.Month()<10){cout<<"-0"<<d.Month(); }else{cout<<"-"<<d.Month();}
					if (d.Day()<10){cout<<"-0"<<d.Day()<<"\"";} else{cout<<"-"<<d.Day()<<"\"";}
					cout <<endl<<endl;
				}
			}
			
			reservations = reservations2;
		}
		// 3.1. Find a Reservation (sailor and boat ids are 0)
		vector<Reservation> FindReservations (Date d1,Date d2){
			vector<Reservation> reservationsf;
			vector<Reservation> reservationsf2;
			vector<Date> dates;
			for (unsigned int i=0; i < reservations.size(); i++){
				if (reservations[i].Getdate()>=d1 && reservations[i].Getdate()<=d2){
					reservationsf.push_back(reservations[i]);
					dates.push_back(reservations[i].Getdate());
				}
			}
			SelectSort(dates);
			for (unsigned int i=0; i < dates.size(); i++){
				for (unsigned int i2=0; i2 < reservationsf.size(); i2++){
					if (reservationsf[i2].Getdate() == dates[i]){
						reservationsf2.push_back(reservationsf[i2]);
					}
				}
			}
			return reservationsf2;
		}
		// 3.2. Find a Reservation (only sailor id is 0)
		vector<Reservation> FindReservations (Boat b,Date d1){
			vector<Reservation> reservationsf;
			vector<Reservation> reservationsf2;
			vector<Date> dates;
			for (unsigned int i=0; i < reservations.size(); i++){
				if (reservations[i].Getdate()==d1 && reservations[i].Getboat().Getid()==b.Getid()){
					reservationsf.push_back(reservations[i]);
					dates.push_back(reservations[i].Getdate());
				}
			}
			SelectSort(dates);
			for (unsigned int i=0; i < dates.size(); i++){
				for (unsigned int i2=0; i2 < reservationsf.size(); i2++){
					if (reservationsf[i2].Getdate()== dates[i]){
						reservationsf2.push_back(reservationsf[i2]);
					}
				}
			}
			return reservationsf2;
		}
		// 3.3. Find a Reservation (only boat id is 0)
		vector<Reservation> FindReservations (Sailor s,Date d1){
			vector<Reservation> reservationsf;
			vector<Reservation> reservationsf2;
			vector<Date> dates;
			for (unsigned int i=0; i < reservations.size(); i++){
				if (reservations[i].Getdate()==d1 && reservations[i].Getsailor().Getid()==s.Getid()){
					reservationsf.push_back(reservations[i]);
					dates.push_back(reservations[i].Getdate());
				}
			}
			SelectSort(dates);
			for (unsigned int i=0; i < dates.size(); i++){
				for (unsigned int i2=0; i2 < reservationsf.size(); i2++){
					if (reservationsf[i2].Getdate()== dates[i]){
						reservationsf2.push_back(reservationsf[i2]);
					}
				}
			}
			return reservationsf2;
		}
	private:
		vector<Reservation> reservations;	
};