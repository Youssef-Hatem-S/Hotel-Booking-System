#include "Hotel.h"
#include "Room.h"
#include <iostream>

Hotel::Hotel(std::string n, std::string loc)
        : name(std::move(n)), location(std::move(loc)) {}

Hotel::~Hotel() {
    for (auto& pair : roomsMap) {
        delete pair.second;
    }
}

void Hotel::addRoom(Room* r) {
    roomsMap[r->getNumber()] = r;
}

Room* Hotel::findAvailableRoom(const std::string& type,
                               const std::string& checkIn,
                               const std::string& checkOut) {
    for (const auto& pair : roomsMap) {
        Room* room = pair.second;
        if (room->getType() == type && room->isAvailable(checkIn, checkOut)) {
            return room;
        }
    }
    return nullptr;
}

Room* Hotel::findRoomByNumber(int roomNumber) {
    auto it = roomsMap.find(roomNumber);
    if (it != roomsMap.end()) {
        return it->second;
    }
    return nullptr;
}

void Hotel::listRooms() const {
    if (roomsMap.empty()) {
        std::cout << "No rooms available in hotel " << name << " (" << location << ").\n";
        return;
    }

    std::cout << "Rooms in hotel " << name << " (" << location << "):\n";
    for (const auto& pair : roomsMap) {
        const Room* r = pair.second;
        std::cout << " - Room " << r->getNumber()
                  << " | Type: " << r->getType()
                  << " | Price: " << r->getPrice() << "\n";
    }
}
