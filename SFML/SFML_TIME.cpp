#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {

	sf::Time t1 = sf::microseconds(10000);
	sf::Time t2 = sf::milliseconds(10);
	sf::Time t3 = sf::seconds(0.01f);

	cout << t1.asMicroseconds() << " " << t2.asMilliseconds() << " " << t3.asSeconds() << endl;

	return 0;
}