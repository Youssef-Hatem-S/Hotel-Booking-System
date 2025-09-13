# 🏨 Hotel Booking Management System

A comprehensive console-based Hotel Booking System built with C++ that demonstrates object-oriented programming principles and efficient resource management. This system provides dual-role functionality for both administrators and guests with a clean, menu-driven interface.

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20Mac-lightgrey.svg)

## ✨ Features

### 👨‍💼 Admin Features
- **Hotel Management**: Add new hotels to the system
- **Room Management**: Add rooms to specific hotels with detailed information
- **Reservation Overview**: View all reservations across the system
- **System Management**: Comprehensive administrative controls

### 👥 Guest Features
- **Hotel Search**: Search for hotels by name
- **Room Availability**: Check available rooms based on dates and room type
- **Booking System**: Make reservations with check-in/check-out dates
- **Reservation Management**: View and cancel existing reservations
- **Personal Dashboard**: View all personal bookings

### 🔧 Technical Features
- **Date Conflict Prevention**: Intelligent booking system prevents double-booking
- **Role-Based Access**: Separate interfaces for administrators and guests
- **Input Validation**: Robust error handling and input validation
- **Memory Management**: Proper resource handling with custom destructors
- **Efficient Data Structures**: Uses `std::unordered_map` for O(1) lookups

## 🏗️ Project Structure
Hotel-Booking-System/
├── include/ # Header files
│ ├── BookingSystem.h # Main booking system controller
│ ├── Guest.h # Guest entity definition
│ ├── Hotel.h # Hotel entity and management
│ ├── Menu.h # User interface handler
│ ├── Reservation.h # Reservation entity
│ └── Room.h # Room entity and availability logic
├── src/ # Source files
│ ├── BookingSystem.cpp # Booking system implementation
│ ├── Guest.cpp # Guest functionality
│ ├── Hotel.cpp # Hotel management implementation
│ ├── Menu.cpp # Menu and user interface
│ ├── Reservation.cpp # Reservation handling
│ ├── Room.cpp # Room availability logic
│ └── main.cpp # Application entry point
└── README.md # This file

