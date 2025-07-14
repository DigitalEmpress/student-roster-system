#pragma once
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

const static int numStudents = 5;
Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };


Roster::Roster()
{//initialize the classRosterArray to nullptr
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i] = nullptr;
	}

}
//create a student object for each student in the data table and populate classRosterArray.
void Roster::parse(string studentData) {
	//parse the studentData string using a comma as a delimiter

	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs));

	DegreeProgram degreeProgram;
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);

	(studentData.substr(lhs, rhs - lhs) == "SECURITY") ? degreeProgram = SECURITY :
		(studentData.substr(lhs, rhs - lhs) == "NETWORK") ? degreeProgram = NETWORK :
		(studentData.substr(lhs, rhs - lhs) == "SOFTWARE") ? degreeProgram = SOFTWARE : degreeProgram = SOFTWARE;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
//parse the data and add it to the classRosterArray.

//parseAndAdd function will take a string as an argument, which contains the student data in a specific format.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysIncourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	//create a new student object
	int daysInCourse[] = { daysIncourse1, daysInCourse2, daysInCourse3};

	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
	//add the student object to the classRosterArray
	for (int i = 0; i < Roster::numStudents; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = student;
			break;
		}
	}
	};


void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < Roster::numStudents; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			cout << "Student with ID " << studentID << " has been removed." << endl;
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " not found." << endl;
	}
};
void Roster::printAll() {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;

};
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			int* daysInCourse = classRosterArray[i]->GetDaysInCourse();
			int averageDays = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
			cout <<	studentID << ": " << averageDays << endl;
			break;
		}
	}

};
void Roster::printInvalidEmails(){
	for (int i = 0; i < Roster::numStudents; i++){
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->GetEmailAddress();
			if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
				cout << "Invalid email: " << email << endl;
			}
		}
	}
};
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {  
for (int i = 0; i < numStudents; i++) {  
	if (classRosterArray[i] != nullptr && classRosterArray[i]->GetDegreeProgram() == degreeprogram) {  
		classRosterArray[i]->print();
	}  
}  
}
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
	}
}

