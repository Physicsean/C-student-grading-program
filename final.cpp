// Project title: Student Grading Program
// Project Description: This program ??
// Programmer: Caged Animals and ???
// Date last modified:12/09/18

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<ctime>
#include<fstream>
using namespace std;

// Function prototypes
void banner();


int main()
{

	banner();
	cout << "\n\n Where is the worth of each course part stored?" <<
		"\n  [I will skip initial white space, filename may contain spaces]: ";

	// Open the file
	string fileName;
	ifstream infile; // define file stream object called infile

	// Get the filename for the syllabus from the user
	cin >> fileName;

	infile.open(fileName); // open the file

	// Check to make sure filename correct
	while (infile.fail())
	{
		cout << "\n\n Unable to Open " << fileName;
		cout << "\n\n  Please enter the right file name for the syllabus: ";
		cin >> fileName;
		infile.open(fileName);
	}

	// Goal: figure out how many assignments are on the syllabus
	// count the number of sections (divided by white space) in the file
	// and divide by 2 to find out how many assignments are on the syllabus.
	// You'll need the number of assignments throughout the rest of the program.

	string file_section;
	int assignments = 0;
	while (infile >> file_section)
	{
		assignments++;
	}
	assignments /= 2;

	cout << "\n\n I am getting the answer key from " << fileName <<
		"\n  This course has " << assignments << " parts";

	// close the file, then re-open it to read it all over again
	infile.close();
	infile.open(fileName);

	// Now create variables where each assignment and grade weight from the syllabus will be held
	// Also create a variable to put the percent signs in the file

	string assignment1, assignment2, assignment3, assignment4, assignment5, assignment6, assignment7;
	int weight1, weight2, weight3, weight4, weight5, weight6, weight7;
	char percent;

	// Using the number of assignments found earlier in the program,
	// assign each assignment and it's weight to the 
	// corresponding variables. Take up to 6 assignments.

	for (int part = 0; part < assignments; part++)
	{
		if (part == 0)
		{
			infile >> assignment1;
			infile >> weight1;
			infile >> percent;
		}
		else if (part == 1)
		{
			infile >> assignment2;
			infile >> weight2;
			infile >> percent;
		}
		else if (part == 2)
		{
			infile >> assignment3;
			infile >> weight3;
			infile >> percent;
		}
		else if (part == 3)
		{
			infile >> assignment4;
			infile >> weight4;
			infile >> percent;
		}
		else if (part == 4)
		{
			infile >> assignment5;
			infile >> weight5;
			infile >> percent;
		}
		else if (part == 5)
		{
			infile >> assignment6;
			infile >> weight6;
			infile >> percent;
		}
		else if (part == 6)
		{
			infile >> assignment7;
			infile >> weight7;
			infile >> percent;
		}
		else
			break;
	}

	/* This code was used by programmer to check if information assigned correctly to the variables
	cout << "\nassignment1: " << assignment1 << endl <<
		"\nweight1: " << weight1 << endl <<
		"\nassignment2: " << assignment2 << endl <<
		"\nweight2: " << weight2 << endl <<
		"\nassignment3: " << assignment3 << endl <<
		"\nweight3: " << weight3 << endl <<
		"\nassignment4: " << assignment4 << endl <<
		"\nweight4: " << weight4 << endl <<
		"\nassignment5: " << assignment5 << endl <<
		"\nweight5: " << weight5 << endl;
	*/

	// Close the file
	infile.close();

	// Now find out how many students the user wants to get grades for.

	cout << "\n\n How many students do you have? ";
	int numStudents;
	cin >> numStudents;

	// Create variables to hold each student's name and grade. Takes up to 3 students

	string student1Name, student2Name, student3Name;
	int student1grade1, student1grade2, student1grade3, student1grade4, student1grade5, student1grade6, student1grade7;
	int student2grade1, student2grade2, student2grade3, student2grade4, student2grade5, student2grade6, student2grade7;
	int student3grade1, student3grade2, student3grade3, student3grade4, student3grade5, student3grade6, student3grade7;

	// Using the number of students supplied by the user create a for loop that will 
	// read information from each student's file

	for (int num = 1; num <= numStudents; num++)
	{
		// To get the file name, concatenate the file name pieces with the number pertaining to each
		// student
		fileName = "Student#" + to_string(num) + ".txt";

		// Then open that file that is specific to that student
		// cout << "\nfilename is: " << fileName; // Used by programmer to make sure working correctly
		infile.open(fileName);

		// for student number 1 get the students full name using getline
		// then get each student's grade. Only get as many grades as there are assignments on the syllabus
		if (num == 1)
		{
			getline(infile, student1Name);
			// cout << "\nStudent1Name: " << student1Name << endl; Used by programmer to make sure working correctly
			for (int part = 0; part < assignments; part++)
			{
				if (part == 0)
				{
					infile >> student1grade1;
					// used by programmer to watch loop run
					// cout << "\nstudent1grade1: " << student1grade1 << endl;
				}
				else if (part == 1)
				{
					infile >> student1grade2;
					// used by programmer to watch loop run
					// cout << "\nstudent1grade2: " << student1grade2 << endl;
				}
				else if (part == 2)
					infile >> student1grade3;
				else if (part == 3)
					infile >> student1grade4;
				else if (part == 4)
					infile >> student1grade5;
				else if (part == 5)
					infile >> student1grade6;
				else if (part == 6)
					infile >> student1grade7;
			}
		}

		// This is the code to get the name and grades for the second student
		else if (num == 2)
		{
			getline(infile, student2Name);
			// Used by programmer to make sure working correctly
			// cout << "\nStudent2Name: " << student2Name << endl;
			for (int part = 0; part < assignments; part++)
			{
				if (part == 0)
				{
					infile >> student2grade1;
					// Used by programmer to make sure working correctly
					// cout << "\nstudent2grade1: " << student1grade1 << endl;
				}

				else if (part == 1)
					infile >> student2grade2;
				else if (part == 2)
					infile >> student2grade3;
				else if (part == 3)
					infile >> student2grade4;
				else if (part == 4)
					infile >> student2grade5;
				else if (part == 5)
					infile >> student2grade6;
				else if (part == 6)
					infile >> student2grade7;
			}
		}
		// This is the code to get the name and grades for the third student
		else if (num == 3)
		{
			getline(infile, student3Name);
			for (int part = 0; part < assignments; part++)
			{
				if (part == 0)
					infile >> student3grade1;
				else if (part == 1)
					infile >> student3grade2;
				else if (part == 2)
					infile >> student3grade3;
				else if (part == 3)
					infile >> student3grade4;
				else if (part == 4)
					infile >> student3grade5;
				else if (part == 5)
					infile >> student3grade6;
				else if (part == 6)
					infile >> student3grade7;
			}
		}
		infile.close(); // each time you run the loop need to close the file. 
		// Will re-open a new file for the next student at the next iteration of the loop
		// cout << endl << fileName << " closed\n"; // used by programmer to see if this part ran
	}



	// Used by programmer to see if variables assigned correctly
	cout << "\n\nHere are the information collected from the files so far: ";
	cout << "\nstudent1Name: " << student1Name << endl;
	cout << "student1grade1: " << student1grade1 << endl;
	cout << "student1grade2: " << student1grade2 << endl;
	cout << "student1grade3: " << student1grade3 << endl;
	cout << "student1grade4: " << student1grade4 << endl;
	cout << "student1grade5: " << student1grade5 << endl;

	cout << "student2Name: " << student2Name << endl;
	cout << "student2grade1: " << student2grade1 << endl;
	cout << "student2grade2: " << student2grade2 << endl;
	cout << "student2grade3: " << student2grade3 << endl;
	cout << "student2grade4: " << student2grade4 << endl;
	cout << "student2grade5: " << student2grade5 << endl;


	cin.ignore();
	cin.get();

	return 0;
}

// function for the banner
void banner()
{
	cout << "\n\t\tStudent Grading Program";
	cout << "\n\t\tBy The Caged Animals (Kay Sweeney, Sean Bradley) and ??? " << endl;
}

