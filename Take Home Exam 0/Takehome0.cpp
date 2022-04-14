#include <iostream>
#include <string>
using namespace std;
//Ege Aktemur
int main() {
	string name_user;
	double note1, note2 , takehome, quiz, takehomeavr, quizavr, examavr, ratio ,ratio2, coursegrade;
	double thenote1,thenote2,thenote3,thenote4,thenote5,quiznote1,quiznote2,quiznote3,quiznote4;
	int thenote12,thenote22,thenote32,thenote42,thenote52;
	int quiznote12,quiznote22,quiznote32,quiznote42;

	cout << "The purpose of this program is to calculate your CS201 grade." <<endl<< "What is your name? ";cin >> name_user;
	cout << "Hello "<< name_user<<", what are your midterm and final exam grades? ";cin >> note1 >> note2;
	if (note1 == -100 || note2 == -100){
		cout << name_user << ", one of your midterm or final exam grade is -100, you will fail the course!"<<endl;
		return 0;}
	if (note1 == -1){
		cout << name_user << ", you did not enter the midterm exam, you will fail the course!"<<endl;
		return 0;}
	if (note2 == -1){
		cout << name_user << ", you did not enter the final exam, you will fail the course!"<<endl;
		return 0;}
	if ((note1+note2)/2 <30){
		cout << name_user << ", your weighted exam average is less than 30, you will fail the course!"<<endl;
		return 0;}
	cout << "What are the grades of your 5 take-home exams? ";
	cin >> thenote1 >> thenote2 >> thenote3 >> thenote4 >>thenote5;
	thenote12 = thenote22 = thenote32 = thenote42 = thenote52 = 0;
	if (thenote1 == -100){thenote12 = 1;}
	if (thenote2 == -100){thenote22 = 1;}
	if (thenote3 == -100){thenote32 = 1;}
	if (thenote4 == -100){thenote42 = 1;}
	if (thenote5 == -100){thenote52 = 1;}
	if (thenote12 + thenote22 + thenote32 + thenote42 + thenote52 >= 2){
		cout << name_user <<", at least two of your THE grades are -100, you will fail the course!"<<endl;
		return 0;}
	cout << "What are the grades of your 4 quizzes? ";
	cin >> quiznote1 >> quiznote2 >> quiznote3 >> quiznote4;
	quiznote12 = quiznote22 = quiznote32 = quiznote42 = 0;
	if (quiznote1 == -100){quiznote12 = 1;}
	if (quiznote2 == -100){quiznote22 = 1;}
	if (quiznote3 == -100){quiznote32 = 1;}
	if (quiznote4 == -100){quiznote42 = 1;}
	if ( quiznote12 + quiznote22 +quiznote32 +quiznote42 >=1 && thenote12 + thenote22 + thenote32 + thenote42 + thenote52 >=1){
		cout << name_user << ", one of your THE and one of your quiz grades is -100, you will fail the course!"<<endl;		
		return 0;}
	if ( quiznote12 + quiznote22 +quiznote32 +quiznote42 >1){
		cout << name_user << ", at least two of your quiz grades are -100, you will fail the course!"<<endl;		
		return 0;}
	quizavr = (quiznote1 + quiznote2+ quiznote3 + quiznote4)/4 ;
	takehomeavr = (thenote1*3 + thenote2*4 +thenote3*4+ thenote4*4+ thenote5*5)/20;
	examavr = (note1 + note2)/2; ratio = takehomeavr/examavr; ratio2 = quizavr/examavr; 
	if (ratio <=2 && ratio>0){ takehome = takehomeavr;} if (ratio <3 && ratio>2){ takehome = takehomeavr * (3-ratio);} if (ratio >3){ takehome = 0;}
	if (ratio2 <=2 && ratio2>0){ quiz = quizavr;} if (ratio2 <3 && ratio2>2){ quiz = quizavr * (3-ratio2);} if (ratio2 >3){ quiz = 0;}
	cout << name_user<<", your weighted exam average is: "<<examavr<<endl;
	cout << name_user<<", your THE average is: "<<takehomeavr<<" and you will get "<<takehome<<" of it."<<endl;
	cout << name_user<<", your quiz average is: "<<quizavr<<" and you will get "<<quiz<<" of it."<<endl;
	coursegrade = (quiz * 0.2) + (takehome * 0.2) + (note1 * 0.3) + (note2 * 0.3);
	cout << name_user << ", your grade for CS201 is: "<<coursegrade<<endl;
	return 0;
}
