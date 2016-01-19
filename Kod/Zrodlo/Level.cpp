#include "Level.h"


Level::Level() : _board(5, 5){
	_difficulty = 3;
}
Level::Level(const int width, const int height) : _board(width, height){
	_difficulty = 3;
}

Level& Level::operator=(const Level& source){
	_board = source._board;
	_theme = source._theme;
	_difficulty = source._difficulty;
	_custom_shapes = source._custom_shapes;
	_name = source._name;	
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
void Level::setName(const char *name){
	_name=  name;
}
void Level::setName(string name){
	_name = name;
}
string Level::getName(){
	return _name;
}
