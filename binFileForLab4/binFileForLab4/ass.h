#ifndef BIG5ASSESSMENT_H
#define BIG5ASSESSMENT_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MIN_AGE = 0;
const int NUM_QUESTIONS = 50;
const int NUM_TRAITS = 5;

enum Traits{
	EXTROVERSION, AGREEABLNESS, CONSCIENT,
	NEUROTICISM, OPENTOEXP
};

class Assessment
{
public:
// Constructors & destructor
Assessment();
Assessment(string f, string L, int a, int q[]);
Assessment(const Assessment& a);
virtual ~Assessment() {}

// Set and get functions for private data
void setFirst(string f){
	strcpy(firstName, f.c_str());
}

const char* getFirst() const{
	return firstName;
}

void setLast(string L){
	strcpy(lastName, L.c_str());
}

const char* getLast() const{
	return lastName;
}

void setAge(int a){
	if(a < MIN_AGE)
		age = MIN_AGE;
	else
		age = a;
}

int getAge() const{
	return age;
}

void setAnswer(int a,int index){
	answers[index] = a;
}

int getAnswers(int i) const{
	return answers[i];
}

void setTraits(double nT[]){
	for(int i = 0; i < NUM_TRAITS; i++)
	{
		normTraits[i] = nT[i];
	}
}

const double* getTraits() const{
	return normTraits;
}
void setKey(){
	char temp1[40];
	char temp2[40];
	strcpy(temp1, firstName);
	strcpy(temp2, lastName);
	makeLower(temp1);
	makeLower(temp2);
	
	strcpy(key, temp2);
	strcat(key, temp1);
	cout << key << endl;
}
const char* getKey(){
	return key;
}
void makeLower(char temp[]);
void makeLowUpFirst(char temp[]);
void calcNormTraits(double trait[]);

// Operators 
Assessment& operator=(const Assessment& a);
friend bool operator<(Assessment a1, Assessment a2);
friend bool operator==(Assessment a1, Assessment a2);
friend ostream& operator<<(ostream& out, const Assessment& a);
istream& read(istream& in);
ostream& write( ostream& outBin );
friend istream& operator>>(istream& inStream, Assessment& a);

//private:
char firstName[40];
char lastName[40];
int age;
int answers[NUM_QUESTIONS];
double normTraits[NUM_TRAITS];
char key[81];
};



#endif