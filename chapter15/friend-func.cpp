#include <iostream>

// Best practice:
// we should prefer non-friend functions over friend functions.

// forward declaration for class
class Humidity;

class Temperature {
   private:
    int m_temp{};

   public:
    explicit Temperature(int temp) : m_temp{temp} {}
    friend void printWeather(const Temperature& temperature,
                             const Humidity& humidity);
};

class Humidity {
   private:
    int m_humidity{0};

   public:
    explicit Humidity(int humidity) : m_humidity{humidity} {}
    friend void printWeather(const Temperature& temperature,
                             const Humidity& humidity);
};

// friend non-member function
// can access private members of both Temperature and Humidity
void printWeather(const Temperature& temperature, const Humidity& humidity) {
    std::cout << "The temperature is " << temperature.m_temp
              << " and the humidity is " << humidity.m_humidity << '\n';
}

int main() {
    Humidity humidity{10};
    Temperature temperature{12};

    printWeather(temperature, humidity);

    return 0;
}
