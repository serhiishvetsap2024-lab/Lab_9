#include "AndroidOS.h"
#include <iostream>

AndroidOS::AndroidOS() {
    android_.vendor = "Unknown";
    android_.majorAPILevel = 0;
}

AndroidOS::~AndroidOS() = default;

void AndroidOS::input() {
    
    MobileOS::input();

    std::cout << "Enter Android vendor (may contain spaces): ";
    std::getline(std::cin, android_.vendor);

    std::string temp;
    while (true) {
        std::cout << "Enter major API level (non-negative integer): ";
        if (!std::getline(std::cin, temp)) return;
        try {
            int api = std::stoi(temp);
            if (api >= 0) {
                android_.majorAPILevel = api;
                break;
            }
            else {
                std::cout << "API level cannot be negative.\n";
            }
        }
        catch (...) {
            std::cout << "Invalid input. Enter an integer.\n";
        }
    }
}

void AndroidOS::print() const {
    std::cout << "----- Android OS -----\n";
    MobileOS::print();
    std::cout << "Vendor: " << android_.vendor << "\n";
    std::cout << "Major API Level: " << android_.majorAPILevel << "\n";
    std::cout << "Computed metric (user reach estimate): " << computeMetric() << "\n";
}

double AndroidOS::computeMetric() const {
    
    return info_.userBaseMillions * (1.0 + android_.majorAPILevel * 0.001);
}
