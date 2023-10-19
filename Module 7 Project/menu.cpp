#include "menu.h"
#include "Course.h"
#include "Courses.h"

/// <summary>
/// Print menu options to stdout
/// </summary>
/// <param name=""></param>
void printMenu(void) {
	cout << "Menu:" << endl;
	cout << "  1. Load CSV File.(For this project please enter \"Advising Program Input.csv\")" << endl;
	cout << "  2. Print Course List." << endl;
	cout << "  3. Print Course." << endl;
    cout << "  9. Exit" << endl << endl;
	cout << "What would you like to do? ";
}

/// <summary>
/// Call various functions based on the user's choice.
/// </summary>
/// <param name="choice"></param>
/// <param name="courses"></param>
void handleChoice(int choice, Courses& courses) {
    switch (choice) {
    case 1: // load file
        {
            string filename;
            auto state = cin.exceptions();  // setup exception handling for stdin
            cin.exceptions(std::istream::failbit | state);
            cout << "Please enter the name of the data file to load." << endl;
            cin.ignore();

            // if already loaded discard previous and start another 
            if (courses.getSize() > 0) {
                courses.clear();
            }

            try {
                getline(cin, filename);     // get user input of filename
                courses.loadFromCSV(filename);
            }
            catch (exception ex) {
                cout << ex.what() << endl;  // display what happened to console
            }

            cin.exceptions(state);          // restore previous exception settings
        }
        break;

    case 2: // print all courses with id and title in alphanumeric order
        cout << "Here is a list of all the courses:" << endl << endl;
        courses.printAll();
        break;

    case 3: // print one course and its prerequisites
        {
            string courseId;
            cout << "What course do you want to know about?(i.e. CSCI100) ";
            cin >> courseId;
            courses.printCourse(courseId);
        }
        break;

    case 9: // exit program
        cout << "Have a nice day professor!" << endl;
        break;

    default: // invalid choice
        cout << choice << "error invalid input." << endl << endl;
        break;
    }
}

void commandLoop(void) {
	int choice = 0;
    Courses courses; // declaring here allocates the memory for the lifetime of the loop

    cout << "Module 7 Course Planner Project." << endl;

	while (choice != 9) { // while not exit command
        cout << endl;
		printMenu();
		cin >> choice; // wait for user input
		handleChoice(choice, courses);
	}
}