#include <iostream>
#include <sstream>		// required for string stream
#include <fstream>		// required for ifstream
#include <string>		// required for string
#include <cstdlib>		// required for atoi, atof
#include "BinarySearchTree.h"
#include "StudentData.h"
#include "SinglyLinkedList.h"

using namespace std;

void visit(int& someData)
	{
		someData=0;
	}

void print(int& someData)
{
	cout << someData << endl;
}

//Prototypes
//void readFile(StudentData* stu, BinarySearchTree<StudentData, int>& stu_tree);
void readFile(SinglyLinkedList<StudentData> stu, BinarySearchTree<StudentData, int>& stu_tree);


int main()
{
	SinglyLinkedList<StudentData> stu;
	BinarySearchTree<StudentData, int> stu_tree;

	// Read student info from a file
	readFile(stu, stu_tree);

	// Using inorder to traverse through the file
	cout << "Traversing throught the file using inorder\n";
	stu_tree.inorderTraverse(print);

	// Add a new student
	cout << "\n\n\nADD A NEW STUDENT\n";
	StudentData* moreStu = new StudentData(11112222, "New student", "New Major", 2.6, 124, 3, 14);
	stu.addTop(moreStu);

	stu_tree.add(stu.get_node_data(moreStu).getID(), stu.get_node_address(moreStu));

	// Delete a student
	cout << "\n\n\nDELETE A STUDENT\n";
	stu_tree.remove(11112222);

	cout << "\nFrom the tree: \n";
	stu_tree.print_tree();

	cout << "\nFrom the list:\n";
	cout << stu;

	/*
	StudentData* stu = new StudentData[10];
	BinarySearchTree<StudentData, int> stu_tree;
	bool tempBool = false;
	string format = "[ID,name,GPA,years studied, current units]";// to display format of data to user

	// Read student info from a file
	readFile(stu, stu_tree);

	// Using inorder to traverse through the file
	cout << "Traversing throught the file using inorder\n";
	stu_tree.inorderTraverse(print);

	// Add a new student
	cout << "\n\n\nADD A NEW STUDENT\n";
	StudentData* moreStu = new StudentData(11112222, "New student", "New Major", 2.6, 124, 3, 14);
	stu[9] = *moreStu;

	stu_tree.add(stu[4].getID(), (stu + 9));

	// Delete a student
	cout << "\n\n\nDELETE A STUDENT\n";
	stu_tree.remove(11112222);
	
	cout << "From the tree: \n";
	stu_tree.print_tree(); 

	cout << "From the array:\n";
	for (int i = 0; i < 10; i++)
	{
		cout << stu[i] << endl;
	}

	// Find a student using the key
	cout << "\n\n\nFIND AND DISPLAY STUDENT by KEY\n";
	tempBool = stu_tree.is_contained(20356325);

	if (tempBool == true)
	{
		StudentData* tempStu = nullptr;
		tempStu = stu_tree.getEntry_address(20356325);
		cout << *tempStu<<endl;
	}
	else
		cout << "Not exist\n";

	// Save to a file
	// The current problem with saving to a file, and display it to the screen is that it has the same format.
	// The purpose of saving a file is for future reading file to a tree again, so if it contains any others inrellevant info then not good
	// So I don't know how to have a different format for output file and display file

	cout << "\n\n\nSAVED DATA to FILE in Preorder\n";
	stu_tree.preorderTraverse(visit);
	ofstream outFile;
	outFile.open("StudentOut.txt");
	stu_tree.save_to_file(outFile);

	outFile.close();

	delete []stu;*/
	system("pause");
	return 0;
}


void readFile(SinglyLinkedList<StudentData> stu, BinarySearchTree<StudentData, int>& stu_tree)
{
	ifstream  inputFile;	// to hold the input file
	string    line;			// to temporarily hold each line of string from the file 
	StudentData* s;

	string id, n, m, gpa, credits, yr, curUnit;


	// Open the file
	inputFile.open("student.txt");

	if (!inputFile)
	{
		cout << "File not found\n";
	}
	else
	{
		while (getline(inputFile, line))	 // reads a line from the file
		{

			stringstream lineStream(line);   // transforms the line into a stream

			// get fields from the string stream; fields are separated by comma
			getline(lineStream, id, ',');
			getline(lineStream, n, ',');
			getline(lineStream, m, ',');
			getline(lineStream, gpa, ',');
			getline(lineStream, credits, ',');
			getline(lineStream, yr, ',');
			getline(lineStream, curUnit, ',');

			int id_convert = atoi(id.c_str());
			double gpa_convert = atof(gpa.c_str());
			double credits_convert = atof(credits.c_str());
			double yr_convert = atof(yr.c_str());
			double curUnit_convert = atof(curUnit.c_str());

			s = new StudentData(id_convert, n, m, gpa_convert, credits_convert, yr_convert, curUnit_convert);

			stu.addTop(s);

			stu_tree.add(id_convert, stu.get_node_address(s));

			delete s;
		}
		inputFile.close(); // Close file
	}
}

/*
void readFile(StudentData* stu, BinarySearchTree<StudentData, int>& stu_tree)
{
	ifstream  inputFile;	// to hold the input file
	string    line;			// to temporarily hold each line of string from the file 
	StudentData* s;
	int i = 0;
	
	string id, n, m, gpa, credits, yr, curUnit;


	// Open the file
	inputFile.open("student.txt");

	if (!inputFile)
	{
		cout << "File not found\n";
	}
	else
	{
		while (getline(inputFile, line))	 // reads a line from the file
		{

			stringstream lineStream(line);   // transforms the line into a stream

			// get fields from the string stream; fields are separated by comma
			getline(lineStream, id, ',');
			getline(lineStream, n, ',');
			getline(lineStream, m, ',');
			getline(lineStream, gpa, ',');
			getline(lineStream, credits, ',');
			getline(lineStream, yr, ',');
			getline(lineStream, curUnit, ',');

			int id_convert = atoi(id.c_str());
			double gpa_convert = atof(gpa.c_str());
			double credits_convert = atof(credits.c_str());
			double yr_convert = atof(yr.c_str());
			double curUnit_convert = atof(curUnit.c_str());

			s = new StudentData(id_convert, n, m, gpa_convert, credits_convert, yr_convert, curUnit_convert);

			*(stu+i)= *s;
			
			stu_tree.add(id_convert, (stu + i));

			delete s;
			i++;
		}
		inputFile.close(); // Close file
	}
}
*/