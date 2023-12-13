#include "Database.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace records {
Database::Database() {
    next_slot_ = 0;
    next_car_number_ = kFirstCarNumber;
}
Database::~Database() { delete [] cars_; }

Car& Database::AddCar(string car_code, string brand_code,
                      int registration_number, int body_number,
                      int engine_number, int release_year, int mileage,
                      string driver_code, string date_of_last_tech_inspection,
                      string mechanic_code, string special_marks) {
    if (next_slot_ >= kMaxCars) {
        cerr << "There is no more room to add the new car!" << endl;
        throw exception();
    }

    Car& car = cars_[next_slot_++];
    car.set_car_code(car_code);
    car.set_brand_code(brand_code);
    car.set_registration_number(registration_number);
    car.set_body_number(body_number);
    car.set_engine_number(engine_number);
    car.set_release_year(release_year);
    car.set_mileage(mileage);
    car.set_driver_code(driver_code);
    car.set_date_of_last_tech_inspection(date_of_last_tech_inspection);
    car.set_mechanic_code(mechanic_code);
    car.set_special_marks(special_marks);
    car.MakeAvailable();

    return car;
}

Car& Database::GetCar(std::string car_code) {
    for (int i = 0; i < next_slot_; i++) {
        if (cars_[i].get_car_code() == car_code) {
            return cars_[i];
        }
    }

    cerr << "No match with car code " << car_code << endl;
    throw exception();
}

Car& Database::GetCar(int registration_number) {
    for (int i = 0; i < next_slot_; i++) {
        if (cars_[i].get_registration_number() == registration_number) {
            return cars_[i];
        }
    }

    cerr << "No match with car registration number " << registration_number << endl;
    throw exception();
}

void Database::DisplayAll() {
    for (int i = 0; i < next_slot_; i++) {
        cars_[i].Display();
        cout << '\n' << endl;
    }
}

void Database::DisplayAvailable() {
    for (int i = 0; i < next_slot_; i++) {
        if (cars_[i].get_is_available()) {
            cars_[i].Display();
            cout << '\n' << endl;
        }
    }
}

void Database::DisplayRemoved() {
    for (int i = 0; i < next_slot_; i++) {
        if (!cars_[i].get_is_available()) {
            cars_[i].Display();
            cout << '\n' << endl;
        }
    }
}
}  // namespace records
