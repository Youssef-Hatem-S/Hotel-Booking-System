cmake_minimum_required(VERSION 3.28)
project(Hotel_Booking_System)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(HotelBookingSystem
        main.cpp
        src/Room.cpp
        src/Guest.cpp
        src/Reservation.cpp
        src/Hotel.cpp
        src/BookingSystem.cpp
        src/Menu.cpp)