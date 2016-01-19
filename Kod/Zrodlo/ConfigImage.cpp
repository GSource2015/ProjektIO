#include "ConfigImage.h"
#include <cmath>
ConfigImage::ConfigImage(const int wimg, const int himg) :
_wimg(wimg), _himg(himg) {
	_scalex = 1;
	_scaley = 1;
}

int ConfigImage::getImgWidth(){
	return _wimg;
}
int ConfigImage::getImgHeight(){
	return _himg;
}
void ConfigImage::getImgSize(int& width, int& height){
	width = _wimg;
	height = _himg;
}
float ConfigImage::getScaleX(){
	return _scalex;
}
float ConfigImage::getScaleY(){
	return _scaley;
}
void ConfigImage::getScale(float& scalex, float& scaley){
	scalex = _scalex;
	scaley = _scaley;
}

ConfigImage& ConfigImage::setImgWidth(const int width){
	_wimg = width;
	return *this;
}
ConfigImage& ConfigImage::setImgHeight(const int height){
	_himg = height;
	return *this;
}
ConfigImage& ConfigImage::setImgSize(const int width, const int height){
	_wimg = width;
	_himg = height;
	return *this;
}
ConfigImage& ConfigImage::setScaleX(const float scalex){
	_scalex = scalex;
	return *this;
}
ConfigImage& ConfigImage::setScaleY(const float scaley){
	_scaley = scaley;
	return *this;
}
ConfigImage& ConfigImage::setScale(const float scalex, const float scaley){
	_scalex = scalex;
	_scaley = scaley;
	return *this;
}

void ConfigImage::calculateRatio(){
	if (_wimg == 0 || _himg == 0){
		_scalex = 0;
		_scaley = 0;
	}
	else{
		_scalex = _wimg > _himg ? fabsf(((float)_wimg) / _himg) : 1;
		_scaley = _himg > _wimg ? fabsf(((float)_himg) / _wimg) : 1;
	}
}
