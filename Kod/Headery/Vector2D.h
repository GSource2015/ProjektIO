#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"

class Matrix2D;

class Vector2D{
	friend class Matrix2D;
public:
	Vector2D(const float x = 0, const float y = 0);
	Vector2D(const Vector2D &source);

	Vector2D& operator=(const Vector2D& source);
	Vector2D& operator=(const float value);
	Vector2D& operator+=(const Vector2D& vect);
	Vector2D& operator+=(const float value);
	Vector2D operator+(const Vector2D& vect) const;
	Vector2D operator+(const float value) const;
	Vector2D& operator-=(const Vector2D& vect);
	Vector2D& operator-=(const float value);
	Vector2D operator-(const Vector2D& vect) const;
	Vector2D operator-(const float value) const;
	float& operator[](const int index);

	Vector2D& setXY(const float x, const float y);
	Vector2D& setX(const float x);
	Vector2D& setY(const float y);
	Vector2D& resetValues();

	float getX() const;
	float getY() const;
	void getXY(float& x, float& y);
	Vector2D& fit(const float x_real_min, const float y_real_min, const float x_real_max, const float y_real_max, const float x_img_min, const float y_img_min, const float x_img_max, const float y_img_max);
private:
	float _vect[3];

};


#endif
