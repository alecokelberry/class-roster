/*
 * Course: C867 - Scripting and Programming - Applications
 * Language: C++
 * Student ID: 012862248
 * Name: Alec Okelberry
 * File: roster.cpp
 */

#include "roster.h"
#include <iostream>
#include <sstream>

// Destructor releases all allocated memory
Roster::~Roster() {
    for (int i = 0; i < studentCount; ++i) {
        delete classRosterArray[i];  // Free each Student
    }
}

// Parse comma-separated row into Student parameters
void Roster::parse(const std::string& row) {
    std::istringstream iss(row);
    std::string studentID, firstName, lastName, emailAddress, degreeStr;
    int age, days1, days2, days3;

    getline(iss, studentID, ',');
    getline(iss, firstName, ',');
    getline(iss, lastName, ',');
    getline(iss, emailAddress, ',');
    iss >> age; iss.ignore();  // Ignore comma after int
    iss >> days1; iss.ignore();
    iss >> days2; iss.ignore();
    iss >> days3; iss.ignore();
    getline(iss, degreeStr);

    DegreeProgram degreeProgram;
    if (degreeStr == "SECURITY") degreeProgram = SECURITY;
    else if (degreeStr == "NETWORK") degreeProgram = NETWORK;
    else degreeProgram = SOFTWARE;  // Default for unknown

    add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
}

// Creates Student and stores in array
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    classRosterArray[studentCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    studentCount++;  // Increment count
}

// Remove by ID, shift array, error message if not found
void Roster::remove(std::string studentID) {
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            for (int j = i; j < studentCount - 1; ++j) {
                classRosterArray[j] = classRosterArray[j + 1];  // Shift left
            }
            classRosterArray[studentCount - 1] = nullptr;
            studentCount--;
            return;
        }
    }
    std::cout << "Student with ID " << studentID << " was not found." << std::endl;
}

// Loops and calls print() on each student
void Roster::printAll() const {
    for (int i = 0; i < studentCount; ++i) {
        classRosterArray[i]->print();
    }
}

// Calculates average days in course
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            double avg = (days[0] + days[1] + days[2]) / 3.0;
            std::cout << avg << std::endl;
            return;
        }
    }
    // No output if not found
}

// Checks emails for @ . no space
void Roster::printInvalidEmails() const {
    for (int i = 0; i < studentCount; ++i) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
            std::cout << email << std::endl;
        }
    }
}

// Filters and prints matching
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
