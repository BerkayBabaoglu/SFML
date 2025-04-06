#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

void SelectMenu();
void Angle();
void Radian();
void asRadian();
void asDegree();


int currentMenu = 0;
int value = 0;

//int main()
//{
//    SelectMenu();
//    return 0;
//}

void SelectMenu() {
    cout << "** Welcome to Angle Calculator! **" << endl;

    cout << "Please choose an option:" << endl;
    cout << "1 - Enter angle in degrees" << endl;
    cout << "2 - Enter angle in radians" << endl;
    cout << "3 - Convert degrees to radians" << endl;
    cout << "4 - Convert radians to degrees" << endl;

    cin >> currentMenu;

    switch (currentMenu)
    {
    case 1:
        Angle();
        break;
    case 2:
        Radian();
        break;
    case 3:
        asRadian();
        break;
    case 4:
        asDegree();
        break;
    default:
        cout << "Wrong number entered!" << endl;
        break;
    }
}

void Angle() {
    cout << "Please enter the angle in degrees: ";
    cin >> value;

    sf::Angle angle1 = sf::degrees(value);
    cout << "You entered: " << angle1.asDegrees() << " degrees" << endl;
}

void Radian() {
    cout << "Please enter the angle in radians: ";
    cin >> value;

    sf::Angle radian1 = sf::radians(value);
    cout << "You entered: " << radian1.asRadians() << " radians" << endl;
}

void asRadian() {
    cout << "Enter degrees to convert to radians: ";
    cin >> value;

    sf::Angle angle1 = sf::degrees(value);
    cout << value << " degrees is " << angle1.asRadians() << " radians" << endl;
}

void asDegree() {
    cout << "Enter radians to convert to degrees: ";
    cin >> value;

    sf::Angle radian1 = sf::radians(value);
    cout << value << " radians is " << radian1.asDegrees() << " degrees" << endl;
}
