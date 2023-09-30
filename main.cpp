#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>

using namespace std;

int main() { 
    const string studentData[]
    {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Brandon,Castellanos,bcas252@wgu.edu,28,17,25,31,SOFTWARE"
    };

    Roster classRoster;

    cout << "C-867: Scripting and Programming - Applications" << endl;
    cout << "Program written in C++" << endl;
    cout << "ID: 011341797\nName: Brandon Castellanos\n\n";
  
    classRoster.PopulateRoster(studentData, size(studentData));
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();

    for (int i = 0; i < classRoster.classRosterArray.size(); i++) {
        classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
    }

    classRoster.PrintByDegreeProgram(SOFTWARE);
    classRoster.Remove("A3");
    classRoster.PrintAll();
    classRoster.Remove("A3");
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();
        
    return 0;
}