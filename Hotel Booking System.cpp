#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Add using namespace std
using namespace std;

class Room {
public:
    int roomNumber; // Declare roomNumber
    string type; // Declare type
    bool isOccupied; // Declare isOccupied
    
    // Constructor to initialize room attributes.
    Room(int num, string t) : roomNumber(num), type(t), isOccupied(false) {}
};

class Customer {
public:
    string name; // Declare name
    string contact; // Declare contact
    
    // Constructor to initialize customer attributes.
    Customer(string n, string c) : name(n), contact(c) {}
};

class Booking {
public:
    Room room; // Declare room
    Customer customer; // Declare customer
    
    // Constructor to initialize booking attributes.
    Booking(Room r, Customer c) : room(r), customer(c) {}
};

class Hotel {
private:
    vector<Room> rooms; // Vector to store rooms
    vector<Customer> customers; // Vector to store customers
    vector<Booking> bookings; // Vector to store bookings