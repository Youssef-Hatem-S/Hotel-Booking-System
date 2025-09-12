
#include "BookingSystem.h"
#include <iostream>

void BookingSystem::addHotel(Hotel *h) {
    hotels[h->name] = h;
}

Hotel* BookingSystem::searchHotel(const std::string &name) {
    if(hotels.find(name) != hotels.end())
        return hotels[name];
    return nullptr;
}

BookingSystem::~BookingSystem() {
    for (auto& pair : hotels) {
        delete pair.second;
    }

    for (auto& pair : reservations) {
        delete pair.second;
    }
}

void BookingSystem::bookRoom(const Guest& guest,
                             const std::string& hotelName,
                             const std::string& checkIn,
                             const std::string& checkOut,
                             const std::string& type) {
    Hotel* h = searchHotel(hotelName);
    if (!h) {
        std::cout << "Hotel not found.\n";
        return;
    }

    Room* room = h->findAvailableRoom(type, checkIn, checkOut);
    if (!room) {
        std::cout << "No available " << type << " rooms for the given dates.\n";
        return;
    }

    Reservation* res = new Reservation(
            nextReservationId++, guest.getId(), guest.getName(), guest.getPhone(),
            room->getNumber(), checkIn, checkOut, hotelName);

    reservations[res->getId()] = res;
    room->addReservation(res);
    std::cout << "Reservation confirmed! ID: " << res->getId() << "\n";
}


void BookingSystem::cancelReservation(int resId, const std::string& hotelName) {
    auto resIt = reservations.find(resId);
    if (resIt == reservations.end()) {
        std::cout << "Reservation not found!\n";
        return;
    }

    Reservation* res = resIt->second;

    if (res->getHotelName() != hotelName) {
        std::cout << "Reservation " << resId << " is not associated with hotel " << hotelName << "!\n";
        return;
    }

    Hotel* hotel = searchHotel(hotelName);
    if (!hotel) {
        std::cout << "Hotel not found!\n";
        return;
    }

    Room* room = hotel->findRoomByNumber(res->getRoomNumber());
    if (!room) {
        std::cout << "Room not found in the specified hotel!\n";
        return;
    }

    if (room->removeReservation(resId)) {
        delete res;
        reservations.erase(resIt);
        std::cout << "Reservation " << resId << " cancelled and removed.\n";
    } else {
        std::cout << "Failed to remove reservation from room.\n";
    }
}

void BookingSystem::listReservations() const {
    if (reservations.empty()) {
        std::cout << "No reservations in the system.\n";
        return;
    }

    std::cout << "All reservations:\n";
    for (const auto &p : reservations) {
        const Reservation* r = p.second;
        std::cout << "ID: " << r->getId()
                  << " | Guest: " << r->getGuestName() << " (ID:" << r->getGuestId() << ")"
                  << " | Room: " << r->getRoomNumber()
                  << " | Dates: " << r->getCheckInDate() << " -> " << r->getCheckOutDate() << "\n";
    }
}

void BookingSystem::listReservationsForGuest(int guestId) const {
    bool found = false;
    for (const auto &p : reservations) {
        const Reservation* r = p.second;
        if (r->getGuestId() == guestId) {
            if (!found) {
                std::cout << "Reservations for guest ID " << guestId << ":\n";
                found = true;
            }
            std::cout << "ID: " << r->getId()
                      << " | Room: " << r->getRoomNumber()
                      << " | Dates: " << r->getCheckInDate() << " -> " << r->getCheckOutDate() << "\n";
        }
    }
    if (!found) {
        std::cout << "No reservations found for guest ID " << guestId << ".\n";
    }
}