// small changes
#include <iostream>
#include <string>

using namespace std;

// Define the structure for a station
struct Station {
    string name;    // Name of the station
    Station* next;  // Pointer to the next station in the route

    // Constructor to initialize station with a name
    Station(string stationName) : name(stationName), next(nullptr) {}
};

// Define the train route class
class TrainRoute {
private:
    Station* head;      // Pointer to the first station in the route
    int stationCount;   // Keep track of the number of stations

public:
    // Constructor to initialize an empty train route
    TrainRoute() : head(nullptr), stationCount(0) {}

    // Method to add a station to the train route
    void addStation(string stationName) {
        // Create a new station with the given name
        Station* newStation = new Station(stationName);
        // If the route is empty, set the new station as the head
        if (!head) {
            head = newStation;
        }
        else {
            // Traverse the route to find the last station
            Station* current = head;
            while (current->next) {
                current = current->next;
            }
            // Append the new station to the end of the route
            current->next = newStation;
        }
        // Increment station count
        stationCount++;
    }

    // Method to display the train route
    void displayRoute() {
        // Start traversing from the head station
        Station* current = head;
        int stationNumber = 1; // Start station numbering from 1
        cout << "Train Route:" << endl;
        // Iterate through each station in the route
        while (current) {
            // Print the station number and name
            cout << "Station " << stationNumber << ": " << current->name;
            // If there are more stations, print a separator
            if (stationNumber < stationCount) {
                cout << " - ";
            }
            // Move to the next station
            current = current->next;
            // Increment station number
            stationNumber++;
        }
        cout << endl;
    }
};

// Main function
int main() {
    // Create a train route object
    TrainRoute route;

    // Ask the user to enter station names until they enter "done"
    string stationName;
    cout << "Enter station names (enter 'done' to finish):\n";
    while (true) {
        cout << "> ";
        // Read the station name from the user
        cin >> stationName;
        // If the user enters "done", exit the loop
        if (stationName == "done") {
            break;
        }
        // Add the entered station to the train route
        route.addStation(stationName);
    }

    // Display the train route
    route.displayRoute();

    return 0;
}
