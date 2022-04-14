#include<iostream>
#include<string>
#include "strutils.h"
//Ege Aktemur

using namespace std;
string firstname,secondname;
string firstword,lowfirstword,secondword;
string decision = "", guess, guess2, choice;
string l, guessedbefore,letter;
int len,error = -1;
bool endgame = false;

bool errormade( int & error){
	endgame = false;
	if ( error == 0 ) { cout << "You have no free guess left."<<endl;
	}
	if ( error == 1 ) { cout << "You have lost a leg!"<<endl;
	}
	if ( error == 2 ) { cout << "You have lost a leg!"<<endl;
	}
	if ( error == 3 ) { cout << "You have lost an arm!"<<endl;
	}
	if ( error == 4 ) { cout << "You have lost an arm!"<<endl;
	}
	if ( error == 5 ) { 
		cout << "You have lost a head";
		cout <<"! GAME OVER!"<<endl<<secondname<<" lost the game :(";
		endgame = true;
	}
	return endgame;
}

bool isalpha(string word) {
	len = word.length();
	for (int i = 0; i< len; i++){
		l = word.substr(i,1);
		if( l != "a" && l != "b" && l != "c" && l != "d" && l != "e" && l != "f" && l != "g" && l != "h" && l != "i" && l != "j" && l != "k" && l != "l" && l != "m" && 
			l != "n" && l != "o" && l != "p" && l != "q" && l != "r" && l != "s" && l != "t" && l != "u" && l != "v" && l != "w" && l != "x" && l != "y" && l != "z"){
				return false;
		}
	}
	return true;
}

string letterguess (string lowfirstword, string guess, string letter){
	string newword;
	len = lowfirstword.length();
	newword = guess;
	for (int i = 0; i< len; i++){
		l = lowfirstword.substr(i,1);
		if (l == letter){
			int place = lowfirstword.find(letter,i);
			newword = newword.substr (0, place) + letter + newword.substr (1 + place);
		}
	}
	return newword;
}

bool guessacceptable (string letter, string guessedbefore){
	if (guessedbefore.find(letter) != string::npos){
		cout<<"Guess entered before! Try again."<<endl;
		return false;
	}
	if (letter.length()>1 || isalpha(LowerString(letter)) == false){
		cout <<"Invalid entry! Try again."<<endl;
		return false;
	}
	return true;
}

bool wordguess (string lowfirstword){
	string newword;
	cout<< "Your guess: "; cin >> newword;
	if (LowerString(newword) == lowfirstword){
		return true;
	}
	else{
		if (isalpha(newword) == false){
			cout <<"Invalid entry! Try again."<<endl;
		}
		else{
			error = error+1;
			endgame = errormade(error);
		}
		return false;
	}
}

string minusword ( string word){
	len = word.length();
	string newword;
	for (int i = 0; i< len; i++){
		newword = newword + "-";
	}
	return newword;
}

bool acceptable(string choice) {
	if(choice == "1" || choice == "2"){
		return true;
	}
	else{return false;}
}
int main (){
	cout <<"Welcome to the HANGMAN GAME"<<endl<<"---------------------------"<<endl;
	cout <<"Player one, please enter your name: ";cin >> firstname;
	cout <<"Player two, please enter your name: ";cin >> secondname;
	cout <<"OK "<<firstname<<" and "<<secondname<<". Let's start the game!"<<endl;
	cout <<firstname<<", please input the word you want "<<secondname<<" to guess: ";cin >> firstword;
	len = firstword.length();
	lowfirstword = LowerString(firstword);
	while (isalpha(lowfirstword) == false){
		cout <<"Invalid word! Try again."<<endl;
		cout <<firstname<<", please input the word you want "<<secondname<<" to guess: ";cin >> firstword;
		lowfirstword = LowerString(firstword);
	}
	guess = minusword(lowfirstword);
	cout << secondname<<", you have 1 free guess, after that you will lose limbs!"<<endl;
	while (endgame == false) {
		cout << "The word is: "<<guess<<endl<<secondname<<", do you want to guess the word(1) or guess a letter(2)? ";cin >> choice;
		while (acceptable(choice) == false){ 
			cout << "Invalid option!"<<endl<<"The word is: "<<guess<<endl<<secondname<<", do you want to guess the word(1) or guess a letter(2)? ";cin >> choice;
		}
		if (choice == "1"){
			if (wordguess(lowfirstword) == true){
				cout << "The word is: "<<lowfirstword<<endl;
				cout<< "Congratulations "<<secondname<<", you won!"<<endl<<secondname<<" won the game!";
				endgame = true;}
		}
		if (choice == "2"){
			cout<< "Your guess: "; cin >> letter;
			letter = LowerString(letter);
			if (guessacceptable(letter,guessedbefore) == true) {
				guessedbefore = guessedbefore + letter;
				guess2 = letterguess(lowfirstword,guess,letter);
				if (guess == guess2){
					error = error +1;
					endgame = errormade(error);
				}
				else{ 
					guess = guess2;
				}
			}
			if (guess ==lowfirstword){endgame=true;
				cout << "The word is: "<<lowfirstword<<endl;
				cout<< "Congratulations "<<secondname<<", you won!"<<endl<<secondname<<" won the game!";}
		}
	}
	return 0;
}