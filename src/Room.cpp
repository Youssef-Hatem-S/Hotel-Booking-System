#include "Room.h"
#include <iostream>
#include <algorithm>

Room::Room(int num, double pr, const std::string& t)
        : number(num), price(pr), type(t) {}

void Room::addReservation(Reservation* r) {
    reservations.push_back(r);
}

bool Room::isAvailable(const std::string& checkIn, const std::string& checkOut) const {
    for (const Reservation* r : reservations) {
        if (checkIn < r->getCheckOutDate() && checkOut > r->getCheckInDate()) {
            return false;
        }
    }
    return true;
}

bool Room::removeReservation(int resId) {
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if ((*it)->getId() == resId) {
            reservations.erase(it);
            return true;
        }
    }
    return false;
}