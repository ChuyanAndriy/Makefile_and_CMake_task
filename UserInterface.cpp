#include <iostream>
#include <stdexcept>
#include <string>

#include "Database.h"

using namespace std;
using namespace records;

int DisplayMenu();
void DoAdd(Database& database);
void DoRemove(Database& database);
void DoRaiseTariff(Database& database);
void DoDecreaseTariff(Database& database);

int main(int args, char** argv) {
    Database car_database;
    bool done = false;

    while (!done) {
        int selection = DisplayMenu();

        switch (selection) {
            case 1:
                DoAdd(car_database);
                break;
            case 2:
                DoRemove(car_database);
                break;
            case 3:
                DoRaiseTariff(car_database);
                break;
            case 4:
                DoDecreaseTariff(car_database);
                break;
            case 5:
                (car_database).DisplayAll();
                break;
            case 6:
                (car_database).DisplayAvailable();
                break;
            case 7:
                (car_database).DisplayRemoved();
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
}

int DisplayMenu() {
    int selection;

    cout << endl;
    cout << "Taxi Company Database" << endl;
    cout << "_____________________" << endl;
    cout << "1) Add a new car" << endl;
    cout << "2) Remove car" << endl;
    cout << "3) Raise tariff" << endl;
    cout << "4) Decrease tariff" << endl;
    cout << "5) List all cars" << endl;
    cout << "6) List all available cars" << endl;
    cout << "7) List all unavailable cars" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "--->";

    cin >> selection;

    return selection;
}

void DoAdd(Database& database) {
    string car_code;
    string brand_code;
    int registration_number;
    int body_number;
    int engine_nember;
    int release_year;
    int mileage;
    string driver_code;
    string date_of_last_tech_inspection;
    string mechanic_code;
    string special_marks;

    cout << "Car code?" << endl;
    cin >> car_code;
    cout << "Brand code?" << endl;
    cin >> brand_code;
    cout << "Registration number?" << endl;
    cin >> registration_number;
    cout << "Body number?" << endl;
    cin >> body_number;
    cout << "Engine number?" << endl;
    cin >> engine_nember;
    cout << "Release year?" << endl;
    cin >> release_year;
    cout << "mileage?" << endl;
    cin >> mileage;
    cout << "Driver code?" << endl;
    cin >> driver_code;
    cout << "Date of last tech inspection?" << endl;
    cin >> date_of_last_tech_inspection;
    cout << "Mechanic code?" << endl;
    cin >> mechanic_code;
    cout << "Special marks?" << endl;
    cin >> special_marks;

    try {
        database.AddCar(car_code, brand_code, registration_number, body_number,
                        engine_nember, release_year, mileage, driver_code,
                        date_of_last_tech_inspection, mechanic_code,
                        special_marks);
    } catch (std::exception ex) {
        cerr << "Unable to add new car!" << endl;
    }
}

void DoRemove(Database& database) {
    string car_code;

    cout << "Car code?" << endl;
    cin >> car_code;

    try {
        Car& car = database.GetCar(car_code);
        car.Remove();
        cout << "Car " << car_code << " has been removed." << endl;
    } catch (std::exception ex) {
        cerr << "Unable to remove car!" << endl;
    }
}

void DoRaiseTariff(Database& database) {
    string car_code;
    int raise_amount;

    cout << "Car code?" << endl;
    cin >> car_code;
    cout << "How much should the tariff be raised?" << endl;
    cin >> raise_amount;

    try {
        Car& car = database.GetCar(car_code);
        car.RaiseTariff(raise_amount);
    } catch (std::exception ex) {
        cerr << "Unable to raise the tariff!" << endl;
    }
}

void DoDecreaseTariff(Database& database) {
    string car_code;
    int decrease_amount;

    cout << "Car code?" << endl;
    cin >> car_code;
    cout << "How much should the tariff be decreased?" << endl;
    cin >> decrease_amount;

    try {
        Car& car = database.GetCar(car_code);
        car.DecreaseTariff(decrease_amount);
    } catch (std::exception ex) {
        cerr << "Unable to decrease the tariff!" << endl;
    }
}
