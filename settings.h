#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 600;
const float WINDOW_HEIGHT = 1000;
const std::string WINDOW_TITLE = "SFML Space Shooter P33022";
const float FPS = 60.f;

const float ROAD_LAYER_SPEED = 7.f;
const float ROAD_OFFSET = 100.f;
const float LEFT_ROAD_SIDE = 100.f;
const float RIGHT_ROAD_SIDE = 400.f;
const float  ROAD_LANE_WIDTH = 75.f;

const float PLAYER_WIDTH = 99.f;
const float PLAYER_HEIGHT = 75.f;
const sf::Vector2f PLAYER_START_POS{ (WINDOW_WIDTH - PLAYER_WIDTH) / 2.f, WINDOW_HEIGHT- PLAYER_HEIGHT - 10};
const float PLAYER_SPEEDX = 10.f;
std::string PLAYER_FILE_NAME = "images\\playerShip1_green.png";
const int INITIAL_HP = 100;
const int FIRE_CD = 300;

const int METEOR_QTY = 35; // max 70000

const int CHAR_SIZE = 32;
const float TEXT_OFFSET = 60.f;
const sf::Vector2f TEXT_START_POS{ WINDOW_WIDTH - TEXT_OFFSET, 0.f };

const sf::Vector2f LASER_START_POS{};
const float LASER_WIDTH = 9.f;

const float BONUS_SPEED = 10.f;
const int BONUS_RANGE = 10000;
const int BONUS_CHANCE = 5000;
const std::string MULTI_LASER_BONUS_FILE_NAME = "images\\bonus_shots.png";
