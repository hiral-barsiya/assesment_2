#include <iostream>
#include <string>
using namespace std;

class Event {
private:
    string eventName;
    string firstName;
    string lastName;
    int numberOfGuests;
    int numberOfMinutes;

    const double costPerHour = 18.50;
    const double costPerMinute = 0.40;
    const double costPerDinner = 20.70;

public:
    // Set event details
    void setEventDetails(string name, string fName, string lName, int guests, int minutes) {
        eventName = name;
        firstName = fName;
        lastName = lName;
        numberOfGuests = guests;
        numberOfMinutes = minutes;
    }

    // Calculate number of servers needed
    int C_servers() {
        return (numberOfGuests + 19) / 20;
    }

    // Calculate cost for one server
    double C_CostForOneServer() {
        return (numberOfMinutes / 60) * costPerHour + (numberOfMinutes % 60) * costPerMinute;
    }

    // Calculate total food cost
    double C_FoodCost() {
        return numberOfGuests * costPerDinner;
    }

    // Calculate average cost per person
    double C_AverageCostPerPerson() {
        return C_FoodCost() / numberOfGuests;
    }

    // Calculate total cost of the event
    double C_totalcost() {
        int servers = C_servers();
        double costForOneServer = C_CostForOneServer();
        double totalFoodCost = C_FoodCost();
        return totalFoodCost + (costForOneServer * servers);
    }

    // Calculate deposit amount 
    double C_DepositAmount() {
        return C_totalcost() * 0.25;
    }

    
    void display() {
        int servers = C_servers();
        double costForOneServer = C_CostForOneServer();
        double totalFoodCost = C_FoodCost();
        double totalCost = C_totalcost();
        double depositAmount = C_DepositAmount();
        double averageCostPerPerson = C_AverageCostPerPerson();

        cout << "=================Event estimate for:" << firstName << " " << lastName << "================"<<endl;
        cout << "Number of Servers : " << servers << endl;
        cout << "Total Cost for Servers: " << costForOneServer << endl;
        cout << "Total Cost for Food is: " << totalFoodCost << endl;
        cout << "Average Cost per Person: " << averageCostPerPerson << endl<<endl;
        cout << "Total Cost is: " << totalCost << endl;
        cout<<"please deposite a 25%   deposite to reserve the event"<<endl;
        cout << "Deposit Amount is: " << depositAmount << endl;
        

    }
};

int main() {
    string eventName, firstName, lastName;
    int numberOfGuests, numberOfMinutes;

    cout << "Event Management System" << endl << endl;
    cout << "Enter event name: ";
    cin >> eventName;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter number of guests: ";
    cin >> numberOfGuests;
    cout << "Enter event duration (minutes): ";
    cin >> numberOfMinutes;

    Event event;
    event.setEventDetails(eventName, firstName, lastName, numberOfGuests, numberOfMinutes);
    event.display();

    return 0;
}
