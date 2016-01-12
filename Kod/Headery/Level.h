#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "Board.h"
#include "Theme.h"

class Level{
public:
	Level();
	Level(const int width, const int height);

	Board& getBoard();
	Theme& getTheme();
	unsigned char getDifficulty() const;
	bool isCustomShape() const;

	void setDifficulty(const unsigned char difficulty);
	void setCustomShape(const bool custom);

private:
	Board _board;
	Theme _theme;
	unsigned char _difficulty;
	bool _custom_shapes;
};

#endif
