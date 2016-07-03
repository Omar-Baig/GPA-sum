//Programmed By: Omar Baig
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
//All funcitons used in the program
void initialize(int& countFemale, int& countMale, float& sumFemaleGPA, float& sumMaleGPA, float& avgMGrade, float& avgFGrade)
{	//initializing all variables in this function to 0.
	countFemale = 0;
	countMale = 0;
	sumFemaleGPA = 0;
	sumMaleGPA = 0;
	avgMGrade = 0;
	avgFGrade = 0;
}
void openFiles(ifstream& inData, ofstream& outData)
{
	//open files to read from them.
	inData.open("project01_Part02Data.txt");
	outData.open("Output.txt");
	//set to two decimals
	outData << fixed << showpoint << setprecision(2);
}
void sumGrades(istream& inData, ostream& outData, int& countFemale, int& countMale, float& sumFemaleGPA, float& sumMaleGPA, char& gender, float& gpa)
{
	while (inData) { // while loop

		inData >> gender;
		inData >> gpa;

		if (gender == 'f') {
			sumFemaleGPA += gpa;
			countFemale++;
		}
		else if (gender == 'm') {
			sumMaleGPA += gpa;
			countMale++;
		}
	}
	
}	//Gets the sum of the gpa's and the number of males and females.
void averageGrade(istream& inData, float& avgMGrade, float& avgFGrade, float sumMaleGPA, int countMale, float sumFemaleGPA, int countFemale)
{
		avgMGrade = sumMaleGPA / countMale;
		avgFGrade = sumFemaleGPA / countFemale;
}	//Average grade formulas
void printResults(float sumMaleGPA, float sumFemaleGPA, float avgFGrade, float avgMGrade, int countMale, int countFemale, ostream& outData)
{	//Function will print everything to the output.txt file
	outData << "Sum Female GPA: " << sumFemaleGPA << endl;
	outData << "Sum Male GPA: " << sumMaleGPA << endl;
	outData << "Female count: " << countFemale << endl;
	outData << "Male count: " << countMale << endl;
	outData << "Average female GPA: " << avgFGrade << endl;
	outData << "Average male GPA: " << avgMGrade << endl;
}
int main()
{
	char gender;
	float gpa, sumFemaleGPA, sumMaleGPA, avgMGrade, avgFGrade;
	ifstream inData;
	ofstream outData;
	int countFemale, countMale;
	//Calling all functions
	openFiles(inData, outData);
	initialize(countFemale, countMale, sumFemaleGPA, sumMaleGPA, avgMGrade, avgFGrade);
	sumGrades(inData, outData, countFemale, countMale, sumFemaleGPA, sumMaleGPA, gender, gpa); 
	averageGrade(inData, avgMGrade, avgFGrade, sumMaleGPA, countMale, sumFemaleGPA, countFemale);
	printResults(sumMaleGPA, sumFemaleGPA, avgMGrade, avgFGrade, countMale, countFemale, outData);
	//Close files at the end of the main function
	inData.close();
	outData.close();
}