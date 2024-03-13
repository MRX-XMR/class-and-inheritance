#include <iostream>

class Car {
public:
    int speed;
private:
    int fuel;

public:
    Car(int speed, int fuel) : speed(speed), fuel(fuel) {}

    void increaseSpeed(int value, int fuelConsumption) {
        if (fuel >= fuelConsumption) {
            speed += value;
            fuel -= fuelConsumption;
            std::cout << "Speed increased to " << speed << ". Fuel remaining: " << fuel << std::endl;
        } else {
            std::cout << "Not enough fuel to increase speed." << std::endl;
        }
    }
};

class Truck : public Car {
private:
    int cargoCapacity;

public:
    Truck(int speed, int fuel, int cargoCapacity) : Car(speed, fuel), cargoCapacity(cargoCapacity) {}

    void loadCargo(int cargoWeight) {
        if (cargoWeight <= cargoCapacity) {
            std::cout << "Cargo loaded. Total weight: " << cargoWeight << std::endl;
        } else {
            std::cout << "Cannot load cargo, weight exceeds capacity." << std::endl;
        }
    }
};

class Motorcycle : public Car {
private:
    bool isSport;

public:
    Motorcycle(int speed, int fuel, bool isSport) : Car(speed, fuel), isSport(isSport) {}

    void wheelie() {
        if (isSport) {
            std::cout << "Performing a wheelie!" << std::endl;
        } else {
            std::cout << "This motorcycle is not designed for wheelies." << std::endl;
        }
    }
};

int main() {
    Truck truck1(80, 100, 500);
    truck1.loadCargo(300);
    truck1.increaseSpeed(20, 30);

    Motorcycle motorcycle1(120, 15, true);
    motorcycle1.wheelie();
    motorcycle1.increaseSpeed(30, 10);

    return 0;
}
