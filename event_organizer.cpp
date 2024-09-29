#include <iostream>
#include <string>

using namespace std;

// Class to represent an Event
class Event {

    string eventName;       // Name of the event
    string firstName;       // First name of the organizer
    string lastName;        // Last name of the organizer
    int numberOfGuests;     // Number of guests
    int numberOfMinutes;    // Duration of the event in minutes

    // Constants for cost calculations
    const double costPerHour = 18.50; // Cost per hour
    const double costPerMinute = 0.40; // Cost per minute
    const double costPerDinner = 20.70; // Cost of dinner per guest

public:
    // Constructor to initialize event details
    Event(string name, string fName, string lName, int guests, int minutes)
        : eventName(name), firstName(fName), lastName(lName),
          numberOfGuests(guests), numberOfMinutes(minutes) {}

    // Function to calculate the number of servers needed
    int calculateServers() {
        // One server can handle 20 guests
        return (numberOfGuests + 19) / 20; 
    }

    // Function to calculate the cost for one server
    double calculateCostForOneServer() {
        double costForOneServer = (numberOfMinutes / 60) * costPerHour +
                                   (numberOfMinutes % 60) * costPerMinute;
        return costForOneServer;
    }

    // Function to calculate the total food cost
    double calculateFoodCost() {
        return numberOfGuests * costPerDinner;
    }

    // Function to calculate the average cost per person
    double calculateAverageCostPerPerson() {
        double totalFoodCost = calculateFoodCost();
        return totalFoodCost / numberOfGuests; // Average cost per person
    }

    // Function to calculate the total cost of the event
    double calculateTotalCost() {
        int servers = calculateServers();
        double costForOneServer = calculateCostForOneServer();
        double totalFoodCost = calculateFoodCost();
        return totalFoodCost + (costForOneServer * servers); // Total cost
    }

    // Function to calculate the deposit amount (25% of total cost)
    double calculateDepositAmount() {
        return calculateTotalCost() * 0.25;
    }

    // Function to display the event summary
    void displaySummary() {
        int servers = calculateServers();
        double costForOneServer = calculateCostForOneServer();
        double totalFoodCost = calculateFoodCost();
        double totalCost = calculateTotalCost();
        double depositAmount = calculateDepositAmount();
        double averageCostPerPerson = calculateAverageCostPerPerson();

        cout << "=================Event estimate for:" << firstName << " " << lastName << "================"<<endl;
        cout << "Number of Servers : " << servers << endl;
        cout << "Total Cost for Servers: " << costForOneServer << endl;
        cout << "Total Cost for Food is: " << totalFoodCost << endl;
        cout << "Average Cost per Person: " << averageCostPerPerson << endl<<endl;
        cout << "Total Cost is: " << totalCost << endl;
        cout<<"please deposite a 25%  deposite to reserve the event"<<endl;
        cout << "Deposit Amount is: " << depositAmount << endl;
        
    }
};

int main() {
    // Collecting event details from the user
    string eventName, firstName, lastName;
    int numberOfGuests, numberOfMinutes;

    cout << "**************************Event Management Systeam***************************" << endl<<endl;;
    cout << "Enter the name of the event: ";
    cin >> eventName; // Using cin to read a single word for event name
    cout << "Enter your first name: ";
    cin >> firstName; // Using cin to read a single word for first name
    cout << "Enter your last name: ";
    cin >> lastName; // Using cin to read a single word for last name
    cout << "Enter the number of guests: ";
    cin >> numberOfGuests; // Reading the number of guests
    cout << "Enter the number of minutes for the event: ";
    cin >> numberOfMinutes; // Reading the duration in minutes

    // Create an instance of Event
    Event event(eventName, firstName, lastName, numberOfGuests, numberOfMinutes);

    // Display the event summary
    event.displaySummary();

    return 0;
}
