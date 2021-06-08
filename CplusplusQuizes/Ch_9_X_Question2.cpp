//Question #2
//
//Write the following program : Create a struct that holds a student’s first name and grade(on a scale of 0 - 100).
//Ask the user how many students they want to enter.Create a std::vector to hold all of the students.
//Then prompt the user for each nameand grade.Once the user has entered all the namesand grade pairs, sort the list by grade(highest first).
//Then print all the namesand grades in sorted order.
//For the following input :
//
//Joe
//82
//Terry
//73
//Ralph
//4
//Alex
//94
//Mark
//88
//The output should look like this:
//
//Alex got a grade of 94
//Mark got a grade of 88
//Joe got a grade of 82
//Terry got a grade of 73
//Ralph got a grade of 4
//You can assume that names don’t contain spaces and that that input extraction doesn’t fail.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student
{
	std::string name{};
	int grade{};
};

int getNumberOfStudents() {
	int numberOfStudents{};

	do
	{
		std::cout << "How many students you want to store?: ";
		std::cin >> numberOfStudents;
	} while (numberOfStudents <= 0);

	return numberOfStudents;
}

std::vector<Student> getStudents() {

	using vector_type = std::vector<Student>;

	int numberOfStudents{ getNumberOfStudents() };

	vector_type students(static_cast<vector_type::size_type>(numberOfStudents));

	int studentNumber{ 1 };

	for (auto& student : students) {
		std::cout << "Enter name #" << studentNumber << ": ";
		std::cin >> student.name;
		std::cout << "Enter gramde #" << studentNumber << ": ";
		std::cin >> student.grade;
		++studentNumber;
	}

	return students;
}

bool compareStudents(const Student& a, const Student& b) {
	return (a.grade > b.grade);
}

int Ch_9_X_Question2() {

	std::vector<Student> students{ getStudents() };

	std::sort(students.begin(), students.end(), compareStudents);

	for (const auto& student : students) {
		std::cout << student.name << " got a grade of " << student.grade << ". \n";
	}

	return 0;
}