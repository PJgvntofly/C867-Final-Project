#include <string>
#include <iostream>
#include <iomanip>
#include "roster.h"
using namespace std;

int main() {
	Roster classRoster;
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int class1Time;
	int class2Time;
	int class3Time;
	string degreeProgram;
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	string student;
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
								   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
								   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
								   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
								   "A5,Christopher,Gass,cgass4@wgu.edu,32,14,28,45,SOFTWARE" };

	for (int i = 0; i < 5; i++) {
		int commaLoc = 0;
		char userChar = ',';
		int j = 0;
		DegreePrograms studentProgram;

		student = studentData[i];

		commaLoc = student.find(userChar);
		studentID = student.substr(0, commaLoc);
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		firstName = student.substr(0, commaLoc);
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		lastName = student.substr(0, commaLoc);
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		email = student.substr(0, commaLoc);
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		age = stoi(student.substr(0, commaLoc));
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		class1Time = stoi(student.substr(0, commaLoc));
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		class2Time = stoi(student.substr(0, commaLoc));
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		class3Time = stoi(student.substr(0, commaLoc));
		student = student.substr(commaLoc + 1);

		commaLoc = student.find(userChar);
		degreeProgram = student.substr(0, commaLoc);
		for (j = 0; j < 3; j++) {
			if (degreeProgram == degreeProgramStrings[j]) {
				if (j == 1) {
					studentProgram = DegreePrograms::SECURITY;
				}
				else if (j == 2) {
					studentProgram = DegreePrograms::NETWORK;
				}
				else if (j == 3) {
					studentProgram = DegreePrograms::SOFTWARE;
				}
			}
		}
		classRoster.Add(studentID, firstName, lastName, email, age, class1Time, class2Time, class3Time, studentProgram);
	}

	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();
	
	for (int i = 0; i < 5; i++) {
		
	}

	cout << setw(5) << "" << "C867 - Scripting and Programming - Applications" << setw(5) << "" << endl;
	cout << setw(22) << "" << "C++" << setw(22) << "" << endl;
	cout << setw(18) << "" << 010004126 << setw(18) << "" << endl;
	cout << setw(9) << "" << "Christopher Gass" << setw(9) << "" << endl;


}