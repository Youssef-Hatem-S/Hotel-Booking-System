#include "Reservation.h"

Reservation::Reservation(int id, int gId, const std::string& gName,
                         const std::string& ph, int rNum,
                         const std::string& in, const std::string& out,
                         const std::string& hotel)
        : id(id), guestId(gId), guestName(gName), phone(ph),
          roomNumber(rNum), checkInDate(in), checkOutDate(out),
          hotelName(hotel) {}