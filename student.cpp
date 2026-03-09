/*
 * Course: C867 - Scripting and Programming - Applications
 * Language: C++
 * Student ID: 012862248
 * Name: Alec Okelberry
 * File: student.cpp
 */

#include "student.h"
#include <iostream>

// Constructor initializes all private variables
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;  // Using this-> to avoid shadowing
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}

// Accessors (simple returns, const for safety)
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }  // Pointer for efficiency
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Mutators (setters with this-> for clarity)
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print in exact format
void Student::print() const {
    std::cout << studentID << '\t' << "First Name: " << firstName << '\t'
         << "Last Name: " << lastName << '\t' << "Email: " << emailAddress << '\t'
         << "Age: " << age << '\t' << "daysInCourse: {"
         << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} ";

    std::cout << "Degree Program: ";
    
    switch (degreeProgram) {
        case SECURITY: std::cout << "Security"; break;
        case NETWORK:  std::cout << "Network";  break;
        case SOFTWARE: std::cout << "Software"; break;
    }
    std::cout << std::endl;
}
