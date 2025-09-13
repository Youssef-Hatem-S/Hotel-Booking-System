#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
private:
    int id;
    int guestId;
    std::string guestName;
    std::string phone;
    int roomNumber;
    std::string checkInDate;
    std::string checkOutDate;
    std::string hotelName;

public:
    Reservation(int id, int guestId, const std::string& gName,
                const std::string& ph, int rNum,
                const std::string& in, const std::string& out,
                const std::string& hotel);

    int getId() const { return id; }
    int getGuestId() const { return guestId; }
    std::string getGuestName() const { return guestName; }
    std::string getPhone() const { return phone; }
    int getRoomNumber() const { return roomNumber; }
    std::string getCheckInDate() const { return checkInDate; }
    std::string getCheckOutDate() const { return checkOutDate; }
    std::string getHotelName() const { return hotelName; }
};

#endif