// dayOfTheWeek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string getDayOfWeek(int dayNum)
{
	string dayName;
	switch (dayNum)
	{
	case 0: dayName = "Sunday";
		break;
	case 1: dayName = "Monday";
		break;
	case 2: dayName = "Tuesday";
		break;
	case 3: dayName = "Wednesday";
		break;
	case 4: dayName = "Thursday";
		break;
	case 5: dayName = "Friday";
		break;
	case 6: dayName = "Saturday";
		break;
	default:
		dayName = "Invalid day number";
	}

	return dayName;

}


int main()
{
	cout << getDayOfWeek(0) << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
