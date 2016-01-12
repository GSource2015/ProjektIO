#ifndef _MATRIX2D_H_
#define _MATRIX2D_H_
#include "Vector2D.h"
#include "NegativeIndexException.h"
#include "OutOfRangeIndexException.h"

class Matrix2D{
public:
	Matrix2D();
	Matrix2D(const Matrix2D& source);
	Matrix2D& operator=(const Matrix2D& source);
	Vector2D operator*(const Vector2D& vector) const;
	Matrix2D operator*(const float value) const;
	Matrix2D operator*(const Matrix2D& matrix) const;
	Matrix2D operator+(const float value) const;
	Matrix2D operator+(const Matrix2D& matrix) const;	
	Matrix2D& operator+=(const float value);
	Matrix2D& operator+=(const Matrix2D& matrix);
	Matrix2D& operator*=(const Matrix2D& matrix);
	
	float& operator()(const int h, const int w);


	Matrix2D& translate(const float x, const float y);
	Matrix2D& scale(const float x, const float y);
	Matrix2D& resetValues();

	static Matrix2D getTranslate(const float x, const float y);
	static Matrix2D getScale(const float x, const float y);
	static Matrix2D getBasic();

private:
	float _mat[3][3];
};

#endif
