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
    
public:
    // Initialize rooms in Hotel constructor
    Hotel() {
    	Hotel() {
        rooms.push_back(Room(101, "Single"));
        rooms.push_back(Room(102, "Double"));
        rooms.push_back(Room(103, "Suite"));
    }
    
    // Add a new customer
    void addCustomer(string name, string contact) {
        customers.push_back(Customer(name, contact));
        cout << "Customer added successfully.\n";
    }
    
    // Book a room for an existing customer
    void bookRoom(int roomNumber, string customerName) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && !room.isOccupied) {
                for (auto& customer : customers) {
                    if (customer.name == customerName) {
                        room.isOccupied = true;
                        bookings.push_back(Booking(room, customer));
                        cout << "Room " << roomNumber << " booked for " << customerName << endl;
                        return;
                    }
                }
                cout << "Customer not found!" << endl;
                return;
            }
        }
        cout << "Room not available!" << endl;
    }