#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <unordered_map>
#include "Room.h"

class Hotel {
public:
    std::string name;
    std::string location;
    std::unordered_map<int, Room*> roomsMap;

    ~Hotel();
    Hotel(std::string n, std::string loc);
    void addRoom(Room* r);
    Room* findAvailableRoom(const std::string& type,
                            const std::string& checkIn,
                            const std::string& checkOut);
    Room* findRoomByNumber(int roomNumber);
    void listRooms() const;


};

#endif