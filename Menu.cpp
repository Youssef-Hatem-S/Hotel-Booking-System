#include "Menu.h"
#include "Hotel.h"
#include "Room.h"
#include "Guest.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::string;

// ========== ENTRY ==========
void Menu::start() {
    mainMenu();
}

// ========== MAIN ROLE MENU ==========
void Menu::mainMenu() {
    int choice;
    do {
        cout << "\n===== Hotel Booking System =====\n";
        cout << "1. Admin\n";
        cout << "2. Guest\n";
        cout << "0. Exit\n";
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: adminMenu(); break;
            case 2: guestMenu(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ========== ADMIN MENU ==========
void Menu::adminMenu() {
    int choice;
    do {
        cout << "\n===== Admin Menu =====\n";
        cout << "1. Add Hotel\n";
        cout << "2. Add Room\n";
        cout << "3. View All Reservations\n";
        cout << "0. Back\n";
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: addHotel(); break;
            case 2: addRoom(); break;
            case 3: bookingSystem.listReservations(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ========== GUEST MENU ==========
void Menu::guestMenu() {
    int choice;
    do {
        cout << "\n===== Guest Menu =====\n";
        cout << "1. Search Hotels\n";
        cout << "2. Book Room\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. View Reservations\n";
        cout << "0. Back\n";
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: searchHotels(); break;
            case 2: bookRoom(); break;
            case 3: cancelReservation(); break;
            case 4: viewReservations(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ========== INPUT HELPERS ==========
void Menu::Getline(std::istream& in, std::string& out) {
    std::getline(in, out);
    if (!out.empty() && out.back() == '\r') out.pop_back();
}

int Menu::readInt(const std::string& prompt) {
    while (true) {
        cout << prompt;
        int x;
        if (cin >> x) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid integer.\n";
    }
}

double Menu::readDouble(const std::string& prompt) {
    while (true) {
        cout << prompt;
        double x;
        if (cin >> x) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid number.\n";
    }
}

std::string Menu::readLine(const std::string& prompt) {
    cout << prompt;
    string s;
    Getline(cin, s);
    return s;
}

// ========== ADMIN ACTIONS ==========
void Menu::addHotel() {
    string name = readLine("Hotel name: ");
    string location = readLine("Location: ");
    auto* h = new Hotel(name, location);
    bookingSystem.addHotel(h);
    cout << "Hotel \"" << name << "\" added.\n";
}

void Menu::addRoom() {
    string hotelName = readLine("Enter hotel name: ");
    Hotel* h = bookingSystem.searchHotel(hotelName);
    if (!h) {
        cout << "Hotel not found.\n";
        return;
    }

    int roomNum = readInt("Room number: ");
    double price = readDouble("Price: ");
    string type = readLine("Room type (Single/Double/Suite): ");

    h->addRoom(new Room(roomNum, price, type));
    cout << "Room " << roomNum << " added.\n";
}


// ========== GUEST ACTIONS ==========
void Menu::searchHotels() {
    string name = readLine("Enter hotel name: ");
    Hotel* h = bookingSystem.searchHotel(name);
    if (!h) {
        cout << "Hotel not found.\n";
        return;
    }
    h->listRooms();
}

void Menu::bookRoom() {
    string hotelName = readLine("Hotel name: ");
    Hotel* h = bookingSystem.searchHotel(hotelName);
    if (!h) {
        cout << "Hotel not found.\n";
        return;
    }

    string type = readLine("Room type wanted (Single/Double/Suite): ");

    int guestId = readInt("Guest ID: ");
    string guestName = readLine("Guest name: ");
    string phone = readLine("Phone: ");
    string checkIn = readLine("Check-in (YYYY-MM-DD): ");
    string checkOut = readLine("Check-out (YYYY-MM-DD): ");

    Guest g(guestId, guestName, phone);

    bookingSystem.bookRoom(g, hotelName, checkIn, checkOut, type);
}

void Menu::cancelReservation() {
    string hotelName = readLine("Hotel name: ");
    int resId = readInt("Reservation ID: ");
    bookingSystem.cancelReservation(resId, hotelName);
}

void Menu::viewReservations() {
    int guestId = readInt("Guest ID: ");
    bookingSystem.listReservationsForGuest(guestId);
}


