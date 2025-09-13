#ifndef MENU_H
#define MENU_H

#include "BookingSystem.h"

class Menu {
public:
    Menu() : bookingSystem() {}
    void start();

private:
    BookingSystem bookingSystem;

    void mainMenu();
    void adminMenu();
    void guestMenu();

    static void Getline(std::istream& in, std::string& out);
    static int readInt(const std::string& prompt);
    static double readDouble(const std::string& prompt);
    static std::string readLine(const std::string& prompt);

    void addHotel();
    void addRoom();

    void bookRoom();
    void cancelReservation();
    void searchHotels();
    void viewReservations();

};

#endif
