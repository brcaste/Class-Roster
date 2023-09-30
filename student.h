#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "degree.h"

using namespace std;
class Student{
    public:
        //constructor
        Student(string id, string fn, string ln, string email, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        Student();
            
        //getters
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const; 
        string GetEmailAddress() const; 
        int GetAge() const;
        vector<int> GetDaysPerCourse()const;
        DegreeProgram GetDegreeProgram() const;

        //setters
        void SetStudentID(string id);
        void SetFirstName(string fn);
        void SetLastName(string  ln);
        void SetEmailAddress(string email);
        void SetAge(int studentAge);
        void SetDaysPerCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) ;
        void SetDegreeProgram(DegreeProgram deg) ;
       
        //print
        void PrintDaysPerCourse();
        void PrintDegreeProgram();
        void Print();   

    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        vector<int> daysPerCourse;
        DegreeProgram degreeProgram;
    
};  
#endif
