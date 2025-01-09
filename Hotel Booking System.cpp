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