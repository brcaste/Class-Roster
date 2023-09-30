#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

using namespace std;

class Roster{
    public:
        vector<Student*> classRosterArray;

        Roster();
        ~Roster();
        void PopulateRoster(const string studentData[],int size);
        void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void Remove(string studentID);
        void PrintAll();
        void PrintAverageDaysInCourse(string studentID);
        void PrintInvalidEmails();
        void PrintByDegreeProgram(DegreeProgram degreeProgram);

};

#endif