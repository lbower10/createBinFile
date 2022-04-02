/*
 * File: big5Assessment.cpp
 * Author: Logan Bowers
 * Description: Contains code for functions used to operate
 * on a Big 5 Assessment class
 */

#include "ass.h"
#include <cstring>
#include <iostream>
using namespace std;


/*
 * operator<: compares first name concatenated to
 * 	last name of two assessments
 * Parameters: Two assessments
 * Returns: true if if a1 firstName < a2 firstName,
 * else false
 */
bool operator<(Assessment a1, Assessment a2)
{
	return (a1.firstName < a2.firstName);
}

/*
 * operator==: compares first name concatenated
 * 	to last name of two assessments
 * Parameters: Two assessments
 * Returns: True if first names are ==, else false
 */
bool operator==(Assessment a1, Assessment a2)
{
	return (a1.firstName == a2.firstName);
}

/*
 * operator<<: Prints an assessment
 * Parameters: output stream ref. out, const Assessment
 * 	ref. a
 * Returns: output stream ref. out
 */
ostream& operator<<(ostream& out, const Assessment& a)
{
	out << a.firstName << " " << a.lastName << endl;

	out << a.age << endl;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		out << a.answers[i] << " ";
	}
	out << endl;
	return out;
}


// Default constructor
Assessment::Assessment()
{
	firstName[0] = '\0';
	lastName[0] = '\0';
	age = 0;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		answers[i] = 0;
	}
}

// Four argument constructor
Assessment::Assessment(string f, string L, int a, int q[])
{
	setFirst(f);
	setLast(L);
	setAge(a);
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		setAnswer(q[i], i);
	}
}


// Copy constructor
Assessment::Assessment(const Assessment& a)
{
	strcpy(this->firstName, a.firstName);
	strcpy(this->lastName, a.lastName);
	this->age = a.age;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		this->answers[i] = a.answers[i];
	}
}


// Assignment operator
Assessment& Assessment::operator=( const Assessment& a)
{
	strcpy(this->firstName, a.firstName);
	strcpy(this->lastName, a.lastName);
	this->age = a.age;
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		this->answers[i] = a.answers[i];
	}
	
	return *this;
}


istream& Assessment::read(istream& inBin)
{
	inBin.read( (char*)this, sizeof(Assessment) );

	return inBin;
}


ostream& Assessment::write( ostream& outBin )  
{
	outBin.write( (char*)this, sizeof(Assessment) );
   return outBin;
}


istream& operator>>( istream& in,  Assessment& a)
{
	cout << "Last name: ";
	in >> a.firstName;
	cout << "First name: ";
	in >> a.lastName;
	
	
	cout << "Age: ";
	in >> a.age;
	cout << "50 question answers: ";
	for(int i = 0; i < NUM_QUESTIONS; i++)
	{
		in >> a.answers[i];
	}

	return in;
}