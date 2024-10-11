#include <string>
#include <iostream>
#include "student.h"

Student::Student() //Empty constructor
{
    this->id = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = "";
    for (int i = 0; i < totalDays; i++) this->daysInCourse[i] = 0;
    this->dp = DegreeProgram::SECURITY;
}

Student::Student(string id, string firstName,string lastName,string email,string age, const int daysInCourse[], DegreeProgram dp) //Full constructor
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < totalDays; i++) this->daysInCourse[i] = daysInCourse[i];
    this->dp = dp;
}

Student::~Student(){} //Destructor

//Getters
string Student::getStudentID() { return this-> id; } //Errors at run
string Student::getStudentFirstName() { return this-> firstName; }
string Student::getStudentLastName() { return this-> lastName; }
string Student::getStudentEmail() { return this-> email; }
string Student::getStudentAge() { return this-> age; }
int* Student::getDaysInCourse() { return this-> daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this-> dp; }

//Setters
void Student::setID(string id) { this->id = id; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(string age) { this->age = age; }
void Student::setDaysInCourse(const int daysInCourse[])
{
    for (int i = 0; i < totalDays; i++) this->daysInCourse[i] = daysInCourse[i]; //Loop
}
void Student::setDegreeProgram(DegreeProgram dp) { this->dp = dp; }
void Student::printHeader()
{
    cout << "ID\t";
    cout << "FirstName\t";
    cout << "LastName\t";
    cout << "Email\t";
    cout << "Age\t";
    cout << "DaysInCourse1\t";
    cout << "DaysInCourse2\t";
    cout << "DaysInCourse3\t";
    cout << "Degree\t";
    cout << endl;
}
void Student::print()
{
    cout << this->id << '\t';
    cout << this->firstName << '\t';
    cout << this->lastName << '\t';
    cout << this->email << '\t';
    cout << this->age << '\t';
    cout << this->daysInCourse[0] << '\t';
    cout << this->daysInCourse[1] << '\t';
    cout << this->daysInCourse[2] << '\t';
    cout << degreeProgramArray[(int)this->dp];
    cout << endl;
}
