//==============================================================
// Filename : main.cpp
// Authors : Jan Sampol and Tesea Edo
// Group : 7
// License : N.A. or open source license like LGPL
// Description : Imlementation of the class and display of all its attributes                 
//==============================================================

#include "../include/person.h"
#include <iostream>

int main() {

    std::string fName, lName;
    int birthDay, birthMonth, birthYear;

  // Collect user data
    std::cout << "=== Patient Information Entry ===" << std::endl;

    std::cout << "Enter your first name: ";
    std::getline(std::cin, fName);

    std::cout << "Enter your last name: ";
    std::getline(std::cin, lName);

    std::cout << "Enter your birth date (day month year, e.g., 16 6 1990): ";
    std::cin >> birthDay >> birthMonth >> birthYear;

    Person person(fName, lName, birthDay, birthMonth, birthYear);
    
    // Show the data of the patient
    std::cout << "\n === Patient information === \n" << std::endl;
    std::cout << "First Name: " << person.getFirstName() << std::endl; // Show name
    std::cout << "Last Name: " << person.getLastName() << std::endl; // Show surname
    std::cout << "Date of Birth: " << person.getBirthDay() << "/" 
              << person.getBirthMonth() << "/" << person.getBirthYear() << std::endl; // Show date of birth
    std::cout << "Age: " << person.getAge() << std::endl; // Show age
    std::cout << "Maximum Heart rate: " << person.calculateMaximumHeartRate() << "bpm \n" << std::endl; // Show MHR
    std::cout << "Target Heart Rate: from "<< person.calculateTargetHeartRate().first << "bpm to " 
              << person.calculateTargetHeartRate().second << "bpm \n" << std::endl; // Show THR

    return 0;
}