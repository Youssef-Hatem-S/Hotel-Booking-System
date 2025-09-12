#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Reservation.h"

class Room {
private:
    int number;
    double price;
    std::string type;
    std::vector<Reservation*> reservations;

public:
    Room(int num, double pr, const std::string& t);

    int getNumber() const { return number; }
    double getPrice() const { return price; }
    std::string getType() const { return type; }

    void addReservation(Reservation* r);
    bool isAvailable(const std::string& checkIn, const std::string& checkOut) const;
    bool removeReservation(int resId);
    void listReservations() const;

//    Room(const Room&) = delete;
//    Room& operator=(const Room&) = delete;
};

#endif