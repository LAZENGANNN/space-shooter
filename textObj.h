#pragma once
#include "settings.h"

class TextObj {
private:
	sf::Font font;
	sf::Text text;

public:
TextObj(std::string str, sf::Vector2f pos) {
	font.loadFromFile("res\\DS-DIGIB.ttf");
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(CHAR_SIZE);
	text.setPosition(pos);
}

void update(std::string str) {
	text.setString(str);
}
sf::Text getText() { return text; }
//void textDraw(sf::RenderWindow& window, const TextObj& textobj) {
//	window.draw(textobj.text);
//}

};