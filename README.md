Hotel Booking System
A comprehensive console-based Hotel Booking System built with C++ that demonstrates object-oriented programming principles and efficient resource management. This system provides dual-role functionality for both administrators and guests with a clean, menu-driven interface.

https://img.shields.io/badge/C++-17-blue.svg
https://img.shields.io/badge/License-MIT-green.svg
https://img.shields.io/badge/Platform-Windows%2520%257C%2520Linux%2520%257C%2520Mac-lightgrey.svg

Features
Admin Features
Hotel Management: Add new hotels to the system

Room Management: Add rooms to specific hotels with detailed information

Reservation Overview: View all reservations across the system

System Management: Comprehensive administrative controls

Guest Features
Hotel Search: Search for hotels by name

Room Availability: Check available rooms based on dates and room type

Booking System: Make reservations with check-in/check-out dates

Reservation Management: View and cancel existing reservations

Personal Dashboard: View all personal bookings

Technical Features
Date Conflict Prevention: Intelligent booking system prevents double-booking

Role-Based Access: Separate interfaces for administrators and guests

Input Validation: Robust error handling and input validation

Memory Management: Proper resource handling with custom destructors

Efficient Data Structures: Uses std::unordered_map for O(1) lookups

Project Structure
text
Hotel-Booking-System/
├── include/                 # Header files
│   ├── BookingSystem.h     # Main booking system controller
│   ├── Guest.h            # Guest entity definition
│   ├── Hotel.h            # Hotel entity and management
│   ├── Menu.h             # User interface handler
│   ├── Reservation.h      # Reservation entity
│   └── Room.h            # Room entity and availability logic
├── src/                   # Source files
│   ├── BookingSystem.cpp  # Booking system implementation
│   ├── Guest.cpp         # Guest functionality
│   ├── Hotel.cpp         # Hotel management implementation
│   ├── Menu.cpp          # Menu and user interface
│   ├── Reservation.cpp   # Reservation handling
│   ├── Room.cpp          # Room availability logic
│   └── main.cpp          # Application entry point
└── README.md             # Project documentation
Getting Started
Prerequisites
C++ Compiler (GCC, Clang, or MSVC)

Git (for cloning the repository)

Installation
Clone the repository

bash
git clone https://github.com/Youssef-Hatem-S/Hotel-Booking-System.git
cd Hotel-Booking-System
Compile the project

bash
# Using g++
g++ -std=c++11 -o hotel-booking src/*.cpp -Iinclude

# Or compile individually for better error reporting
g++ -std=c++11 -c src/*.cpp -Iinclude
g++ -o hotel-booking *.o
Run the application

bash
./hotel-booking
Usage
Starting the Application
Run the executable to launch the Hotel Booking System:

bash
./hotel-booking
Main Menu Options
Admin: Access administrative functions

Guest: Access guest booking functions

Exit: Close the application

Admin Functions
Add new hotels with name and location

Add rooms to existing hotels with room number, price, and type

View all reservations across the system

Guest Functions
Search for hotels by name

Book rooms by specifying dates and room type

Cancel existing reservations

View personal reservation history

Technical Implementation
Object-Oriented Design
The system implements several key classes:

Hotel: Manages hotel properties and room collections

Room: Handles room availability and reservations

Guest: Stores guest information and booking history

Reservation: Manages booking details and dates

BookingSystem: Core system controller

Menu: User interface and input handling

Data Structures
std::unordered_map for efficient hotel and reservation lookup

std::vector for managing room reservations

Custom memory management with proper destructors

Key Algorithms
Date conflict detection for room availability

Input validation and error handling

Menu navigation and state management

Contributing
Contributions are welcome! Here's how you can help:

Fork the project

Create a feature branch (git checkout -b feature/AmazingFeature)

Commit your changes (git commit -m 'Add some AmazingFeature')

Push to the branch (git push origin feature/AmazingFeature)

Open a Pull Request

License
This project is licensed under the MIT License - see the LICENSE file for details.

Developer
Youssef Hatem

GitHub: @Youssef-Hatem-S

Project Link: https://github.com/Youssef-Hatem-S/Hotel-Booking-System

Acknowledgments
Inspired by real-world hotel management systems

Built to demonstrate C++ object-oriented programming capabilities

Designed with scalability and maintainability in mind
