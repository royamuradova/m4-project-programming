#include <iostream>
#include <string>
using namespace std;

// -------------------- ParkedCar Class --------------------
class ParkedCar {
private:
    string make, model, color, licenseNumber;
    int minutesParked;

public:
    ParkedCar(string mk, string mdl, string clr, string lic, int min) {
        make = mk;
        model = mdl;
        color = clr;
        licenseNumber = lic;
        minutesParked = min;
    }

    int getMinutesParked() const { return minutesParked; }
    string getMake() const { return make; }
    string getModel() const { return model; }
    string getColor() const { return color; }
    string getLicenseNumber() const { return licenseNumber; }
};

// -------------------- ParkingMeter Class --------------------
class ParkingMeter {
private:
    int minutesPurchased;

public:
    ParkingMeter(int minutes) {
        minutesPurchased = minutes;
    }

    int getMinutesPurchased() const { return minutesPurchased; }
};

// -------------------- ParkingTicket Class --------------------
class ParkingTicket {
private:
    ParkedCar car;
    double fine;
    string officerName;
    string badgeNumber;

public:
    ParkingTicket(ParkedCar c, string name, string badge, int overMinutes)
        : car(c), officerName(name), badgeNumber(badge) {
        fine = 25.0;
        if (overMinutes > 60) {
            fine += 10.0 * ((overMinutes - 1) / 60); // Extra fine per hour
        }
    }

    void printTicket() const {
        cout << "\n*** Parking Ticket Issued ***\n";
        cout << "Car - " << car.getColor() << " " << car.getMake()
             << " " << car.getModel() << ", License: " << car.getLicenseNumber() << endl;
        cout << "Fine: $" << fine << endl;
        cout << "Officer: " << officerName << ", Badge #: " << badgeNumber << endl;
    }
};

// -------------------- PoliceOfficer Class --------------------
class PoliceOfficer {
private:
    string name;
    string badgeNumber;

public:
    PoliceOfficer(string n, string badge) {
        name = n;
        badgeNumber = badge;
    }

    void inspectCar(ParkedCar car, ParkingMeter meter) const {
        int parked = car.getMinutesParked();
        int paid = meter.getMinutesPurchased();

        if (parked > paid) {
            int overMinutes = parked - paid;
            ParkingTicket ticket(car, name, badgeNumber, overMinutes);
            ticket.printTicket();
        } else {
            cout << "\nNo violation. Car is legally parked.\n";
        }
    }
};

// -------------------- Main Function --------------------
int main() {
    // Create a parked car: make, model, color, license, minutes parked
    ParkedCar car("Toyota", "Camry", "Silver", "XYZ-1234", 125);

    // Create a parking meter with time purchased
    ParkingMeter meter(60);  // 60 minutes purchased

    // Create a police officer
    PoliceOfficer officer("Jane Doe", "4789");

    // Officer inspects the car
    officer.inspectCar(car, meter);

    return 0;
}
