#include "Board.h"


Board::Board(){
	_fields = NULL;
	_width = 0;
	_height = 0;
}

Board::Board(const int width, const int height){
	if (width == 0 && height == 0){
		_fields = NULL;
		_width = 0;
		_height = 0;
	}
	else if (width < 3 || width > 30)
		throw WrongSizeException(width);
	else if (height < 3 || height > 30)
		throw WrongSizeException(height);
	else{
		_width = width;
		_height = height;
		reserveFields();
	}
}
Board::Board(const Board& source){
	_width = source.getWidth();
	_height = source.getHeight();
	reserveFields();
	for (int h = 0; h < _height; ++h){
		for (int w = 0; w < _width; ++w){
			_fields[h][w] = source._fields[h][w];
		}
	}
}

Board::~Board(){
	freeFields();
}

Board& Board::operator=(const Board& source){
	freeFields();
	_width = source.getWidth();
	_height = source.getHeight();
	reserveFields();
	for (int h = 0; h < _height; ++h){
		for (int w = 0; w < _width; ++w){
			_fields[h][w] = source._fields[h][w];
		}
	}
	return *this;
}
int Board::operator()(const int width, const int height) const{
	return getValue(width, height);
}
int Board::operator()(const int width, const int height, const char value){
	return setValue(width, height, value);
}

int Board::getValue(const int width, const int height) const{
	if (_fields == NULL)
		throw NullArrayException();
	if (width < 0)
		throw NegativeIndexException(width);
	if (width >= _width)
		throw OutOfRangeIndexException(width);
	if (height < 0)
		throw NegativeIndexException(height);
	if (height >= _height)
		throw OutOfRangeIndexException(height);
	return _fields[height][width];
}

int Board::getWidth() const{
	return _width;
}
int Board::getHeight() const{
	return _height;
}
void Board::getSize(int& width, int& height) const{
	width = _width;
	height = _height;
}

int Board::setValue(const int width, const int height, const char value){
	if (_fields == NULL)
		throw NullArrayException();
	if (width < 0)
		throw NegativeIndexException(width);
	if (width >= _width)
		throw OutOfRangeIndexException(width);
	if (height < 0)
		throw NegativeIndexException(height);
	if (height >= _height)
		throw OutOfRangeIndexException(height);
	if (value < -1 || value > 5)
		throw WrongValueException(value);
	char tmp = _fields[height][width];
	_fields[height][width] = value;
	return tmp;
}

Board& Board::fillWith(const char value){
	if (_fields == NULL)
		throw NullArrayException();
	if (value < -1 || value > 5)
		throw WrongValueException(value);
	for (int h = 0; h < _height; ++h)
		for (int w = 0; w < _width; ++w)
			_fields[h][w] = value;
	return *this;
}

void Board::resize(const int new_width, const int new_height){
	if (new_width == 0 && new_height == 0)
		freeFields();
	else if (new_width < 3 || new_width > 30)
		throw WrongSizeException(new_width);
	else if (new_height < 3 || new_height > 30)
		throw WrongSizeException(new_height);
	else if (_fields){
		char **old = _fields;
		int oldw = _width, oldh = _height;
		_width = new_width;
		_height = new_height;
		reserveFields();
		int maxw = _width < oldw ? _width : oldw;
		int maxh = _height < oldh ? _height : oldh;
		for (int h = 0; h < maxh; ++h)
			for (int w = 0; w < maxw; ++w)
				_fields[h][w] = old[h][w];
		for (int h = 0; h < oldh; ++h)
			delete[] old[h];
		delete[] old;
	}
	else{
		_width = new_width;
		_height = new_height;
		reserveFields();
	}
}

bool Board::isValid() const{
	return _fields != NULL;
}


void Board::reserveFields(){
	_fields = new char *[_height];
	for (int h = 0; h < _height; ++h){
		_fields[h] = new char[_width];
		for (int w = 0; w < _width; ++w){
			_fields[h][w] = 0;
		}
	}
}

void Board::freeFields(){
	for (int h = 0; h < _height; ++h)
		delete[] _fields[h];
	delete[] _fields;
	_fields = NULL;
	_width = 0;
	_height = 0;
}

