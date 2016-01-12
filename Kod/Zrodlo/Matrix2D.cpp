#include "Matrix2D.h"


Matrix2D::Matrix2D(){
	resetValues();
}
Matrix2D::Matrix2D(const Matrix2D& source){
	operator=(source);
}

Matrix2D& Matrix2D::operator=(const Matrix2D& source){
	_mat[0][0] = source._mat[0][0]; _mat[0][1] = source._mat[0][1]; _mat[0][2] = source._mat[0][2];
	_mat[1][0] = source._mat[1][0]; _mat[1][1] = source._mat[1][1]; _mat[1][2] = source._mat[1][2];
	_mat[2][0] = source._mat[2][0]; _mat[2][1] = source._mat[2][1]; _mat[2][2] = source._mat[2][2];
	return *this;
}
Vector2D Matrix2D::operator*(const Vector2D& vector) const{
	Vector2D result;
	for (int h = 0; h < 3; ++h){
		float sum = 0;
		for (int w = 0; w < 3; ++w){
			sum += vector._vect[w] * _mat[h][w];
		}
		result[h] = sum;
	}
	return result;
}
Matrix2D Matrix2D::operator*(const float value) const{
	Matrix2D result;
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			result(h, w) = _mat[h][w] * value;
		}
	}
	return result;
}
Matrix2D Matrix2D::operator*(const Matrix2D& matrix) const{
	Matrix2D result;
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			float sum = 0;
			for (int n = 0; n < 3; ++n){
				sum += _mat[h][n] * matrix._mat[n][w];
			}
			result(h, w) = sum;
		}
	}
	return result;
}
Matrix2D Matrix2D::operator+(const float value) const{
	Matrix2D result;
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			result(h, w) = _mat[h][w] + value;
		}
	}
	return result;
}
Matrix2D Matrix2D::operator+(const Matrix2D& matrix) const{
	Matrix2D result;
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			result(h, w) = _mat[h][w] + matrix._mat[h][w];
		}
	}
	return result;
}
Matrix2D& Matrix2D::operator+=(const float value){
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			_mat[h][w] += value;
		}
	}
	return *this;
}
Matrix2D& Matrix2D::operator+=(const Matrix2D& matrix){
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			_mat[h][w] += matrix._mat[h][w];
		}
	}
	return *this;
}
Matrix2D& Matrix2D::operator*=(const Matrix2D& matrix){
	Matrix2D temporary;
	for (int h = 0; h < 3; ++h){
		for (int w = 0; w < 3; ++w){
			float sum = 0;
			for (int n = 0; n < 3; ++n){
				sum += _mat[h][n] * matrix._mat[n][w];
			}
			temporary(h, w) = sum;
		}
	}
	operator=(temporary);
	return *this;
}

float& Matrix2D::operator()(const int h, const int w){
	if (h > 2)
		throw OutOfRangeIndexException(h);
	if (w > 2)
		throw OutOfRangeIndexException(w);
	if (h < 0)
		throw NegativeIndexException(h);
	if (w < 0)
		throw NegativeIndexException(w);
	return _mat[h][w];
}

Matrix2D& Matrix2D::translate(const float x, const float y){
	operator*=(getTranslate(x, y));
	return *this;
}
Matrix2D& Matrix2D::scale(const float x, const float y){
	operator*=(getScale(x, y));
	return *this;
}
Matrix2D& Matrix2D::resetValues(){
	_mat[0][0] = 0; _mat[0][1] = 0; _mat[0][2] = 0;
	_mat[1][0] = 0; _mat[1][1] = 0; _mat[1][2] = 0;
	_mat[2][0] = 0; _mat[2][1] = 0; _mat[2][2] = 1;
	return *this;
}

Matrix2D Matrix2D::getTranslate(const float x, const float y){
	Matrix2D result;
	result(0, 0) = 1; result(0, 1) = 0; result(0, 2) = x;
	result(1, 0) = 0; result(1, 1) = 1; result(1, 2) = y;
	result(2, 0) = 0; result(2, 1) = 0; result(2, 2) = 1;
	return result;
}
Matrix2D Matrix2D::getScale(const float x, const float y){
	Matrix2D result;
	result(0, 0) = x; result(0, 1) = 0; result(0, 2) = 0;
	result(1, 0) = 0; result(1, 1) = y; result(1, 2) = 0;
	result(2, 0) = 0; result(2, 1) = 0; result(2, 2) = 1;
	return result;
}
Matrix2D Matrix2D::getBasic(){
	Matrix2D result;
	result(0, 0) = 1; result(0, 1) = 0; result(0, 2) = 0;
	result(1, 0) = 0; result(1, 1) = 1; result(1, 2) = 0;
	result(2, 0) = 0; result(2, 1) = 0; result(2, 2) = 1;
	return result;
}
