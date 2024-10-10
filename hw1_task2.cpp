#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int inputNumber = 0;
	int checkSeconds = 63;
	int checkMinutes = 4032;
	int checkSmallHours = 15360;
	int checkBigHours = 196608;
	int checkClockFormat = 262144;
	int seconds = 0;
	int minutes = 0;
	int smallHours = 0;
	int bigHours = 0;
	int clockFormat = 0;

	

		cout << "Enter a positive natural number to turn it into its Binary Clock format: ";
		cin >> inputNumber;

		//Turns the first 6 bits to seconds
		seconds = inputNumber & checkSeconds;

		//Turns the next 6 bits to minutes
		minutes = (inputNumber & checkMinutes) >> 6;

		//Turns the next 4 bits in small number of hours
		smallHours = (inputNumber & checkSmallHours) >> 12;

		//Turns the next 2 bits in the big number of hours
		bigHours = (inputNumber & checkBigHours) >> 16;

		//Checks if the clock should be in 24h or 12h format
		clockFormat = (inputNumber & checkClockFormat) >> 18;


		//Checks if the hour is bigger than 12 in a 12h clock format
		if (clockFormat == 0) {
			if (bigHours > 1 && smallHours > 2) {
				cout << "Invalid data!";
				return 0;
			}
		}
		//Checks if the hour is bigger than 24 in a 24h clock format 
		if (clockFormat == 1) {
			if (bigHours > 2) {
				cout << "Invalid data!";
				return 0;
			}
		}

		//Make sure that the seconds and minutes are in the scope
		if (seconds > 59) {
			cout << "Invalid data!";
			return 0;
		}
		if (minutes > 59) {
			cout << "Invalid data!";
				return 0;
		}

		//Add one 0 so it can be simetrical
		if (seconds < 10 && minutes < 10) {
			cout << "\nThe number that you have enter convert to the following time: " << bigHours << smallHours << ":0" << minutes << ":0" << seconds;
			return 0;
		}
		//Add one 0 so it can be simetrical
		else if (seconds < 10) {
			cout << "\nThe number that you have enter convert to the following time: " << bigHours << smallHours << ":" << minutes << ":0" << seconds;
			return 0;
		}
		//Add one 0 so it can be simetrical
		else if (minutes < 10) {
			cout << "\nThe number that you have enter convert to the following time: " << bigHours << smallHours << ":0" << minutes << ":" << seconds;
			return 0;
		}
		else {
			cout << "\nThe number that you have enter convert to the following time: " << bigHours << smallHours << ":" << minutes << ":" << seconds;
		}


		


}

