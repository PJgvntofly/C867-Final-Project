#pragma once
#include <string>
#include "student.h"
using namespace std;

class Roster {
public:
	void Add(string studentID, string firstName, string lastName, string email, int age, int class1Days, int class2Days, int class3Days, DegreePrograms degreeProgram);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	Student* GetClassRosterArrayValue(int i);
private:
	Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
};
