#include "MobileOS.h"
#include <limits>

MobileOS::MobileOS() {
    info_.name = "Unknown";
    info_.version = "0.0";
    info_.releaseYear = 0;
    info_.userBaseMillions = 0.0;
}

MobileOS::MobileOS(const Info& info) : info_(info) {}

MobileOS::~MobileOS() = default;

void MobileOS::input() {
    std::string temp;
    std::cout << "Enter OS name: ";
    std::getline(std::cin, info_.name);

    std::cout << "Enter OS version: ";
    std::getline(std::cin, info_.version);

   
    while (true) {
        std::cout << "Enter release year (e.g. 2008): ";
        if (!std::getline(std::cin, temp)) return;
        try {
            int year = std::stoi(temp);
            if (year >= 1970 && year <= 2100) {
                info_.releaseYear = year;
                break;
            }
            else {
                std::cout << "Invalid year. Enter a number between 1970 and 2100.\n";
            }
        }
        catch (...) {
            std::cout << "Invalid input. Please enter an integer.\n";
        }
    }

    
    while (true) {
        std::cout << "Enter user base (millions, e.g. 1500.5): ";
        if (!std::getline(std::cin, temp)) return;
        try {
            double ub = std::stod(temp);
            if (ub >= 0.0) {
                info_.userBaseMillions = ub;
                break;
            }
            else {
                std::cout << "User base cannot be negative.\n";
            }
        }
        catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
}

void MobileOS::print() const {
    std::cout << "OS Name: " << info_.name << "\n";
    std::cout << "Version: " << info_.version << "\n";
    std::cout << "Release Year: " << info_.releaseYear << "\n";
    std::cout << "User base (millions): " << info_.userBaseMillions << "\n";
}

double MobileOS::computeMetric() const {
    
    return info_.userBaseMillions;
}
