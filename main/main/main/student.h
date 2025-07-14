#ifndef STUDENT_H  
#define STUDENT_H  
#include "degree.h"  
#include <string> // Include this to resolve 'string' identifier issues  

using namespace std; // Ensure 'string' is recognized  

class Student {  

private:  
   string studentID;  
   string firstName;  
   string lastName;  
   string emailAddress;  
   int age;  
   int daysInCourse[3];  
   DegreeProgram degreeProgram;  

public:  
   // Constructor declaration  
   Student(string studentID,  
           string firstName,  
           string lastName,  
           string emailAddress,  
           int age,  
           int daysInCourse[],  
           DegreeProgram degreeProgram);  

   string GetStudentID();  
   string GetFirstName();  
   string GetLastName();  
   string GetEmailAddress();  
   int GetAge();  
   int* GetDaysInCourse();  
   DegreeProgram GetDegreeProgram();  

   void SetStudentID(string studentId);  
   void SetFirstName(string firstName);  
   void SetLastName(string lastName);  
   void SetEmailAddress(string emailAddress);  
   void SetAge(int age);  
   void SetDaysInCourse(int daysInCourse[]);  
   void SetDegreeProgram(DegreeProgram degreeProgram);  
   void print();  
   void printDaysInCourse();  
};  

// Constructor definition  
// Other methods remain unchanged
#endif // !STUDENT_H