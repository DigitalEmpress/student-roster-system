#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

//constructor

    Student::Student(string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse[],
        DegreeProgram degreeProgram) {
        this->studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->emailAddress = emailAddress;
        this->age = age;
        this->daysInCourse[0] = daysInCourse[0];
        this->daysInCourse[1] = daysInCourse[1];
        this->daysInCourse[2] = daysInCourse[2];
        this->degreeProgram = degreeProgram;
    }

    void Student::print() {


        cout << studentID << "   First Name: " << firstName << "   Last Name: " << lastName << "   Email Address: " << emailAddress << "   Age: " << age << "   Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}   Degree Program: ";
        switch (degreeProgram) {
        case SECURITY:
            cout << "SECURITY";
            break;
        case NETWORK:
            cout << "NETWORK";
            break;
        case SOFTWARE:
            cout << "SOFTWARE";
            break;
        default:
            cout << "Unknown Degree Program";
        }
        
		cout << endl;
        
    };


   void Student::SetStudentID(string studentId) {
       this->studentID = studentId;
   };
   void Student::SetFirstName(string firstName) {
       this->firstName = firstName;
   };
   void Student::SetLastName(string lastName) {
       this->lastName = lastName;
   };
   void Student::SetEmailAddress(string emailAddress) {
       this->emailAddress = emailAddress;
   };
   void Student::SetAge(int age) {
       this->age = age;
   };
   void Student::SetDaysInCourse(int daysInCourse[]) {
       this->daysInCourse[0] = daysInCourse[0];
       this->daysInCourse[1] = daysInCourse[1];
       this->daysInCourse[2] = daysInCourse[2];
   };
   void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
       this->degreeProgram = degreeProgram;
   };

   void Student::printDaysInCourse() {
       cout << "Days in Course: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << endl;
   };



   string Student::GetStudentID() {
       return studentID;
   };
   string Student::GetFirstName() {
       return firstName;
   };
   string Student::GetLastName() {
       return lastName;
   };
   string Student::GetEmailAddress() {
       return emailAddress;
   };
   int Student::GetAge() {
       return age;
   };
   int* Student::GetDaysInCourse() {
       return daysInCourse;
   };
   DegreeProgram Student::GetDegreeProgram() {
	   return degreeProgram;
   };
