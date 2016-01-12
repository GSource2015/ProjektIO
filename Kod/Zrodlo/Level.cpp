#include "Level.h"


Level::Level() : _board(5, 5){
	_difficulty = 3;
}
Level::Level(const int width, const int height) : _board(width, height){
	_difficulty = 3;
}

Board& Level::getBoard(){
	return _board;
}
Theme& Level::getTheme(){
	return _theme;
}
unsigned char Level::getDifficulty() const{
	return _difficulty;
}
bool Level::isCustomShape() const{
	return _custom_shapes;
}

void Level::setDifficulty(const unsigned char difficulty){
	if (difficulty > 7 || difficulty < 3)
		throw WrongValueException(difficulty);
	_difficulty = difficulty;
}
void Level::setCustomShape(const bool custom){
	_custom_shapes = custom;
}
