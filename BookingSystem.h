#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <unordered_map>
#include <string>
#include "Hotel.h"
#include "Reservation.h"
#include "Guest.h"

class BookingSystem {
private:
    std::unordered_map<std::string, Hotel *> hotels;
    std::unordered_map<int, Reservation *> reservations;
    int nextReservationId = 1;

public:
    BookingSystem() = default;
    ~BookingSystem();
    void addHotel(Hotel *h);
    Hotel *searchHotel(const std::string &name);
    void bookRoom(const Guest& guest,
                  const std::string& hotelName,
                  const std::string& checkIn,
                  const std::string& checkOut,
                  const std::string& type);
    void cancelReservation(int resId, const std::string& hotelName);
    void listReservations() const;
    void listReservationsForGuest(int guestId) const;

//    BookingSystem(const BookingSystem&) = delete;
//    BookingSystem& operator=(const BookingSystem&) = delete;
};

#endif