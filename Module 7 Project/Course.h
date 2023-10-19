#ifndef __PROJECT_TWO_COURSE_H  // Check if the header is not already included
#define __PROJECT_TWO_COURSE_H  // Define it so it can't be included again

// Include necessary headers and libraries
#include <string>
#include <iostream>
#include <vector>

using namespace std;  // Use the standard namespace

class Course  // Define the Course class
{
private:  // Private attributes
	string id;  // Course identifier, like "CSCI100"
	string title;  // Course title, like "Introduction to Computer Science"
	vector<Course> prerequisites;  // A vector to hold prerequisite courses

public:
	// Default constructor with no arguments
	Course() {
	}

	// Getter method to get the course ID
	string getId() const {
		return this->id;
	}

	// Getter method to get the course title
	string getTitle() const {
		return this->title;
	}

	// Setter method to set the course ID
	void setId(const string id) {
		this->id = id;
	}

	// Setter method to set the course title
	void setTitle(const string title) {
		this->title = title;
	}

	// Method to add a course to the list of prerequisites
	void addPrerequisite(const Course course) {
		prerequisites.push_back(course);
	}

	// Method to display course details to standard output
	void print() const;
};

#endif  // End of the header file inclusion guard
