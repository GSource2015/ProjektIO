#include "Vector2D.h"


Vector2D::Vector2D(const float x, const float y){
	_vect[0] = x;
	_vect[1] = y;
	_vect[2] = 1;
}
Vector2D::Vector2D(const Vector2D &source){
	operator=(source);
}

Vector2D& Vector2D::operator=(const Vector2D& source){
	_vect[0] = source._vect[0];
	_vect[1] = source._vect[1];
	_vect[2] = source._vect[2];
	return *this;
}
Vector2D& Vector2D::operator=(const float value){
	_vect[0] = value;
	_vect[1] = value;
	return *this;
}
Vector2D& Vector2D::operator+=(const Vector2D& vect){
	_vect[0] += vect._vect[0];
	_vect[1] += vect._vect[1];
	return *this;
}
Vector2D& Vector2D::operator+=(const float value){
	_vect[0] += value;
	_vect[1] += value;
	return *this;
}
Vector2D Vector2D::operator+(const Vector2D& vect) const{
	Vector2D result;
	result[0] = _vect[0] + vect._vect[0];
	result[1] = _vect[1] + vect._vect[1];
	return result;
}
Vector2D Vector2D::operator+(const float value) const{
	Vector2D result;
	result[0] = _vect[0] + value;
	result[1] = _vect[1] + value;
	return result;
}
Vector2D& Vector2D::operator-=(const Vector2D& vect){
	_vect[0] -= vect._vect[0];
	_vect[1] -= vect._vect[1];
	return *this;
}
Vector2D& Vector2D::operator-=(const float value){
	_vect[0] -= value;
	_vect[1] -= value;
	return *this;
}
Vector2D Vector2D::operator-(const Vector2D& vect) const{
	Vector2D result;
	result[0] = _vect[0] - vect._vect[0];
	result[1] = _vect[1] - vect._vect[1];
	return result;
}
Vector2D Vector2D::operator-(const float value) const{
	Vector2D result;
	result[0] = _vect[0] - value;
	result[1] = _vect[1] - value;
	return result;
}
float& Vector2D::operator[](const int index){
	if (index < 0)
		throw NegativeIndexException(index);
	if (index > 2)
		throw OutOfRangeIndexException(index);
	return _vect[index];
}

Vector2D& Vector2D::setXY(const float x, const float y){
	_vect[0] = x;
	_vect[1] = y;
	return *this;
}
Vector2D& Vector2D::setX(const float x){
	_vect[0] = x;
	return *this;
}
Vector2D& Vector2D::setY(const float y){
	_vect[1] = y;
	return *this;
}
Vector2D& Vector2D::resetValues(){
	_vect[0] = 0;
	_vect[1] = 0;
	_vect[2] = 1;
	return *this;
}

float Vector2D::getX() const{
	return _vect[0];
}
float Vector2D::getY() const{
	return _vect[1];
}

void Vector2D::getXY(float& x, float& y){
	x = _vect[0];
	y = _vect[1];
}

Vector2D& Vector2D::fit(const float x_real_min, const float y_real_min, const float x_real_max, const float y_real_max, const float x_img_min, const float y_img_min, const float x_img_max, const float y_img_max){
	float Sx = (x_img_max - x_img_min) / (x_real_max - x_real_min);
	float Sy = (y_img_max - y_img_min) / (y_real_max - y_real_min);
	_vect[0] = Sx*(_vect[0] - x_real_min) + x_img_min;
	_vect[1] = y_img_max - (Sy*(_vect[1] - y_real_min) + y_img_min);
	return *this;
}

