/*
 * Course: C867 - Scripting and Programming - Applications
 * Language: C++
 * Student ID: 012862248
 * Name: Alec Okelberry
 * File: roster.h
 */

#pragma once

#include "student.h"

class Roster {
private:
    // Array of pointers to hold Student objects
    Student* classRosterArray[5]{};
    int studentCount = 0;  // Tracks number of students

public:
    Roster() = default;
    ~Roster();  // Destructor to release memory

    void parse(const std::string& row);  // Parse data string

    // Add function with exact signature
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    void remove(std::string studentID);  // Remove by ID, error if not found
    void printAll() const;  // Loop and print each
    void printAverageDaysInCourse(std::string studentID) const;  // Average of 3 days
    void printInvalidEmails() const;  // Check @ . no space
    void printByDegreeProgram(DegreeProgram degreeProgram) const;  // Filter by program
};
