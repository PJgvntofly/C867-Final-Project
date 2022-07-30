#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "roster.h"
using namespace std;

void Roster::Add(string studentID, string firstName, string lastName, string email, int age, int class1Days, int class2Days, int class3Days, DegreePrograms degreeProgram) {
	Student tempStudent(studentID, firstName, lastName, email, age, class1Days, class2Days, class3Days, degreeProgram);
	Student* studentPntr;

	studentPntr = &tempStudent;
	for (unsigned int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = studentPntr;
		}
	}
}

void Roster::Remove(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetID() == studentID) {
				delete classRosterArray[i];
			}
		}
	}
}

void Roster::PrintAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->PrintInfo();
		}
	}
}

void Roster::PrintAvgDaysInCourse(string studentID) {
	int totalTime = 0;
	vector<int> courseDays;
	string studentID;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetID() == studentID) {
				studentID = classRosterArray[i]->GetID();
				courseDays = classRosterArray[i]->GetCourseDays();
				for (unsigned int i = 0; i < courseDays.size(); i++) {
					totalTime += courseDays.at(i);
				}
			}
		}

	}
	cout << "Average Class Time for Student " << studentID << ": " << totalTime / 3 << endl;
}

void Roster::PrintInvalidEmails() {
	cout << "Invalid Email Addresses:" << endl;
	cout << setfill('-') << setw(35) << "" << endl;
	cout << setfill(' ');
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			string email;
			email = classRosterArray[i]->GetEmail();
			if (!(email.find('@') != string::npos && email.find(email.substr(email.find('@'))) != string::npos)) {
				cout << classRosterArray[i]->GetID() << ": " << email << endl;
			}
		}
	}
}

Student* Roster::GetClassRosterArrayValue(int i) {
	return classRosterArray[i];
}