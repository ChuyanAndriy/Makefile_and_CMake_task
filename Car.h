#include <iostream>

namespace records {
    const int kDeafaultTariff = 1000;
class Car {
   public:
    Car();

    void Display();

    void RaiseTariff(int raise_amount);
    void DecreaseTariff(int decrease_amount);
    void MakeAvailable();
    void Remove();

    bool get_is_available();

    void set_car_code(std::string car_code);
    std::string get_car_code();

    void set_brand_code(std::string brand_code);
    std::string get_brand_code();

    void set_registration_number(int registration_number);
    int get_registration_number();

    void set_body_number(int body_number);
    int get_body_number();

    void set_engine_number(int engine_number);
    int get_engine_number();

    void set_release_year(int release_year);
    int get_release_year();

    void set_mileage(int mileage);
    int get_mileage();

    void set_tariff(int tariff);
    int get_tariff();

    void set_driver_code(std::string driver_code);
    std::string get_driver_code();

    void set_date_of_last_tech_inspection(std::string date_of_last_tech_inspection);
    std::string get_date_of_last_tech_inspection();

    void set_mechanic_code(std::string mechanic_code);
    std::string get_mechanic_code();

    void set_special_marks(std::string special_marks);
    std::string get_special_marks();

   private:
    int tariff_;
    bool is_available_;
    std::string car_code_;
    std::string brand_code_;
    int registration_number_;
    int body_number_;
    int engine_number_;
    int release_year_;
    int mileage_;
    std::string driver_code_;
    std::string date_of_last_tech_inspection_;
    std::string mechanic_code_;
    std::string special_marks_;
};
}  // namespace records