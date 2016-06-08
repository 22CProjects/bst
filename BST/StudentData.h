#ifndef _STUDENT_DATA
#define _STUDENT_DATA

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::ostream;

class StudentData
{
	private:
		int    ID;
		string name;
		string major;
		double GPA;
		double total_credits;
		double year_studied;
		double current_units;

	public:
		StudentData() :ID(0), name(""), major(""), GPA(0.0), total_credits(0.0), year_studied(0.0), current_units(0.0) {}
		StudentData(int id, string n, string m, double gpa, double credits, double yr, double curUnit) :
			ID(id), name(n), major(m), GPA(gpa), total_credits(credits), year_studied(yr), current_units(curUnit) {}

		int getID() { return ID; }

		StudentData& operator=(const StudentData& student)
		{
			ID = student.ID;
			name = student.name;
			major = student.major;
			GPA = student.GPA;
			total_credits = student.total_credits;
			year_studied = student.year_studied;
			current_units = student.current_units;
			return *this;
		}

		friend ostream & operator<<(ostream& output, const StudentData& student);
};
#endif // !_STUDENT_DATA


ostream& operator<<(ostream& output, const StudentData& student)
{
	output << student.ID << "," << student.name << "," <<","<<student.major<<","<< student.total_credits << "," << student.year_studied << "," << student.current_units;
	return output;
}

/*<< "ID: " << student.ID << " | Name: " << student.name << "\n"
		<< "\tMajor: " << student.major << " |  GPA: " << student.GPA << " |  Total Credits: " << student.total_credits << "\n"
		<< "\tYears at college: " << student.year_studied << " |  Current Units: " << student.current_units << "\n\n";*/