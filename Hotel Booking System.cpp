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
    
    // Check out a room and mark it as available
    void checkOutRoom(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.isOccupied) {
                room.isOccupied = false;
                bookings.erase(remove_if(bookings.begin(), bookings.end(), [&](Booking& booking) {
                    return booking.room.roomNumber == roomNumber;
                }), bookings.end());
                cout << "Room " << roomNumber << " checked out successfully.\n";
                return;
            }
        }
        cout << "Room is either not occupied or does not exist.\n";
    }
    
    // Display all current bookings
    void showBookings() {
        cout << "Current Bookings:" << endl;
        for (const auto& booking : bookings) {
            cout << "Room " << booking.room.roomNumber << " booked by " << booking.customer.name << endl;
        }
        if (bookings.empty()) {
            cout << "No current bookings.\n";
        }
    }
    
    // Display all available rooms
    void showAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (const auto& room : rooms) {
            if (!room.isOccupied) {
                cout << "Room " << room.roomNumber << " (" << room.type << ")\n";
            }
        }
    }
    
    // Search for a customer by name
    void searchCustomer(string customerName) {
        cout << "Searching for customer: " << customerName << endl;
        for (const auto& customer : customers) {
            if (customer.name == customerName) {
                cout << "Customer Found: " << customer.name << ", Contact: " << customer.contact << endl;
                return;
            }
        }
        cout << "Customer not found.\n";
    }
};

// Main function
int main() {
	Hotel hotel; // Create Hotel object
    int choice;
    
    // Main menu loop
    do {
        cout << "\n--- Hotel Booking System ---\n";
        cout << "1. Add Customer\n";
        cout << "2. Book Room\n";
        cout << "3. Check Out Room\n";
        cout << "4. Show Bookings\n";
        cout << "5. Show Available Rooms\n";
        cout << "6. Search Customer\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name, contact;
        int roomNumber;
        
        // Perform actions based on user choice
        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin.ignore(); 
                getline(cin, name); 
                cout << "Enter customer contact: ";
                getline(cin, contact); 
                hotel.addCustomer(name, contact); 
                break;
            case 2:
                cout << "Enter room number to book: ";
                cin >> roomNumber; 
                cout << "Enter customer name: ";
                cin.ignore(); 
                getline(cin, name); 
                hotel.bookRoom(roomNumber, name); 
                break;
            case 3:
                cout << "Enter room number to check out: ";
                cin >> roomNumber; 
                hotel.checkOutRoom(roomNumber); 
                break;
            case 4:
                hotel.showBookings(); 
                break;
            case 5:
                hotel.showAvailableRooms(); 
                break;
            case 6:
                cout << "Enter customer name to search: ";
                cin.ignore(); 
                getline(cin, name); 
                hotel.searchCustomer(name); 
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7); 

    return 0; 
}        
