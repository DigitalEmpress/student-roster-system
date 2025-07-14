#include <iostream>  
#include <string>  
#include "roster.h"  
using namespace std;  

int main() {  
   const int numStudents = 5;  
   const string studentData[] = {  
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",  
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",  
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",  
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",  
       "A5,Mesyia,Lawson,nun@wgu.edu,56,32,5,22, SOFTWARE"  
   };  

   // Print out course details  
   cout << "Course Title: C867 Scripting and Programming Applications" << endl;  
   cout << "Programming Language Used: C++" << endl;  
   cout << "WGU Student ID: 00000000" << endl;  
   cout << "Name: Mesyia Lawson" << endl;  
   cout << endl;  

   // Create an instance of the Roster class  
   Roster classRoster;  

   // Parse the data and add it to the classRosterArray  
   for (int i = 0; i < numStudents; i++) {  

       classRoster.parse(studentData[i]);  
   }  


   classRoster.printAll();
   cout << endl;
   // Print invalid emails

   classRoster.printInvalidEmails();
   cout << endl;

   // Print average days in course for each student
   cout << "Average Days in Course:" << endl;
   for (int i = 0; i < numStudents; i++) {
	   classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
   }
   cout << endl;


   // Print students by degree program
   cout << "Degree Program:" << endl;
   classRoster.printByDegreeProgram(SOFTWARE);
   cout << endl;

   // Remove a student
   classRoster.remove("A3");
  cout << "Removing A3:" << endl;
   classRoster.printAll();
   cout << endl;

   cout << "Removing A3:" << endl;
   classRoster.remove("A3");

   if (classRoster.classRosterArray[0] == nullptr) {
	   cout << "Student with ID A3 not found!" << endl;
      
   }
   else {
       cout << endl;
   }

   // Clean up memory

   classRoster.~Roster();
 
   
   return 0;  
}
