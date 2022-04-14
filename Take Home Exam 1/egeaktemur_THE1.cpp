#include<iostream>
#include<string>

//Ege Aktemur

using namespace std;
string user_name,exercise;
double weight, liftedweight , reps , minute ,goal, total,difference;
double repsLunge,minLunge,repsPushUp,minPushUp,repsPullUp,minPullUp,repsWeightLift,minWeightLift,liftedWeight;
double lungeCalorie, pushupCalorie, pullupCalorie ,weightliftCalorie;
bool error;
double MET,lungeMET,pushupMET,pullupMET,weightliftMET;

void getInput(string exercise, double & liftedweight , double & reps , double & minute){
	cout << exercise; 
	if (exercise == "Lunges: " || exercise == "Push Ups: " || exercise == "Pull Ups: "){cin >> minute >> reps;}
	if (exercise == "Weight Lifting: "){cin >> minute >> reps >> liftedweight;}
}

bool inputCheck(double weight, double reps , double minute, double liftedweight =1){	
	if (weight < 30) {cout << "Weight out of range!"<<endl; return false;}
	if (liftedweight > 35 || liftedweight <= 0 ) {cout << "Lifted weight out of range!"<<endl; return false;}
	if (reps > 50 || reps < 0 ) { cout << "Reps out of range!"<<endl; return false;}
	if (minute > 2000 || minute <0) {cout << "Minute out of range!"<<endl; return false;}
	return true;
}

void calculateMET(string exercise, double reps , double & MET){
	if (exercise == "Lunges: ") {
		if (reps<15) {MET = 3;}
		if (reps>=15 && reps<30) {MET = 6.5;}
		if (reps>=30) {MET = 10.5;}}
	if (exercise == "Push Ups: ") {
		if (reps<15) {MET = 4;}
		if (reps>=15) {MET = 7.5;}}
	if (exercise == "Pull Ups: ") {
		if (reps<25) {MET = 5;}
		if (reps>=25) {MET = 9;}}
}
void calculateWeightLiftMET(double reps, double liftedWeights, double & MET){
	if (liftedWeights<5) {
		if (reps<20) {MET = 3;}
		if (reps>=20 && reps<40) {MET = 5.5;}
		if (reps>=40) {MET = 10;}}
	if (liftedWeights>=5 || liftedWeights<15) {
		if (reps<20) {MET = 4;}
		if (reps>=20 && reps<40) {MET = 7.5;}
		if (reps>=40) {MET = 12;}}
	if (liftedWeights>=15) {
		if (reps<20) {MET = 5;}
		if (reps>=20 && reps<40) {MET = 9;}
		if (reps>=40) {MET = 13.5;}}
}
void displayResults(double difference, double total, double weight, double lungeMET, double pushupMET,
					double pullupMET, double weightliftMET, double lungeCalorie, double pushupCalorie, 
					double pullupCalorie , double weightliftCalorie) {
	cout << "From lunges, you burned "<< lungeCalorie<<" calories."<<endl;
	cout << "From push ups, you burned "<< pushupCalorie<<" calories."<<endl;
	cout << "From pull ups, you burned "<< pullupCalorie<<" calories."<<endl;
	cout << "From weight lifting, you burned "<< weightliftCalorie<<" calories."<<endl;
	cout << "You burned "<<(total)<<" calories."<<endl;
	if (difference==0){cout <<endl<<"Congratulations! You have reached your goal!"<<endl;}	
	if (difference>0){cout <<endl<<"You have surpassed your goal! You can eat something worth "<<difference<< " calories :)"<<endl;}
	if (difference<0){cout <<endl<<"You did not reach your goal by "<<-difference<< " calories."<<endl;
		cout << "You need to do lunges "<< -(200*difference)/(lungeMET*3.5*weight) << " minutes more to reach your goal or," << endl;
        cout << "You need to do push ups "<< -(200*difference)/(pushupMET*3.5*weight) << " minutes more to reach your goal or," << endl;
        cout << "You need to do pull ups "<< -(200*difference)/(pullupMET*3.5*weight) << " minutes more to reach your goal or," << endl;
        cout << "You need to do weight lifting "<< -(200*difference)/(weightliftMET*3.5*weight) << " minutes more to reach your goal." << endl;
	}
}
void computeResults(double weight, double goal, double repsLunge, double repsPushUp, double repsPullUp, 
					double repsWeightLift, double minLunge, double minPushUp, double minPullUp, 
					double minWeightLift, double liftedWeight){
	exercise = "Lunges: ";
	calculateMET(exercise,repsLunge,MET);
	lungeMET = MET;
	exercise = "Push Ups: ";
	calculateMET(exercise,repsPushUp,MET);
	pushupMET = MET;
	exercise = "Pull Ups: ";
	calculateMET(exercise,repsPullUp,MET);
	pullupMET = MET;
	calculateWeightLiftMET(reps,liftedweight,MET);weightliftMET = MET;
	lungeCalorie = minLunge*(lungeMET*3.5*weight)/200;
	pushupCalorie = minPushUp*(pushupMET*3.5*weight)/200;
	pullupCalorie = minPullUp*(pullupMET*3.5*weight)/200;
	weightliftCalorie = minWeightLift*(weightliftMET*3.5*weight)/200;
	total = lungeCalorie + pushupCalorie + pullupCalorie + weightliftCalorie;
	difference = total-goal;
	displayResults(difference, total, weight, lungeMET, pushupMET, pullupMET, weightliftMET, 
				   lungeCalorie, pushupCalorie, pullupCalorie, weightliftCalorie);
}

int main(){ 
	error= true;
	cout << "Please enter your name: ";cin >> user_name;
	cout << "Welcome "<<user_name<<", please enter your weight(kg): "; cin >> weight;
	cout << user_name<<", please enter minutes and repetitions in a week for the activities below."<<endl;

	exercise = "Lunges: ";
	getInput(exercise,liftedweight,reps,minute);
	repsLunge = reps; minLunge = minute;

	exercise = "Push Ups: ";
	getInput(exercise,liftedweight,reps,minute);
	repsPushUp = reps; minPushUp = minute; 

	exercise = "Pull Ups: ";
	getInput(exercise,liftedweight,reps,minute);
	calculateMET(exercise,reps,MET);repsPullUp = reps; minPullUp = minute; pullupMET = MET;

	cout << user_name<<", please enter minutes, repetitions and lifted weight in a week for the activities below."<<endl;
	exercise = "Weight Lifting: ";
	getInput(exercise,liftedweight,reps,minute);
	repsWeightLift = reps;minWeightLift = minute;liftedWeight = liftedweight;
	

	cout << user_name<<", please enter your weekly calorie burn goal: "; cin >> goal;

	error = inputCheck(weight,40,100,liftedweight); if (error == false) {return 0;}
	error = inputCheck(weight,repsLunge,100,liftedweight); if (error == false) {return 0;}
	error = inputCheck(40,repsPushUp,100); if (error == false) {return 0;}
	error = inputCheck(40,repsPullUp,100);if (error == false) {return 0;}
	error = inputCheck(40,repsWeightLift,100);if (error == false) {return 0;}
	error = inputCheck(40,repsLunge,minLunge); if (error == false) {return 0;}
	error = inputCheck(40,repsLunge,minPushUp); if (error == false) {return 0;}
	error = inputCheck(40,repsLunge,minPullUp);if (error == false) {return 0;}
	error = inputCheck(40,repsLunge,minWeightLift); if (error == false) {return 0;}
	computeResults(weight, goal, repsLunge, repsPushUp, repsPullUp, repsWeightLift, minLunge, minPushUp, minPullUp, minWeightLift, liftedWeight);

	return 0;
}