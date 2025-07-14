#pragma once
#include <iostream>
#include <string>
#include "student.h"


class Roster
{
public:
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

	Roster(); //constructor to initialize the classRosterArray to nullptr.

	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);

	 ~Roster(); //destructor to release the memory that was allocated dynamically in Roster.

	}
;