#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_TRAINS = 8;
const int SEATS_PER_COACH = 80;
const double TICKET_PRICE = 25.0;

struct Train {
    int availableSeats;
    double moneyTaken;
    int passengers;
};

vector<Train> trains(NUM_TRAINS);

void startOfDay() {
    for (int i = 0; i < NUM_TRAINS; ++i) {
        trains[i].availableSeats = SEATS_PER_COACH * 6;
        trains[i].moneyTaken = 0.0;
        trains[i].passengers = 0;
    }
}

bool purchaseTickets(int trainIndex, int numPassengers) {
    if (numPassengers > 0 && numPassengers <= trains[trainIndex].availableSeats) {
        double totalCost = numPassengers * TICKET_PRICE;
        int freeTickets = numPassengers / 10;

        trains[trainIndex].availableSeats -= numPassengers;
        trains[trainIndex].moneyTaken += totalCost;
        trains[trainIndex].passengers += numPassengers;

        cout << "Tickets purchased successfully!\n";
        cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "Free tickets awarded: " << freeTickets << endl;

        return true;
    }
    else {
        cout << "Error: Insufficient seats available.\n";
        return false;
    }
}
