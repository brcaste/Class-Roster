#include "student.h"
#include <iostream>

using namespace std;

Student::Student(string id , string fn, string ln, string email, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
	this->studentID = id;
	this->firstName = fn;
	this->lastName = ln;
	this->emailAddress = email;
	this->age = studentAge;
	this->daysPerCourse.push_back(daysInCourse1);
	this->daysPerCourse.push_back(daysInCourse2);
	this->daysPerCourse.push_back(daysInCourse3);
	this->degreeProgram = degreeProgram;
}

Student::Student() :studentID(""), firstName(""), lastName(""), emailAddress(""), age(0), daysPerCourse((0)), degreeProgram(SECURITY){}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

vector<int> Student::GetDaysPerCourse() const {
	return daysPerCourse;
	
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
}

void Student::SetStudentID(string id){
	studentID = id;
}

void Student::SetFirstName(string fn){
	firstName = fn;
}

void Student::SetLastName(string ln){
	lastName = ln;
}

void Student::SetEmailAddress(string email){
	emailAddress = email;
}

void Student::SetAge(int studentAge){
	age = studentAge;
}

void Student::SetDaysPerCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3){
	daysPerCourse.push_back(daysInCourse1);
	daysPerCourse.push_back(daysInCourse2);
	daysPerCourse.push_back(daysInCourse3);
}

void Student::SetDegreeProgram(DegreeProgram d){
	degreeProgram = d;
}


void Student::PrintDaysPerCourse(){
	cout << "{";
	for (int i = 0; i < daysPerCourse.size(); i++) {
		cout << daysPerCourse.at(i);
		if (i != daysPerCourse.size() - 1) {
			cout << ", ";
		}
	}
	cout << "}";
}

void Student::PrintDegreeProgram(){

	if (degreeProgram == SECURITY) {
		cout << "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		cout << "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		cout << "SOFTWARE";
	}
}

void Student::Print(){

	cout << GetStudentID() << "\tFirst Name : " << GetFirstName() << "\tLast Name : " << GetLastName() << "\tAge : " << GetAge() << "\tdaysInCourse : ";
	PrintDaysPerCourse();
	cout << "\tDegree Program: ";
	PrintDegreeProgram();
	cout << "\n";
}
	