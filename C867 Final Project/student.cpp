#include <iostream>
#include <string>
#include <vector>
#include "student.h"

Student::Student(string studentID, string firstName, string lastName, string email, int age, int course1Days, int course2Days, int course3Days, DegreePrograms degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	courseDays.push_back(course1Days);
	courseDays.push_back(course2Days);
	courseDays.push_back(course3Days);
	this->degreeProgram = degreeProgram;
}

Student::~Student() {
	delete this;
}

void Student::SetID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmail(string email) {
	bool validEmail = false;
	if (email.find('@') != string::npos && email.find(email.substr(email.find('@'))) != string::npos) {
		this->email = email;
	}
	else {
		cout << "Please use a valid email address." << endl;
	}
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDegreeProgram(DegreePrograms degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::AddCourseDays(int courseDays) {
	this->courseDays.push_back(courseDays);
}

string Student::GetID() {
	return studentID;
}

string Student::GetName() {
	string fullName = firstName + " " + lastName;
	return fullName;
}

string Student::GetEmail() {
	return email;
}

int Student::GetAge() {
	return age;
}

vector<int> Student::GetCourseDays() {
	return courseDays;
}

DegreePrograms Student::GetDegreeProgram() {
	return degreeProgram;
}

void Student::PrintInfo() {
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName
		<< "\t" << "Age: " << age << "\t" << "daysInCourse: {";
	for (unsigned int i = 0; i < courseDays.size(); i++) {
		if (i < (courseDays.size() - 1)) {
			cout << courseDays.at(i) << ", ";
		}
		else {
			cout << courseDays.at(i);
		}
	}
	cout << "} Degree Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
}