/*
 * Course: C867 - Scripting and Programming - Applications
 * Language: C++
 * Student ID: 012862248
 * Name: Alec Okelberry
 * File: main.cpp
 */

#include "roster.h"
#include <iostream>

// Main demonstrates all functionality in exact order
int main() {
    // Print course title, language, ID, and name
    std::cout << "Course: Scripting and Programming - Applications (C867)" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: 012862248" << std::endl;
    std::cout << "Name: Alec Okelberry" << std::endl;
    std::cout << std::endl;

    // Instantiate Roster
    Roster classRoster;

    // Student data table with intentional email errors
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Alec,Okelberry,aokelb2@wgu.edu,24,30,40,50,SOFTWARE"
    };

    // Parse student data table and add all students
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }
    std::cout << std::endl;

    // Execute pseudo-code in exact order
    std::cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Displaying invalid emails:" << std::endl;
    classRoster.printInvalidEmails();
    std::cout << std::endl;

    // Loop through classRosterArray via IDs (private array → extract from data)
    std::cout << "Displaying average days in course for each student:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        size_t commaPos = studentData[i].find(',');
        std::string id = studentData[i].substr(0, commaPos);
        classRoster.printAverageDaysInCourse(id);
    }
    std::cout << std::endl;

    std::cout << "Displaying students in SOFTWARE degree program:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << std::endl;

    classRoster.remove("A3");
    std::cout << "Displaying all students after removing A3:" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    classRoster.remove("A3");  // Should print "not found"
    std::cout << std::endl;

    // Destructor auto-calls to release memory
    return 0;
}
