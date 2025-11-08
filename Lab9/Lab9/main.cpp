#include <iostream>
#include <vector>
#include <memory>
#include "MobileOS.h"
#include "AndroidOS.h"
#include "IOS.h"

int main() {
    std::cout << "Polymorphic Mobile OS demo (Android and iOS)\n";
    std::vector<std::unique_ptr<MobileOS>> systems;

    while (true) {
        std::cout << "\nChoose an action:\n";
        std::cout << "1 - Add Android OS\n";
        std::cout << "2 - Add iOS\n";
        std::cout << "3 - Print all\n";
        std::cout << "4 - Compute total metric\n";
        std::cout << "0 - Exit\n";
        std::cout << "Enter choice: ";
        std::string choice;
        if (!std::getline(std::cin, choice)) break;

        if (choice == "1") {
            auto a = std::make_unique<AndroidOS>();
            a->input();
            systems.push_back(std::move(a));
        }
        else if (choice == "2") {
            auto ios = std::make_unique<IOS>();
            ios->input();
            systems.push_back(std::move(ios));
        }
        else if (choice == "3") {
            std::cout << "\n--- All systems ---\n";
            for (size_t i = 0; i < systems.size(); ++i) {
                std::cout << "System #" << (i + 1) << ":\n";
                systems[i]->print();
                std::cout << "\n";
            }
        }
        else if (choice == "4") {
            double total = 0.0;
            for (const auto& s : systems) {
                total += s->computeMetric();
            }
            std::cout << "Total computed metric (sum of user reach estimates): " << total << " millions\n";
        }
        else if (choice == "0") {
            break;
        }
        else {
            std::cout << "Unknown option.\n";
        }
    }

    std::cout << "Exiting.\n";
    return 0;
}
