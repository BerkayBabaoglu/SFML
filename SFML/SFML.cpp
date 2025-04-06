#include <iostream>
#include <SFML/Graphics.hpp>

int currentMenu = 0;

using namespace std;
int main()
{

}

void SelectMenu() {

    cout << "** Welcome to Angle Calculator! **" << endl;

    cout << "Please enter the number!" << endl;

    cin >> currentMenu;

    if (currentMenu != NULL) {
        switch (currentMenu)
        {
        case 1:
            Angle();
        case 2:
            Radian();
        case 3:
            asRadian();
        case 4:
            asDegree();
        default:
            cout << "Wrong number entered!" << endl;
            break;
        }
    }
}

float Angle() {
    cout << "Please enter the angle value!" << endl;

}