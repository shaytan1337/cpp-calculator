#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits> // Added for std::numeric_limits


std::vector<double> userInput()
{
    double x{}, y{};
    while (true) {
        try {
            std::cout << "------------\n" << "Input the value for x and y: ";
            std::cin >> x;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter numbers.");
            }
            std::cin >> y;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter numbers.");
            }
            return {x, y};
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string getOperation()
{
    std::string operation{};
    while (true) {
        std::cout << "Enter the operation (+, -, *, /): ";
        std::cin >> operation;
        if (operation == "+" || operation == "-" || operation == "*" || operation == "/") {
            return operation;
        } else {
            std::cout << "Unsupported operation. Please try again.\n";
        }
    }
}

double myCalculator(double x, double y, const std::string& operation)
{
    if (operation == "+") {
        std::cout << "You have selected addition operation" << std::endl;
        std::cout << "The result of addition is " << x + y << std::endl;
        return x + y;
    } 
    else if (operation == "*") {
        std::cout << "You have selected multiplication operation" << std::endl;
        std::cout << "The result of multiplication is " << x * y << std::endl;
        return x * y;
    } 
    else if (operation == "/") {
        if (y == 0) {
            std::cerr << "Error: Division by zero is not allowed." << std::endl;
            return std::numeric_limits<double>::quiet_NaN(); // Return NaN for invalid results
        }
        std::cout << "You have selected division operation" << std::endl;
        std::cout << "The result of division is " << x / y << std::endl;
        return x / y;
    } 
    else if (operation == "-") {
        std::cout << "You have selected subtraction operation" << std::endl;
        std::cout << "The result of subtraction is " << x - y << std::endl;
        return x - y;
    } 
    else {
        std::cerr << "Unsupported operation..." << std::endl;
        return std::numeric_limits<double>::quiet_NaN(); // Return NaN for unsupported operations
    }
}


int main()
{
    char repeat;
    do {
        std::vector<double> test_it { userInput() };
        std::string operation { getOperation() };
        double result = myCalculator(test_it[0], test_it[1], operation);

        std::cout << "Do you want to perform another calculation? (y/N): ";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
