// ## Задача 4: Абстрактный класс "Транспортное средство"

// **Цель:** Создать и использовать абстрактный класс.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double fuelLevel;

public:
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y), fuelLevel(100) {}
    virtual ~Vehicle() {}
    
    // TODO: Сделать класс абстрактным с чисто виртуальными методами:
    // - startEngine()
    // - stopEngine()
    // - refuel(double amount)
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void refuel(double amount) = 0;

    
    virtual void displayInfo() const {
        cout << brand << " " << model << " (" << year << ")" << endl;
        cout << "Уровень топлива: " << fuelLevel << "%" << endl;
    }
    
    double getFuelLevel() const { return fuelLevel; }
    void setFuelLevel(double level) { 
        if (level >= 0 && level <= 100) fuelLevel = level; 
    }
};

class Car : public Vehicle {
private:
    int doors;
    string transmission;

public:
    Car(string b, string m, int y, int d, string trans) 
        : Vehicle(b, m, y), doors(d), transmission(trans) {}
    
    // TODO: Реализовать чисто виртуальные методы
    void startEngine() override {
        cout << "Автомобиль " << brand << " " << model << " заводится с ключа" << endl;
        cout << "Коробка передач: " << transmission << endl;
    }
    void stopEngine() override {
        cout << "Двигатель автомобиля " << brand << " " << model << " заглушен" << endl;};
    void refuel(double amount) override {
        double newFuelLevel = fuelLevel + amount;
        if (newFuelLevel > 100) {
            fuelLevel = 100;
            cout << "Бак автомобиля полностью заполнен!" << endl;
        } else {
            fuelLevel = newFuelLevel;
            cout << "Заправлено " << amount << "%. Текущий уровень: " << fuelLevel << "%" << endl;
        }
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Количество дверей: " << doors << endl;
        cout << "Трансмиссия: " << transmission << endl;
    }

    // Honestly I have no idea why I decided to add this method
    void honk() {
        cout << "Бип-бип! " << brand << " " << model << " сигналит" << endl;
    };

};


class Motorcycle : public Vehicle {
private:
    bool hasFairing;

public:
    Motorcycle(string b, string m, int y, bool fairing) 
        : Vehicle(b, m, y), hasFairing(fairing) {}
    
    // TODO: Реализовать чисто виртуальные методы
    void wheelie() {
        cout << brand << " " << model << " делает вилли!" << endl;
    }

    void startEngine() override {
        cout << "Мотоцикл " << brand << " " << model << " заводится с кнопки" << endl;
        if (hasFairing) {
            cout << "Мотоцикл с обтекателем" << endl;
        } else {
            cout << "Мотоцикл без обтекателя" << endl;
        }
    }

    void stopEngine() override {
        cout << "Двигатель мотоцикла " << brand << " " << model << " заглушен" << endl;
    }

    void refuel(double amount) override {
        double newFuelLevel = fuelLevel + amount;
        if (newFuelLevel > 100) {
            fuelLevel = 100;
            cout << "Бак мотоцикла полностью заполнен!" << endl;
        } else {
            fuelLevel = newFuelLevel;
            cout << "Заправлено " << amount << "%. Текущий уровень: " << fuelLevel << "%" << endl;
        }
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Обтекатель: " << (hasFairing ? "есть" : "нет") << endl;
    }


};

int main() {
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Toyota", "Camry", 2022, 4, "автоматическая"));
    vehicles.push_back(new Car("Lada", "Vesta", 2021, 4, "механическая"));
    vehicles.push_back(new Motorcycle("Yamaha", "YZF-R6", 2023, true));
    vehicles.push_back(new Motorcycle("Harley-Davidson", "Sportster", 2020, false));
    
    // TODO: Создать массив указателей на Vehicle
    // Добавить объекты Car и Motorcycle
    // Продемонстрировать полиморфное поведение
    for (size_t i = 0; i < vehicles.size(); ++i) {
        cout << "\n--- Транспортное средство " << i + 1 << " ---" << endl;
        vehicles[i]->displayInfo();
        vehicles[i]->startEngine();
        
        // Использование топлива
        vehicles[i]->setFuelLevel(50);
        vehicles[i]->refuel(30);
        
        vehicles[i]->stopEngine();
        cout << endl;
    }
    
    return 0;
}