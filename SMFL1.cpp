#include  <SFML/Graphics.hpp>
#include <iostream>
#include <bitset>

using namespace std;
using namespace sf;

int main() {
	RenderWindow window(VideoMode(750, 400), "lesson-2-2");
	
	
	
	//======================================================
	// Конструктор 3 объекта (шестиугольник)
	//======================================================
	CircleShape Crc3;
	Crc3.setRadius(80);
	Crc3.setPointCount(6);
	//Crc3.setOutlineColor(Color(128, 255, 128));
	//Crc3.setOutlineThickness(2);
	Crc3.setPosition(450, 200);
	


	//======================================================
	// Главный цикл программы
	//======================================================
	int i = 0, j = 0;
	uint8_t Red = 0;

	while (window.isOpen()) {
		// Конструктор обработчика событий
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		// Вызовы функций
		window.clear();

		uint8_t  Green = 0, Blue = 0;
		Red |= (i & 16711680) >> 16;
		Green |= (i & 65280) >> 8;
		Blue |= (i & 255);

		Crc2.setFillColor(Color(Red+=10, Green, Blue, 170));
		//cout << i << " " << (int)Red << " " << (int)Green << " " << (int)Blue << " " <<  endl;
		Crc3.setFillColor(Color(0, j, 255 - j, 170));
		Crc2.rotate(0.5);
		Crc3.rotate(-0.5);

		window.draw(Crc2);
		window.draw(Crc3);
		window.display();
		i += 50; i %= 16777216;
		j++; j %= 256;

	}
	return 0;
}
