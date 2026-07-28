#include <iostream>
#include <cmath>
#include <numbers>

static double FindHypotenuse() {
    //side1 input
    double side1;
    while (true) {

        std::cout << "What is the length of side one: ";
        std::cin >> side1;

        if (std::cin.fail()) {
            std::cout << "Invalid, input must be a double";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    //side2 input
    double side2;
    while (true) {
        std::cout << "Enter the length of side 2: ";
        std::cin >> side2;

        if (std::cin.fail()) {
            std::cout << "Invalid input must be a double" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    //calculation
    double hypotenuse = sqrt((pow(side1, 2) + pow(side2, 2)));

    return hypotenuse;
}

static double findLeg() {

    //hypotenuse input
    double hypotenuse;
    while (true) {

        std::cout << "What is the length of the hypotenuse: ";
        std::cin >> hypotenuse;

        if (std::cin.fail()) {
            std::cout << "Invalid, input must a double";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    //side input;
    double side;
    while (true) {
        std::cout << "Enter the length of the side: ";
        std::cin >> side;

        if (std::cin.fail()) {

            std::cout << "Invalid, input must be a double";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    const double ans = sqrt((pow(hypotenuse, 2) - pow(side, 2)));
    return ans;
}


int main() {

    const double pi = std::numbers::pi;

    //menuChoice input
    int menuChoice;
    while (true){
        std::cout << "-------" << "Welcome" << "-------" << '\n';
        std::cout << "1: Calculate the hypotenuse" << '\n' << "2: Calculate the legs" << '\n';
        std::cin >> menuChoice;

        if (std::cin.fail()) {
            std::cout << "Invalid input, must be an integer" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (menuChoice != 1 && menuChoice != 2) {
            std::cout << "Please enter one of the listed options" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    double ans;
    switch (menuChoice) {
        case 1: {
            ans = FindHypotenuse();
            std::cout << ans;
            break;
        }
        case 2:
            ans = findLeg();
            std::cout << ans;
            break;

        default:
            std::cout << "Invalid choice" << '\n';
            break;
    }

    return 0;
}