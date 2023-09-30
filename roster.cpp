#include "roster.h"
#include <sstream>
#include <iostream>

using namespace std;

Roster::Roster() {}

Roster::~Roster() {
    cout << "Calling destructor...";
    vector<Student*>::iterator it;
    for (it = classRosterArray.begin(); it != classRosterArray.end();) {
        delete* it;
        it = classRosterArray.erase(it);
    }
    if (classRosterArray.empty()) {
        cout << "Class Roster is empty.\n";
    }
}

void Roster::PopulateRoster(const string studentData[],int size) {
   
    vector<string> dataSet;
    char delim = ',';
    string token = "";
    DegreeProgram degreeProgram = SOFTWARE;

    for (int i = 0; i < size; i++) {
       
        stringstream ss(studentData[i]);
        while (ss.good()) {
            getline(ss, token, delim);
            dataSet.push_back(token);
            
        }
 
        if (dataSet[8] == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (dataSet[8] == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else {
            degreeProgram = SOFTWARE;
        }
        Add(dataSet[0], dataSet[1], dataSet[2], dataSet[3], stoi(dataSet[4]), stoi(dataSet[5]), stoi(dataSet[6]), stoi(dataSet[7]), degreeProgram);
        
        dataSet.clear();
    }
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    Student* newStudent = new Student(studentID,firstName,lastName,emailAddress,age,daysInCourse1,daysInCourse2,daysInCourse3,degreeProgram);
    classRosterArray.push_back(newStudent);
}   

void Roster::Remove(string studentID){

    vector<Student*>::iterator it;
    bool studentExists = false;
    
    for (it = classRosterArray.begin(); it != classRosterArray.end();) {
        if ((*it)->GetStudentID() == studentID) {
            delete* it;
            it = classRosterArray.erase(it);
            studentExists = true;
            cout << "Student ID: " << studentID << " has been removed from roster.\n";
            break;
        }
        else {
            ++it;
        }
    }
    if (!studentExists) {
        cout << "Tried to remove Student with ID "<< studentID << ", but was not found in the roster." << endl;
    }
    
}

void Roster::PrintAll(){

    cout << "**************************--CLASS ROSTER--**********************************\n";
    for (int i = 0; i < classRosterArray.size(); i++) {
        classRosterArray[i]->Print();
    }
    cout << "****************************************************************************\n";

}

void Roster::PrintAverageDaysInCourse(string studentID){
    vector<Student*>::iterator it;
    vector<int> daysCopyArray;
    int total = 0;
    float avg = 0.0;
    bool studentExists = false;

    for (it = classRosterArray.begin(); it != classRosterArray.end();) {
        if ((*it)->GetStudentID() == studentID) {
            studentExists = true;
            daysCopyArray = (*it)->GetDaysPerCourse();
            for (int i = 0; i < daysCopyArray.size(); i++) {
                total += daysCopyArray[i];
            }
            avg = total / daysCopyArray.size();
            break;
        }
        else {
            ++it;
        }
    }
    
    cout << "Average days in course for Student ID " <<studentID <<" is : " << avg <<" days.\n";

}

void Roster::PrintInvalidEmails(){
    vector<Student*>::iterator it;
    bool invalidFlag = false;
    string email;
    cout << "**********************--PRINTING INVALID EMAILS--***************************\n";
    for (it = classRosterArray.begin(); it != classRosterArray.end();) {
        email = (*it)->GetEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            invalidFlag = true;
            cout << email << endl;
        }
        ++it;
    }
    if (!invalidFlag) {
        cout << "All student email addresses are valid" << endl;
    }
    cout << "****************************************************************************\n";
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram){
    vector<Student*>::iterator it;
    cout << "**************************--CLASS ROSTER BY DEGREE--**********************************\n";
    for (it = classRosterArray.begin(); it != classRosterArray.end();) {
        if ((*it)->GetDegreeProgram() == degreeProgram) {
            (*it)->Print();
        }
        ++it;
    }
    cout << "****************************************************************************\n";  
}

