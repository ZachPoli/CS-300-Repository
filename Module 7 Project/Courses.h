#ifndef __PROJECT_TWO_COURSES_H
#define __PROJECT_TWO_COURSES_H

#include <stdexcept>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Course.h"

using namespace std;

class Courses
{
private:
	/// <summary>
	/// Memory storage for the Course objects
	/// </summary>
	vector<Course> courses;

	/// <summary>
	/// High level, non-implementation specific method for adding a course
	/// to the underlying datatype.
	/// </summary>
	/// <param name="course"></param>
	void addCourse(const Course course);

	/// <summary>
	/// Called by addCourse
	/// Appends a course to the end of the data type
	/// Wraps the data type implementation
	/// Should call addCourse instead of this
	/// </summary>
	/// <param name="course"></param>
	void append(const Course course) {
		courses.push_back(course);
	}

	/// <summary>
	/// Called by addCourse
	/// Inserts a course somewhere into the data type
	/// Wraps the data type implementation
	/// Should call addCourse instead of this
	/// </summary>
	/// <param name="position">index of insertion</param>
	/// <param name="course">the course object to insert</param>
	void insert(const size_t position, const Course course) {
		vector<Course>::iterator iter;
		iter = courses.begin() + position;
		courses.insert(iter, course);
	}

	/// <summary>
	/// Wraps the data type at() call
	/// Use this instead of accessing the datatype directly
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	Course at(const size_t index) const {
		return courses.at(index);
	}

	/// <summary>
	/// Performs a Binary Search of the data type
	/// The data type is expected to already be sorted
	/// Returns the midpoint regardless of found/not found
	/// in order to communicate the closest value
	/// The caller is responsible for checking the return value
	/// to determine a match or not. Caller should call getSize()
	/// before calling only call if > 0
	/// </summary>
	size_t binarySearch(const string key) const;

	/// <summary>
	/// Calls binarySearch and then checks the return value
	/// On match will return the course found
	/// On no match will return a default Course object
	/// </summary>
	Course findCourse(const string courseId) const;

	/// <summary>
	/// Splits a string into a vector<string> of tokens by a delimiter
	/// </summary>
	vector<string> splitString(const string input, const string delimiter) const;

public:
	/// <summary>
	/// Clear all the data.
	/// </summary>
	void clear() {
		courses.clear();
	}

	/// <summary>
	/// Initialize the Courses object from a CSV file
	/// </summary>
	void loadFromCSV(const string filename, const string deliminator = ",");

	/// <summary>
	/// Print a specific course and its Prerequisites.
	/// </summary>
	void printCourse(const string courseId) const;

	/// <summary>
	/// Print all courses by Id and Title in alphanumeric order.
	/// </summary>
	void printAll() const;

	/// <summary>
	/// Wraps the data type size() call
	/// Use this instead of accessing the datatype directly
	/// </summary>
	/// <returns></returns>
	size_t getSize() const {
		return courses.size();
	}
};

#endif