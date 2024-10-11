# include "roster.h"
# include <iostream>
# include <string>
int
main()
{
    cout << "----------------------------------------------------------------" << endl;
cout << "Integrated Development Environment written in C++" << endl;
cout << "----------------------------------------------------------------" << endl;

const
string
studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Estudios,Zacate,zacate@inbox.mail,23,13,35,13,SOFTWARE",
};

Roster
roster;
for (int i = 0; i < 5; i++)
{
    roster.parse(studentData[i]);
};

cout << "Showing each student:" << endl;
roster.printAll();

cout << endl;

for (int i = 0; i < 3; i++)
{
    cout << "Showing by degree program:" << degreeProgramArray[i] << endl;
roster.printByDegree((DegreeProgram)
i);
}

cout << "Showing all with invalid emails:" << endl;
roster.printInvalidEmails();

cout << "Showing average days to complete a course:" << endl;
for (int i = 0; i < numStudents; i++)
roster.printAverageDaysToComplete(roster.getStudents()[i]->getStudentID());

cout << "Removing student A3" << endl;
roster.removeStudentByID("A3");

cout << "Removing student A3" << endl;
roster.removeStudentByID("A3");

cout << "Complete! Destructors will now be called immediately and release all dynamically allocated memory." << endl;
return 0;
}
