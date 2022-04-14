#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "date.h"
#include <vector>
using namespace std;

struct sailor{int id;string name;double rank;double age;};
struct boat {int bid;string bname;string color;};
struct prints{Date date;string name;double rank;double age;string bname;string color;};
void SelectSort(vector<Date> & a){// pre: a contains a.size() elements// post: elements of a are sorted in non-decreasing order
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
void SelectSortN(vector<string> & a){
    int j, k, minIndex, numElts = a.size();
	string temp;
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

int main(){
	string filename;
	cout << "Enter filename for reservation database: "; cin >> filename;
	ifstream file;ifstream boatsfile;ifstream sailorsfile;
	boatsfile.open("Boats.txt");sailorsfile.open("Sailors.txt");file.open(filename.c_str());
	if (file.fail() || boatsfile.fail() || sailorsfile.fail()) {
		cout << "Cannot open the files. Exiting..."<<endl;
		return 0;
	}
	string line,lines;int id;string name;double rank;double age;vector<sailor> sailors;string color;vector<boat> boats;;
	getline(sailorsfile,lines);
	while (getline(sailorsfile,lines)){
		istringstream line(lines);
		string word;
		for (int i=1; i < 5; i++){
			line >> word;
			if (i==1){id=stoi(word);} if (i==2){name=word;} if (i==3){rank=stod(word);} if (i==4){age=stod(word);}
		}
		struct sailor s;
		s.id=id;s.name=name;s.rank=rank;s.age=age;sailors.push_back(s);
	}
	getline(boatsfile,lines);
	while (getline(boatsfile,lines)){
		istringstream line(lines);
		string word;
		for (int i=1; i < 5; i++){
			line >> word;
			if (i==1){id=stoi(word);} if (i==2){name=word;} if (i==3){color=(word);}
		}
		struct boat b;
		b.bid=id;b.bname=name;b.color=color;boats.push_back(b);
	}
	int pid;string pname;double prank;double page;int BID;string date;int day,month,year;string info;vector<prints> infos;vector<Date> dates;prints print;string pcolor,pbname;
	getline(file,lines);
	while (getline(file,lines)){
		istringstream line(lines);string word;
		for (int i=1; i < 4; i++){
			line >> word;
			if(i==1){
				for(int i2=0; i2<sailors.size(); i2++){
					if (stoi(word)==sailors.at(i2).id){
						pid=sailors.at(i2).id;
						pname=sailors.at(i2).name;
						prank=sailors.at(i2).rank;
						page=sailors.at(i2).age;
					}
				}
			}
			if(i==2){
				BID=stoi(word);
				for(int i2=0; i2<boats.size(); i2++){
					if (BID==boats.at(i2).bid){
						print.bname=boats.at(i2).bname;
						print.color=boats.at(i2).color;
					}
				}
			}
			if(i==3){
				date=word;	
				year=stoi(date.substr(0,4));
				month=stoi(date.substr(5,2));
				day=stoi(date.substr(8,2));
				Date d(month,day,year);
				dates.push_back(d);
				print.date=d;
			}
		}
		print.name=pname;print.rank=prank;print.age=page;infos.push_back(print);
	}
	SelectSort(dates);
	vector<string> sailorsnames;
	for (int i=0; i < infos.size(); i++){
		sailorsnames.push_back(infos.at(i).name);
	}
	SelectSortN(sailorsnames);
	bool exist=false;
	vector<prints> infos2;
	for (int i=0; i < sailorsnames.size(); i++){
		exist=false;
		for (int i2=0; i2 < infos.size(); i2++){
			if (sailorsnames.at(i)==infos.at(i2).name && exist==false){
				infos2.push_back(infos.at(i2));
				infos.erase(infos.begin()+i2);
				exist=true;
			}
		}
	}
	infos=infos2;
	for (int i=0; i < dates.size(); i++){
		exist=false;
		for (int i2=0; i2 < infos.size(); i2++){
			if (dates.at(i)==infos.at(i2).date && exist==false ){
				cout << infos.at(i2).date.Year();
				if (infos.at(i2).date.Month()<10){cout<<"-0"<<infos.at(i2).date.Month(); }else{cout<<"-"<<infos.at(i2).date.Month();}
				if (infos.at(i2).date.Day()<10){cout<<"-0"<<infos.at(i2).date.Day();} else{cout<<"-"<<infos.at(i2).date.Day();}
				cout<< " -> " << infos.at(i2).name << "(" << infos.at(i2).age << "," << infos.at(i2).rank<<") has reserved " << infos.at(i2).bname<< "(" + infos.at(i2).color << ")" << endl;
				infos.erase(infos.begin()+i2);
				exist=true;
			}
		}
	}
	return 0;
}