#include <iostream>

// Function declarations
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);

int main() {
    double temperature;
    int choice;

    while (true) {
        std::cout << "\nTemperature Converter\n";
        std::cout << "1. Convert Celsius to Fahrenheit\n";
        std::cout << "2. Convert Fahrenheit to Celsius\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 3) {
            break;
        }

        std::cout << "Enter the temperature: ";
        std::cin >> temperature;

        switch (choice) {
            case 1:
                std::cout << temperature << " Celsius is " << celsiusToFahrenheit(temperature) << " Fahrenheit\n";
                break;
            case 2:
                std::cout << temperature << " Fahrenheit is " << fahrenheitToCelsius(temperature) << " Celsius\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
