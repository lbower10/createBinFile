#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ass.h"
#include "ass.cpp"
using namespace std;

const int M = 3;
const int size = 50;
int main()
{
	Assessment r[M];
	ifstream in;
	ofstream binOut;
	const string fileName = "Big5Assessments.txt";
	//cout << sizeof(Results) << endl << endl;
	in.open(fileName.c_str(), ios::in);
	if(in.fail())
	{
		cout << "Failed" << endl;
		return 0;
	}
	
	string first, last;
	
	for(int i = 0; i < M; i++)
	{
		in >> r[i].firstName >> r[i].lastName >> r[i].age;
		for(int j = 0; j < size; j++)
		{
			in >> r[i].answers[j];
		}
	}
	
	in.close();
	
	for(int k = 0; k < M; k++)
	{
		cout << r[k].firstName << " " << r[k].lastName << " " << r[k].age << " ";
		for(int L = 0; L < size; L++)
		{
			cout << r[k].answers[L] << " ";
		}
		cout << endl;
	}
	
	binOut.open("threeAssessments.bin", ios::out | ios::binary);
	for(int y = 0; y < M; y++)
	{
		binOut.write( (char*)&r[y], sizeof(Assessment) );
	}
	binOut.close();
	
	
	cout << "Read from binary" << endl;
	
	ifstream inBin;
	inBin.open("Big5Assessments.bin", ios::in | ios::binary);
	for(int u = 0; u < M; u++)
	{
		inBin.read( (char*)&r[u], sizeof(Assessment) );
	}
	
	for(int p = 0; p < M; p++)
	{
		cout << r[p].firstName << " " << r[p].lastName << " " << r[p].age << endl;;
		for (int z = 0; z < 50; z++)
		{
			cout << r[p].answers[z] << " ";
		}
		cout << endl;
	}
	
	return 0;
}