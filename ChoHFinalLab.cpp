#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include "Student.h"
using namespace std;

bool sort_First_name(const Student stu1, const Student stu2)
{
		return (stu1.First_Name() < stu2.First_Name());
}
bool sort_Last_name(const Student stu1, const Student stu2)
{
	if (stu1.Last_Name() == stu2.Last_Name())
		return (stu1.First_Name() > stu2.Last_Name());
	return (stu1.Last_Name() < stu2.Last_Name());
}

bool sort_Age(const Student stu1, const Student stu2)
{
		return stu1.Age() < stu2.Age();
}

int main()
{
	//1) testing for vector
	/* IT WORKS!
	vector<Student> vecStu;
	string inPutFileName, first_name, last_name;
	float gpa;
	int age;
	cout << "Enter full path to input file: ";
	getline(cin, inPutFileName);
	ifstream in;
	in.open(inPutFileName);
	if (!in)
	{
		cout << "Failed to open input file." << endl;
		exit(0);
	}
	while (!in.eof())
	{ 
		in >> first_name;
		in >> last_name;
		in >> age;
		in >> gpa;
		vecStu.emplace_back(first_name, last_name, age, gpa);
	}
	//sorting by first name
	sort(vecStu.begin(), vecStu.end(), sort_First_name);
	vector<Student>::iterator Iter;
	cout << "************Sorting By First Name************\n";
	for (Iter = vecStu.begin(); Iter != vecStu.end(); Iter++)
		cout << " " << *Iter;
	cout << '\n';

	//sorting by last name
	sort(vecStu.begin(), vecStu.end(), sort_Last_name);
	cout << "************Sorting By Last Name************\n";
	for (Iter = vecStu.begin(); Iter != vecStu.end(); Iter++)
		cout << " " << *Iter;
	cout << '\n';

	//sorting by age
	sort(vecStu.begin(), vecStu.end(), sort_Age);
	cout << "************Sorting By Age************\n";
	for (Iter = vecStu.begin(); Iter != vecStu.end(); Iter++)
		cout << " " << *Iter;
	cout << "Press Enter the Continue: " << flush;
	cin.get();*/
//-----------------------------------------------------------------------------------------
	//2) List Class
	/* ALSO WORKS!
	list<Student> liStu;
	string inPutFileName, first_name, last_name;
	ifstream in;
	float gpa;
	int age;
	cout << "Enter full path to input file: ";
	getline(cin, inPutFileName);
	in.open(inPutFileName);
	if (in.fail())
	{
		cout << "Failed to open input file." << endl;
		exit(0);
	}
	while (!in.eof())
	{
		in >> first_name;
		in >> last_name;
		in >> age;
		in >> gpa;
		liStu.emplace_back(first_name, last_name, age, gpa);
	}
	//sorting by first name
	liStu.sort(sort_First_name);
	list<Student>::iterator Iter;
	cout << "************Sorting By First Name************\n";
	for (Iter = liStu.begin(); Iter != liStu.end(); Iter++)
		cout << " " << *Iter;
	cout << '\n';

	//sorting by last name
	liStu.sort(sort_Last_name);
	cout << "************Sorting By Last Name************\n";
	for (Iter = liStu.begin(); Iter != liStu.end(); Iter++)
		cout << " " << *Iter;
	cout << '\n';

	//sorting by age
	liStu.sort(sort_Age);
	cout << "************Sorting By Age************\n";
	for (Iter = liStu.begin(); Iter != liStu.end(); Iter++)
		cout << " " << *Iter;
	cout << "Press Enter the Continue: " << flush;
	cin.get();*/
//-------------------------------------------------------------------------------------
	//3) Testing for function object
	//ITS WORKING ALSO !!!
	list<Student> liStu;
	Student stud;	
	string inPutFileName, first_name, last_name;
	ifstream in;
	float gpa;
	int age;
	cout << "Enter full path to input file: ";
	getline(cin, inPutFileName);
	in.open(inPutFileName);
	if (in.fail())
	{
		cout << "Failed to open input file." << endl;
		exit(0);
	}
	while (!in.eof())
	{
		in >> first_name;
		in >> last_name;
		in >> age;
		in >> gpa;
		liStu.emplace_back(first_name, last_name, age, gpa);
	}
	//sorting by first name
	Student::Choice(1);//setting choice = 1
	liStu.sort(stud);
	list<Student>::iterator Iter;
	cout << "************Sorting By First Name************\n";
	for (Iter = liStu.begin(); Iter != liStu.end(); Iter++)
		cout << " " << *Iter;
	cout << '\n';

	//sorting by last name
	Student::Choice(2); // setting choice = 2 
	liStu.sort(stud);
	cout << "************Sorting By Last Name************\n";
	for (Iter = liStu.begin(); Iter != liStu.end(); Iter++)
		cout << " " << *Iter;
	cout << '\n';

	//sorting by age
	Student::Choice(3); // setting choice = 3
	liStu.sort(stud);
	cout << "************Sorting By Age************\n";
	for (Iter = liStu.begin(); Iter != liStu.end(); Iter++)
		cout << " " << *Iter;
	cout << "Press Enter the Continue: " << flush;
	cin.get();
//-------------------------------------------------------------------------------------
	/*
	4) 
		Both Vector and List STL are different in few areas. While both STL uses
		the iterator to move throughout the data, the list allocates memories for 
		each individual data in it. Meanwhile vector classes create adjacent
		memory for all data, list can be saved and changed in any place of the memory.
		Vector is generally useful when creating dynamic arrays or lists of objects.
		List would be useful in situations where insertion and deletion in containers.
	*/
}