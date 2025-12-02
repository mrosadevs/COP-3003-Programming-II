#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    double baseFare;

public:
    Vehicle(std::string b, double f) : brand(b), baseFare(f) {}

    double calculateBaseFare(double distance) {
        return distance * baseFare;
    }

    void updateBaseFare(double newFare) {
        baseFare = newFare;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(std::string b, double f, int s)
        : Vehicle(b, f), seats(s) {}

    double seatingAdjustment() {
        return seats > 4 ? 5.0 : 0.0;
    }

    int getSeats() {
        return seats;
    }
};

class ElectricCar : public Car {
protected:
    double batteryLevel;

public:
    ElectricCar(std::string b, double f, int s, double battery)
        : Car(b, f, s), batteryLevel(battery) {}

    double ecoDiscount(double fare) {
        return fare * 0.10;
    }

    void chargeBattery(double amount) {
        batteryLevel = std::min(100.0, batteryLevel + amount);
    }
};

class Driver {
protected:
    std::string driverName;
    double rating;

public:
    Driver(std::string name, double r)
        : driverName(name), rating(r) {}

    void updateRating(double newRating) {
        rating = newRating;
    }

    double ratingBonus() {
        return rating >= 4.5 ? 3.0 : 0.0;
    }
};

class Ride : public ElectricCar, public Driver {
public:
    Ride(std::string b, double f, int s, double battery, std::string name, double r)
        : ElectricCar(b, f, s, battery), Driver(name, r) {}

    double calculateTotalFare(double distance) {
        double fare = calculateBaseFare(distance);
        fare += seatingAdjustment();
        fare -= ecoDiscount(fare);
        fare += ratingBonus();
        return fare;
    }

    void rideSummary(double distance) {
        std::cout << "\n=== Ride Summary ===\n";
        std::cout << "Driver: " << driverName << std::endl;
        std::cout << "Vehicle Brand: " << brand << std::endl;
        std::cout << "Seats: " << getSeats() << std::endl;
        std::cout << "Distance: " << distance << " miles\n";
        std::cout << "Fare: $" << calculateTotalFare(distance) << std::endl;
    }
};

int main() {
    Ride r("Tesla", 2.50, 5, 80.0, "Aiden Pierce", 4.7);

    r.chargeBattery(10);
    r.updateBaseFare(2.75);

    double distance = 12.5;
    r.rideSummary(distance);

    return 0;
}
