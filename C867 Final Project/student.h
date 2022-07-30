#pragma once
#include <vector>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	Student(string studentID, string firstName, string lastName, string email, int age, int course1Days, int course2Days, int course3Days, DegreePrograms degreeProgram);
	~Student();
	void SetID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void AddCourseDays(int days);
	void SetDegreeProgram(DegreePrograms degreeProgram);

	string GetID();
	string GetName();
	string GetEmail();
	int GetAge();
	vector<int> GetCourseDays();
	DegreePrograms GetDegreeProgram();
	void PrintInfo();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	vector<int> courseDays;
	DegreePrograms degreeProgram;
};
