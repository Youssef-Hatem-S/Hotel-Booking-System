#include "Guest.h"
#include <iostream>

Guest::Guest(int id, const std::string& n, const std::string& ph)
        : id(id), name(n), phone(ph) {}

void Guest::print() const {
    std::cout << "Guest ID: " << id
              << ", Name: " << name
              << ", Phone: " << phone << std::endl;
}
