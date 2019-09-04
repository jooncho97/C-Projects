#ifndef STUDENT_CLASS
#define STUDENT_CLASS 
#include <iostream>
#include <string>
using namespace std;

struct Student
{
	//overloaded input & output operators
	friend ostream& operator<<(std::ostream & os, const Student & s);
	friend istream& operator>>(std::istream & is, Student & s);
private:
	string m_first_name, m_last_name;
	int m_age;
	float m_gpa;
	static int m_choice;
protected:
	//Input and Output
	void Read(std::istream &is); // Mutator
	void Write(std::ostream &os) const; // Accessor
public:
	//Constructor & Copy Constructor
	Student();
	Student(string first_name, string last_name, int age, float GPA);
	//Accessor & Mutator
		//For m_name
	void First_Name(string first_name); 
	void Last_Name(string last_name);
	string First_Name() const; 
	string Last_Name() const;
		//For m_age
	void Age(int Age); 
	int Age() const; 
		//For m_ssn
	void GPA(float gpa);
	float GPA() const;
	static void Choice(int selection);
	static int Choice();
	bool operator()(const Student &s3, const Student &s4);
};
#endif