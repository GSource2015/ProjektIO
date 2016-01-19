#include "Theme.h"



Theme::Theme(){
}
//Theme::Theme(const Theme& source);
Theme& Theme::operator=(const Theme& source){
	_background = source._background;
	_walls =  source._walls;
	
	for(int i = 0; i < 6; ++i){
		_floors[i] = source._floors[i];
	}
	isDefault = source.isDefault;
	_mtheme = source._mtheme;;
	_name = source._name;	
	
}

Theme& Theme::loadBackground(const wxColour& background){
	_background = background;
	return *this;
}
Theme& Theme::loadBackground(unsigned char R, unsigned char G, unsigned char B){
	_background.Set(R, G, B);
	return *this;
}
Theme& Theme::loadWalls(const wxColour& walls){
	_walls = walls;
	return *this;
}
Theme& Theme::loadWalls(unsigned char R, unsigned char G, unsigned char B){
	_walls.Set(R, G, B);
	return *this;
}
Theme& Theme::loadFloor(const int i, const wxColour& floor){
	if (i > 6)
		throw OutOfRangeIndexException(i);
	else if (i < 0)
		throw NegativeIndexException(i);
	else{
		_floors[i] = floor;
		return *this;
	}
}
Theme& Theme::loadFloor(const int i, const unsigned char R, const unsigned char G, const unsigned char B){
	if (i > 5)
		throw OutOfRangeIndexException(i);
	else if (i < 0)
		throw NegativeIndexException(i);
	else{
		_floors[i].Set(R, G, B);
		return *this;
	}
}
Theme& Theme::setTheme(main_theme new_theme){
	_mtheme = new_theme;
	return *this;
}

wxColour& Theme::getBackground(){
	return _background;
}
wxColour& Theme::getWalls(){
	return _walls;
}
wxColour& Theme::getFloor(int number){
	if (number > 5)
		throw OutOfRangeIndexException(number);
	else if (number < 0)
		throw NegativeIndexException(number);
	else{
		return _floors[number];
	}
}
Theme::main_theme Theme::getTheme() const{
	return _mtheme;
}

Theme& Theme::setName(const char *name){
	_name = name;
	return *this;
}

Theme& Theme::setName(std::string name){
	_name = name;
	return *this;
}

string  Theme::getName(){
	return _name;
}

Theme& Theme::loadFloor(const int i, unsigned long colour){
	_floors[i] = wxColour(colour);
	return *this;
}

Theme& Theme::loadBackground(unsigned long colour){
	_background = wxColour(colour);
	return *this;
}

Theme& Theme::loadWalls(unsigned long colour){
	_walls = wxColour(colour);
	return *this;
}
