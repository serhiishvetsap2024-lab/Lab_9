#include "IOS.h"
#include <iostream>
#include <algorithm>

IOS::IOS() {
    ios_.isEnterpriseSigned = false;
    ios_.deviceFamily = "Unknown";
}

IOS::~IOS() = default;

void IOS::input() {
    MobileOS::input();

    std::string temp;
    std::cout << "Is enterprise-signed? (yes/no): ";
    if (!std::getline(std::cin, temp)) return;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    ios_.isEnterpriseSigned = (temp == "yes" || temp == "y");

    std::cout << "Enter device family (may contain spaces): ";
    std::getline(std::cin, ios_.deviceFamily);
}

void IOS::print() const {
    std::cout << "------- iOS -------\n";
    MobileOS::print();
    std::cout << "Enterprise Signed: " << (ios_.isEnterpriseSigned ? "Yes" : "No") << "\n";
    std::cout << "Device Family: " << ios_.deviceFamily << "\n";
    std::cout << "Computed metric (user reach estimate): " << computeMetric() << "\n";
}

double IOS::computeMetric() const {
    
    return info_.userBaseMillions * (ios_.isEnterpriseSigned ? 1.05 : 1.0);
}
