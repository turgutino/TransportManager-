Vehicle Management System
Overview
The Vehicle Management System is a C++ application that manages different types of vehicles, including cars, ships, and airplanes. The system allows users to store and display information about various vehicles using object-oriented programming principles, including inheritance and encapsulation.

Features
Vehicle Types: Supports cars, ships, and airplanes, each with specific attributes.
Unique Identification: Each vehicle is assigned a unique ID for easy identification.
Information Display: Vehicles can be displayed sequentially with their details.
Sleep Functionality: A delay is implemented between displaying vehicles to enhance user experience.
Memory Management: Uses pointers for dynamic memory allocation and proper cleanup.
Classes
Engine
Manages engine information (number, company, and volume).
Transportation
Base class for all vehicles, containing common attributes like model, vendor, and unique ID.
Car
Inherits from Transportation and adds features specific to cars, such as whether it has a spoiler.
Ship
Inherits from Transportation and adds features specific to ships, such as whether it has a sail.
AirPlane
Inherits from Transportation and adds features specific to airplanes, including engine count and passenger capacity.
VehicleDepot
Manages collections of vehicles and provides functionality to add vehicles and display all stored vehicles.
