#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace searchtest
{
	class Student
	{
	public:
		int firstname, lastname;
		bool flushot;

	public:
		Student(int fname, int lname, bool shot) : firstname(fname), lastname(lname), flushot(shot) {}

		bool operator<(const Student& s1)
		{
		
			return (firstname < s1.firstname) && (lastname < s1.lastname) ;
		}

		bool operator==(const Student& s)
		{
			return (firstname == s.firstname) && (lastname == s.lastname);
		}

		/*
		bool operator==(const Student& s1, const Student& s2)
		{
			return (s1.firstname == s2.firstname) && (s1.lastname == s2.lastname);
		}
		*/

		void print()
		{
			cout << firstname << "->" << lastname << "->"  << flushot << endl;
		}
	};

	void searchtest()
	{
		std::vector<Student> students;
		students.push_back({1,2,false});
		students.push_back({ 2,2,false });
		students.push_back({ 3,2,false });

		

		Student s{ 2,2,false };
		auto compare = [&s](const Student& s2) { return s.firstname == s2.firstname; };
		auto it = std::find(students.begin(), students.end(),s);
		
		if (it != std::end(students))
		{
			cout << "Found";
			(*it).print();
		}
		else
		{
			cout << "Not found";
		}

	}

}

