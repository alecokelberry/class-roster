/*
 * Course: C867 - Scripting and Programming - Applications
 * Language: C++
 * Student ID: 012862248
 * Name: Alec Okelberry
 * File: student.h
 */

#pragma once

#include "degree.h"
#include <string>

class Student {
private:
    // Private variables for student data
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];  // Array for 3 course days
    DegreeProgram degreeProgram;

public:
    // Constructor with all parameters from data table
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Accessors (getters) for each variable
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int* getDaysInCourse() const;  // Returns pointer to avoid copying array
    DegreeProgram getDegreeProgram() const;

    // Mutators (setters) for each variable
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print
    void print() const;
};
