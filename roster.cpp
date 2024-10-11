# include "roster.h"
# include <iostream>
# include <string>
# include <vector>

using
std::vector;
using
std::stringstream;

Roster::Roster()
{
for (int i = 0; i < 5; i++)
{
    getStudents()[i] = nullptr;
}; // initially sets each ptr to null in classRoster array

}
void
Roster::parse(string
studentData)
{
    vector < string > result;
size_t
start;
size_t
end = 0;
while ((start = studentData.find_first_not_of(',', end)) != string: :
    npos)
{
    end = studentData.find(',', start);
result.push_back(studentData.substr(start, end - start));
}
DegreeProgram
dp = DegreeProgram::SECURITY;
switch(result.at(8).back())
{
    case
'K': dp = DegreeProgram::NETWORK;
break;
case
'E': dp = DegreeProgram::SOFTWARE;
break;
}
add(result.at(0), result.at(1), result.at(2), result.at(3), result.at(4), stoi(result.at(5)), stoi(result.at(6)),
    stoi(result.at(7)), dp); // Call
for roster
}

void Roster::
    add(string
id, string
firstName, string
lastName, string
email, string
age, int
daysInCourse1, int
daysInCourse2, int
daysInCourse3, DegreeProgram
dp)
{
    int
daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
classRosterArray[++lastIndex] = new
Student(id, firstName, lastName, email, age, daysInCourse, dp);
cout << "Student added to class roster at row" << lastIndex + 1 << endl;
}

void
Roster::printAll()
{
    Student:: printHeader();
for (int i = 0; i <= Roster::lastIndex; i++)
{
cout << classRosterArray[i]->getStudentID();
cout << '\t';
cout << classRosterArray[i]->getStudentFirstName();
cout << '\t';
cout << classRosterArray[i]->getStudentLastName();
cout << '\t';
cout << classRosterArray[i]->getStudentEmail();
cout << '\t';
cout << classRosterArray[i]->getStudentAge();
cout << '\t';
cout << classRosterArray[i]->getDaysInCourse()[0];
cout << '\t';
cout << classRosterArray[i]->getDaysInCourse()[1];
cout << '\t';
cout << classRosterArray[i]->getDaysInCourse()[2];
cout << '\t';
cout << degreeProgramArray[classRosterArray[i]->getDegreeProgram()] << std::endl;
}
}

void
Roster::printByDegree(DegreeProgram
dp)
{
    Student:: printHeader();
for (int i = 0; i <= Roster::lastIndex; i++)
{
if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
}
cout << std::endl;
}

void
Roster::printInvalidEmails()
{
for (int i = 0; i <= Roster::lastIndex; i++)
{
    string
    id = Roster::getStudents()[i]->getStudentEmail();
    if (id.find(' ') != string::npos | | id.find('.') == string: :
        npos | | id.find('@') == string::npos)
    cout << id << " is invalid" << endl;
}
}

void
Roster::printAverageDaysToComplete(string
id)
{
for (int i = 0; i <= Roster::lastIndex; i++)
{
    if (classRosterArray[i]->getStudentID() == id)
    {
        cout << id << ": ";
    cout << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[
        i]->getDaysInCourse()[2]) / 3.0 << endl;
    }
    }
    }

    void
    Roster::removeStudentByID(string
    id)
    {
        bool
    success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == id)
        {
            success = true;
        Student * temp = classRosterArray[i];
        classRosterArray[i] = classRosterArray[numStudents - 1];
        classRosterArray[numStudents - 1] = temp;
        Roster::lastIndex - -;
        }
        }
        if (success)
        {
        cout << "Student " << id << " removed." << endl; // Removing
        student
        by
        id
        printAll(); // Showing
        current
        student
        roster
    }
    else cout << "Student " << id << " not found." << endl;
    }

    Student ** Roster::getStudents()
    {
    return Roster::classRosterArray;
}

Roster::~Roster() // Returns
pointer
to
an
array
{
for (int i = 0; i < numStudents; i++)
    {
        cout << "Destructor called for " << classRosterArray[i]->getStudentID() << endl;
    delete
    classRosterArray[i];
    classRosterArray[i] = nullptr;
    }
    }
