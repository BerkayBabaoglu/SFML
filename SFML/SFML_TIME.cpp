#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread> //this_thread::sleep_for icin
#include <chrono>

using namespace std;

//int main()
//{
//	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Oyun");
//	window.setFramerateLimit(60);
//
//	cout << "Starting the game in 3 seconds" << endl;
//
//	this_thread::sleep_for(chrono::seconds(3));
//	
//
//	cout << "START! the clock is ticking" << endl;
//
//	//sfml zaman tutucu
//	sf::Clock gameClock;
//
//	while (window.isOpen()) {
//		while (const optional event = window.pollEvent()) {
//			if (event->is<sf::Event::Closed>()) {
//				window.close();
//			}
//		}
//	}
//
//
//	//gecen sureyi al
//	sf::Time elapsed = gameClock.getElapsedTime();
//	float seconds = elapsed.asSeconds();
//
//	cout << "Elapsed time: " << seconds << " second\r";
//
//	window.clear(sf::Color::Black);
//	window.display();
//
//}