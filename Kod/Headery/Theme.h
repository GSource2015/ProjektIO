#ifndef _THEME_H
#define _THEME_H
#include <wx/colour.h>
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"

class Theme{
public:
	enum main_theme {WINTER, FOREST, DESERT, COTTAGE, DUNGEON, BEACH};
	Theme();
	//Theme(const Theme& source);
	//Theme& operator=(const Theme& source);

	Theme& LoadBackground(const wxColour& background);
	Theme& LoadBackground(unsigned char R, unsigned char G, unsigned char B);
	Theme& LoadWalls(const wxColour& walls);
	Theme& LoadWalls(unsigned char R, unsigned char G, unsigned char B);
	Theme& LoadFloor(const int i, const wxColour& floor);
	Theme& LoadFloor(const int i, unsigned char R, unsigned char G, unsigned char B);
	Theme& setTheme(main_theme new_theme);

	wxColour& getBacground();
	wxColour& getWalls();
	wxColour& getFloor(int number);

	main_theme getTheme() const;

private:
	wxColour _background;
	wxColour _walls;
	wxColour _floors[5];
	main_theme _mtheme;
};

#endif
