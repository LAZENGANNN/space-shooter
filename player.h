#pragma once
#include "settings.h"
#include "laser.h"
#include <list>
#include "textobj.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx = 0.f;
	int lives = 3;
	std::list<Laser*> lasers;
	int hp = 100;
	TextObj hpText;
	sf::FloatRect bounds;
	sf::Clock timer;
	bool threeLasers = false;

public:
	Player() : hpText(std::to_string(hp), sf::Vector2f(0.f, 0.f)) {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		bounds = sprite.getGlobalBounds();
		sprite.setPosition(
			(WINDOW_WIDTH - bounds.width) / 2,
			WINDOW_HEIGHT - bounds.height - 50.f
		);
		timer.restart();
	}

	void update() {
		speedx = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			speedx = -8;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			speedx = 8;
		}
		sprite.move(speedx, 0.f);

		sf::Vector2f playerPos = sprite.getPosition();
		if (playerPos.x < 0) {
			sprite.setPosition(0.f, playerPos.y);
		}
		else if (playerPos.x > WINDOW_WIDTH - bounds.width) {
			sprite.setPosition(WINDOW_WIDTH - bounds.width, playerPos.y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			fire();
		}
		for (auto laser : lasers) {
			laser->update();
		}
		hpText.update("HP:" + std::to_string(hp));
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
		for (auto laser : lasers) {
			window.draw(laser->getSprite());
		}
		window.draw(hpText.getText());
	}

	int getLives() { return lives; }
	void incLives() { lives++; }
	void decLives() { lives--; }

	void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		if (now > 350) {
			sf::Vector2f laserPos{ sprite.getPosition().x + bounds.width / 2,  sprite.getPosition().y };
			Laser* l = new Laser(laserPos);
			lasers.push_back(l);
			if (threeLasers) {
				sf::Vector2f leftLaserPos{ laserPos.x - PLAYER_WIDTH/2, laserPos.y + bounds.width/2 };
				sf::Vector2f rightLaserPos{ laserPos.x + PLAYER_WIDTH/2, laserPos.y + bounds.width / 2 };
				Laser* lL = new Laser(leftLaserPos);
				Laser* rL = new Laser(rightLaserPos);
				lasers.push_back(lL);
				lasers.push_back(rL);
			}
			timer.restart();

		}
	}
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	bool isDead() { return hp <= 0; }
	bool isAlive() { return hp > 0; }
	void receiveDamage(int damage) { hp -= damage; }

	std::list<Laser*>* getLasers() { return &lasers; }

	void activateThreeLasers() { threeLasers = true; }
	void deactivateThreeLasers() { threeLasers = false; }

	void heal() { 
		hp += 50;
		//hp = hp % 100;
	}
};