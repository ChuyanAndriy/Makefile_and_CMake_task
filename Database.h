#include <iostream>

#include "Car.h"

namespace records {
const int kMaxCars = 100;
const int kFirstCarNumber = 1000;

class Database {
   public:
    Database();
    ~Database();

    Car &AddCar(std::string car_code, std::string brand_code,
                int registration_number, int body_number, int engine_number,
                int release_year, int mileage, std::string driver_code,
                std::string date_of_last_tech_inspection, std::string mechanic_code,
                std::string special_marks);
    Car &GetCar(std::string car_code);
    Car &GetCar(int registration_number);
    void DisplayAll();
    void DisplayAvailable();
    void DisplayRemoved();

   protected:
    Car* cars_ = new Car[kMaxCars];
    int next_slot_;
    int next_car_number_;
};
}  // namespace records
