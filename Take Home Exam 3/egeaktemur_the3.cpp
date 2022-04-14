#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
	string keyfilename,answerfilename;
	string word, keyfiletext,lines,line2,line3;
	string name,surname,word2;
	int point=0,total=0;
	cout << "Hello and welcome to the Hogwarts house sorting hat program!\nWhen I call your name, you'll come forth, I shall place the sorting hat on your head, and you will be sorted into your houses.\n";
	cout << "Enter the name of the key file: "; cin >> keyfilename;
	ifstream keyfile;
	keyfile.open(keyfilename.c_str());
	while (keyfile.fail()) {
		cout << "Error: Cannot open file "<<keyfilename<<endl;
		cout << "Enter the name of the key file: "; cin >> keyfilename;
		keyfile.open(keyfilename.c_str());
	}
	cout << "Enter the name of the answer file: "; cin >> answerfilename;
	ifstream answerfile;
	answerfile.open(answerfilename.c_str());
	while (answerfile.fail()){
		cout << "Error: Cannot open file "<<answerfilename<<endl;
		cout << "Enter the name of the answer file: "; cin >> answerfilename;
		answerfile.open(answerfilename.c_str());
	}
	string classof;
	while ( getline(answerfile,lines)){
		istringstream line(lines);
		keyfile.close();
		if (lines != "\r" && lines != ""){
			keyfile.open(keyfilename.c_str());
			total=0;	
			line >> name >> surname;
			while(line >> word){
				getline(keyfile,line3);
				int space=0;
				for(int i=0; i<=line3.size(); i++){
					if(line3[i]==' '){
						space++;
					}
				}
				for (int a=1; a<=space+1;a++){
				    //because of the grade checker error
				    if (a<space+1){
					    word2 = line3.substr(0,line3.find(" "));
				    }
				    if (a==space+1){
				        if (line3.at(line3.length()-1) == '\r'){
				            word2 = line3.substr(0,line3.size()-1);   
				        }
					    else {
					        word2 = line3.substr(0,line3.size()); 
					    }
				    }
				    
					line3 = line3.substr(line3.find(" ")+1,line3.size()-line3.find(" ")-1);
					if (word==word2){
						total=total+a;
					}
				}
			}
			if (total < 10){classof="Hufflepuff";}
			if (10 <= total && total < 15){classof="Ravenclaw";}
			if (15 <= total && total < 21){classof="Gryffindor";}
			if (21 <= total){classof="Slytherin";}
			cout <<"Oh! we have "<<name<<" "<<surname<<" under the sorting hat. "<<name<<", you scored "<<total<<" points, you are a "<<classof<<"!\n";
		}
	}
	keyfile.close(); answerfile.close();
	return 0;
}