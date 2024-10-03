#include <iostream>
#include <string>
using namespace std;

class Event {
private:
    string name;
    string fname;
    string lname;
    int guests;
    int minutes;

    const double hourRate = 18.50;
    const double minRate = 0.40;
    const double dinnerRate = 20.70;

public:
    void setData(string n, string f, string l, int g, int m) {
        name = n;
        fname = f;
        lname = l;
        guests = g;
        minutes = m;
    }

    // Calculate number of servers
    int calcServers() {
        return (guests + 19) / 20;
    }

    // Calculate server cost
    double serverCost() {
        return (minutes / 60) * hourRate + (minutes % 60) * minRate;
    }

    // Calculate food cost
    double foodCost() {
        return guests * dinnerRate;
    }

    // Calculate average cost per person
    double avgCost() {
        return foodCost() / guests;
    }

    // Calculate total cost
    double totalCost() {
        int servers = calcServers();
        double server = serverCost();
        double food = foodCost();
        return food + (server * servers);
    }

    // Calculate deposit amount
    double deposit() {
        return totalCost() * 0.25;
    }

    // Display event summary
    void display() {
        int servers = calcServers();
        double server = serverCost();
        double food = foodCost();
        double total = totalCost();
        double avg = avgCost();
        double dep = deposit();

        cout << "=========================Event Estimate for: " << fname << " " << lname << "============================"<<endl;
        cout << "Servers: " << servers << endl;
        cout << "Server Cost: " << server << endl;
        cout << "Food Cost: " << food << endl;
        cout << "Avg Cost: " << avg << endl << endl;
        cout << "Total Cost: " << total << endl;
        cout<<"please deposite a 25%   deposite to reserve the event"<<endl;
        cout << "Deposit 25% to reserve: " << dep << endl;
    }
};

int main() {
    string name, fname, lname;
    int guests, minutes;

    cout << "*************************Event Management System**************************" << endl << endl;
    cout << "Enter event name: ";
    cin >> name;
    cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;
    cout << "Enter guests: ";
    cin >> guests;
    cout << "Enter minutes: ";
    cin >> minutes;

    Event event;
    event.setData(name, fname, lname, guests, minutes);
    event.display();

    return 0;
}

