#include "Car.h"

#include <iostream>
#include <string>

using namespace std;

namespace records {
Car::Car() {
    tariff_ = kDeafaultTariff;
    is_available_ = false;
    car_code_ = "";
    brand_code_ = "";
    registration_number_ = -1;
    body_number_ = -1;
    engine_number_ = -1;
    release_year_ = -1;
    mileage_ = -1;
    driver_code_ = "";
    date_of_last_tech_inspection_ = "";
    mechanic_code_ = "";
    special_marks_ = "";
}
void Car::Display() {
    cout << "Car code: " << get_car_code() << endl;
    cout << "-----------------------------" << endl;
    cout << "Brand code:" << get_brand_code() << endl;
    cout << "Registration number: " << get_registration_number() << endl;
    cout << "Body number: " << get_body_number() << endl;
    cout << "Engine number: " << get_engine_number() << endl;
    cout << "Release year: " << get_release_year() << endl;
    cout << "Mileage: " << get_mileage() << endl;
    cout << "Driver code: " << get_driver_code() << endl;
    cout << "Date of last technical inspection:" << get_date_of_last_tech_inspection() << endl;
    cout << "Mechanic code: " << get_mechanic_code() << endl;
    cout << "Special marks: " << get_special_marks() << endl;
    cout << "Tariff: " << get_tariff() << endl;
    cout << "Car is " << (get_is_available() ? "available." : "not available.") << endl;
}
void Car::MakeAvailable() { is_available_ = true; }
void Car::Remove() { is_available_ = false; }
void Car::RaiseTariff(int raise_amount) { set_tariff(get_tariff() + raise_amount); }
void Car::DecreaseTariff(int decrease_amount) {set_tariff(get_tariff() - decrease_amount); }

bool Car::get_is_available() { return is_available_; }

void Car::set_tariff(int tariff) { tariff_ = tariff; }
int Car::get_tariff() { return tariff_; }

void Car::set_car_code(string car_code) { car_code_ = car_code; }
string Car::get_car_code() { return car_code_; }

void Car::set_brand_code(string brand_code) { brand_code_ = brand_code; }
string Car::get_brand_code() { return brand_code_; }

void Car::set_registration_number(int registration_number) { registration_number_ = registration_number; }
int Car::get_registration_number() { return registration_number_; }

void Car::set_body_number(int body_number) { body_number_ = body_number; }
int Car::get_body_number() { return body_number_; }

void Car::set_engine_number(int engine_number) { engine_number_ = engine_number; }
int Car::get_engine_number() { return engine_number_; }

void Car::set_release_year(int release_year) { release_year_ = release_year; }
int Car::get_release_year() { return release_year_; }

void Car::set_mileage(int mileage) { mileage_ = mileage; }
int Car::get_mileage() { return mileage_; }

void Car::set_driver_code(string driver_code) { driver_code_ = driver_code; }
string Car::get_driver_code() { return driver_code_; }

void Car::set_date_of_last_tech_inspection(string date_of_last_tech_inspection) { date_of_last_tech_inspection_ = date_of_last_tech_inspection; }
string Car::get_date_of_last_tech_inspection() { return date_of_last_tech_inspection_; }

void Car::set_mechanic_code(string mechanic_code) { mechanic_code_ = mechanic_code; }
string Car::get_mechanic_code() { return mechanic_code_; }

void Car::set_special_marks(string special_marks) { special_marks_ = special_marks; }
string Car::get_special_marks() { return special_marks_; }
}  // namespace records
