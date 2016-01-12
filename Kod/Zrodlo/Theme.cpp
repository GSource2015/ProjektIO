#include "Theme.h"

Theme::Theme(){

}
//Theme::Theme(const Theme& source);
//Theme& Theme::operator=(const Theme& source);

Theme& Theme::LoadBackground(const wxColour& background){
	_background = background;
	return *this;
}
Theme& Theme::LoadBackground(unsigned char R, unsigned char G, unsigned char B){
	_background.Set(R, G, B);
	return *this;
}
Theme& Theme::LoadWalls(const wxColour& walls){
	_walls = walls;
	return *this;
}
Theme& Theme::LoadWalls(unsigned char R, unsigned char G, unsigned char B){
	_walls.Set(R, G, B);
	return *this;
}
Theme& Theme::LoadFloor(const int i, const wxColour& floor){
	if (i > 5)
		throw OutOfRangeIndexException(i);
	else if (i < 0)
		throw NegativeIndexException(i);
	else{
		_floors[i] = floor;
		return *this;
	}
}
Theme& Theme::LoadFloor(const int i, const unsigned char R, const unsigned char G, const unsigned char B){
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
}

wxColour& Theme::getBacground(){
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
