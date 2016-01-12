#ifndef _BOARD_H_
#define _BOARD_H_
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"
#include "WrongValueException.h"
#include "NullArrayException.h"
#include "WrongSizeException.h"

class Board{
public:
	Board();
	Board(const int width, const int height);
	Board(const Board& source);
	~Board();

	Board& operator=(const Board& source);
	int operator()(const int width, const int height) const;
	int operator()(const int width, const int height, const char value);

	int getValue(const int width, const int height) const;
	int getWidth() const;
	int getHeight() const;
	void getSize(int& width, int& height) const;

	int setValue(const int width, const int height, const char value);
	Board& fillWith(const char value);

	void resize(const int new_width, const int new_height);
	bool isValid() const;

private:
	char **_fields;
	int _width;
	int _height;
	
	void reserveFields();
	void freeFields();
};

#endif
