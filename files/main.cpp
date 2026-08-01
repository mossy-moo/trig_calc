#include <iostream>
#include <cmath>
#include <numbers>

static double DegreesToRadians(double degrees) {
    double radians = degrees * (std::numbers::pi/180);
    return radians;
}

static double RadiansToDegrees(double radians) {
    double degrees = radians * (180/std::numbers::pi);
    return degrees;
}

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

static double FindLeg() {

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

static void AngleBased() {

    int angleBasedMenu;
    while (true) {

        std::cout << "------------------------" << '\n' << " Angle Based Calculator " << '\n' << "------------------------" << '\n';

        std::cout << "1: Calculate an angle" << '\n' << "2: Calculate a side" << '\n';
        std::cin >> angleBasedMenu;

        if (std::cin.fail()) {
            std::cout << "Invalid, input must be an integer" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (angleBasedMenu != 1 && angleBasedMenu != 2) {
            std::cout << "Please enter a listed option" << '\n';
            continue;
        }

        break;
    }

    switch (angleBasedMenu) {
        /*
         * calculating an angle
         * need at least two side accept only one as blank
        */
        case 1:

            double opposite_side;
            double adjacent_side;
            double hypotenuse;

            std::cout << "Please enter all lengths in the same units and input any unknown measurements as 0" << '\n';

            //opposite_side input
            while (true) {
                std::cout << "Enter the length of the opposite side: ";
                std::cin >> opposite_side;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input an integer";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            //adjacent_side input
            while (true) {
                std::cout << "Enter the length of the adjacent side: ";
                std::cin >> adjacent_side;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input an integer";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            //hypotenuse input
            while (true) {
                std::cout << "Enter the length of the hypotenuse side: ";
                std::cin >> hypotenuse;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input an integer";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (hypotenuse != 0) {
                    if (adjacent_side >= hypotenuse || opposite_side >= hypotenuse) {
                        std::cout << "The hypotenuse must be the longest side" << '\n';
                        continue;
                    }
                }
                break;
            }

            if ((opposite_side == 0 && adjacent_side == 0 && hypotenuse ==0) || (opposite_side == 0 && adjacent_side == 0) || (opposite_side == 0 && hypotenuse == 0) || (adjacent_side == 0 && hypotenuse ==0)) {
                std::cout << "Not enough information";
            }

            //sine
            else if (opposite_side != 0 && hypotenuse != 0) {

                double sin_angle = opposite_side/hypotenuse;
                double angle = RadiansToDegrees(std::asin(sin_angle));
                std::cout << "The angle is " << angle << "°" << '\n';
            }

            //cosine
            else if (adjacent_side != 0 && hypotenuse != 0) {
                double cos_angle = adjacent_side/hypotenuse;
                double angle = RadiansToDegrees(std::acos(cos_angle));
                std::cout << "The angle is " << angle << "°" << '\n';
            }

            //tangent
            else if (opposite_side != 0 && adjacent_side != 0) {
                std::cout << "Tangent under development";
                double tan_angle = opposite_side/adjacent_side;
                double angle = RadiansToDegrees(std::atan(tan_angle));
                std::cout << "The angle is " << angle << "°" << '\n';
            }

            else {
                double sin_angle = opposite_side/hypotenuse;
                double angle = RadiansToDegrees(std::asin(sin_angle));
                std::cout << "The angle is " << angle << "°" << '\n';
            }

            break;

            /*
             * Calculating a side
             * Need one side and one angle that != 90
             */
        case 2:
            //angle input
            double angle;
            while (true) {
                std::cout << "Enter and angle that is greater than or equal to 90°: " << '\n';
                std::cin >> angle;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input a double";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (angle >= 90) {
                    std::cout << "The angle is too big";
                    continue;
                }

                if (angle == 0) {
                    std::cout << "The angle is too small";
                    continue;
                }

                break;
            }

            std::cout << "Please enter all lengths in the same units and input any unknown measurements as 0" << '\n';

            //opposite_side input
            while (true) {
                std::cout << "Enter the length of the opposite side: ";
                std::cin >> opposite_side;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input an integer";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            //adjacent_side input
            while (true) {
                std::cout << "Enter the length of the adjacent side: ";
                std::cin >> adjacent_side;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input an integer";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            }

            //hypotenuse input
            while (true) {
                std::cout << "Enter the length of the hypotenuse side: ";
                std::cin >> hypotenuse;

                if (std::cin.fail()) {
                    std::cout << "Invalid, input an integer";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (hypotenuse != 0) {
                    if (adjacent_side >= hypotenuse || opposite_side >= hypotenuse) {
                        std::cout << "The hypotenuse must be the longest side" << '\n';
                        continue;
                    }
                }
                break;
            }

            if ((opposite_side != 0 && adjacent_side != 0 && hypotenuse != 0)) {
                std::cout << "Use option number one or two" << '\n';
                return;
            }

            if (opposite_side == 0 && adjacent_side == 0 && hypotenuse == 0) {

                std::cout << "Insufficient information" << '\n';
                return;
            }

            break;
    }
}

int main() {

    bool repeat = true;

    while (repeat == true) {

        //menuChoice input
        int menuChoice;
        while (true){
            std::cout << "----------------------------------------" << '\n' << " Welcome to the trigonometry calculator " << '\n' << "----------------------------------------" << '\n';
            std::cout << "1: Calculate the hypotenuse" << '\n' << "2: Calculate the legs" << '\n' << "3: Calculate using an angle" << '\n';
            std::cout << "----------------------------------------" << '\n';
            std::cin >> menuChoice;

            if (std::cin.fail()) {
                std::cout << "Invalid input, must be an integer" << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3) {
                std::cout << "Please enter one of the listed options" << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        }

        double ans;
        switch (menuChoice) {
            case 1:
                ans = FindHypotenuse();
                std::cout << ans << '\n';
                break;

            //invoking FindLeg method
            case 2:
                ans = FindLeg();
                std::cout << ans << '\n';
                break;

            //invoking AngleBased method
            case 3:
                AngleBased();
                break;

            default:
                std::cout << "Invalid choice" << '\n';
                break;
        }

        while (true) {

            std::cout << "Would you like to do another calculation (y/n): ";
            std::string repeatInput;
            std::cin >> repeatInput;

            if (std::cin.fail()) {
                std::cout << "Invalid, input must be a string" << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            else if (repeatInput == "y" || repeatInput == "Y") {

            }

            else if (repeatInput == "n" || repeatInput == "N") {

                repeat = false;
            }

            else {
                std::cout << "Enter a listed option" << '\n';
                continue;
            }

            break;
        }


    }
    return 0;
}