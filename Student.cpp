#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

				//Friend Function operators
ostream& operator<<(std::ostream &os, const Student & s)
{
	s.Write(os);
	return os; 
}
istream& operator>>(std::istream &is, Student & s)
{
	s.Read(is);
	return is;
}

				//Member Fucntion
	
//Constructor & Copy Constructor
Student::Student() : m_age(0)
{
	m_first_name = "Not Set First Name";
	m_last_name = "Not Set Last Name";
	m_age = 0;
	m_gpa = 0.0f;
}
Student::Student(string first_name, string last_name, int age, float GPA) : 
	m_first_name(first_name), m_last_name(last_name), m_age(age), m_gpa(GPA){}


//Accessor & Mutator
	//For m_first_name & m_last_name
void Student::First_Name(string first_name)
{
	m_first_name = first_name;
}
void Student::Last_Name(string last_name)
{
	m_last_name = last_name;
}
string Student::First_Name() const
{
	return string(m_first_name);
}
string Student::Last_Name() const
{
	return string(m_last_name);
}
	//For m_age
void Student::Age(int Age)
{
	m_age = Age;
}
int Student::Age() const
{
	return m_age;
}
	//For m_gpa
void Student::GPA(float gpa)
{
	m_gpa = gpa;
}
float Student::GPA() const
{
	return m_gpa;
}

void Student::Read(std::istream &is)
{
	if (&is == &cin)
	{
		cout << "Enter the first name: " << flush;
		is >> m_first_name;
		cout << "Enter the last name: " << flush;
		is >> m_last_name;
		cout << "Enter the Age: " << flush;
		is >> m_age;
		cout << "Enter the GPA: " << flush;
		is >> m_gpa;
	}
	else
	{
		is >> m_first_name;
		is >> m_last_name;
		is >> m_age;
		is >> m_gpa;
	}
}
void Student::Write(std::ostream &os) const
{
	if (&os == &cout)   
		os << "First Name: " << m_first_name << "\nLast Name: " << m_last_name << "\nAge: " 
			<< m_age << "\nGPA: " << m_gpa << '\n';
	else
		os << m_first_name << '\n' <<m_last_name<<'\n'<< m_age << '\n' << m_gpa << '\n';
}
void Student::Choice(int selection)
{
	if (m_choice < 1 || m_choice > 3)
	{
		cout << "\n\n***** ERROR. Student::Choice. Invalid sort choice passed."
			<< "\n*****       The sort option must be either 1, 2, or 3."
			<< "\n\nHit enter to exit the program: " << flush;
		cin.get();
		exit(10);
	}
	m_choice = selection;
}
int Student::m_choice = 1;
int Student::Choice()
{
	return m_choice;
}
bool Student::operator()(const Student &s3, const Student &s4)
{
	if (m_choice == 1)
	{
		return (s3.First_Name() < s4.First_Name());
	}
	if (m_choice == 2)
	{
		if (s3.Last_Name() == s4.Last_Name())
			return (s3.First_Name() > s4.Last_Name());
		return (s3.Last_Name() < s4.Last_Name());
	}
	if (m_choice == 3)
	{
		return s3.Age() < s4.Age();
	}
	return false;
}