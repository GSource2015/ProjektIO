#include "ConfigReal.h"


ConfigReal::ConfigReal(const float xmin, const float ymin, const float xmax, const float ymax, const float camx, const float camy, const float zoom) :
_xmin(xmin), _ymin(ymin), _xmax(xmax), _ymax(ymax),
_camx(camx), _camy(camy), _zoom(zoom){

}

ConfigReal& ConfigReal::setXMin(const float xmin){
	_xmin = xmin;
	return *this;
}
ConfigReal& ConfigReal::setXMax(const float xmax){
	_xmax = xmax;
	return *this;
}
ConfigReal& ConfigReal::setYMin(const float ymin){
	_ymin = ymin;
	return *this;
}
ConfigReal& ConfigReal::setYMax(const float ymax){
	_ymax = ymax;
	return *this;
}
ConfigReal& ConfigReal::setCoords(const float xmin, const float ymin, const float xmax, const float ymax){
	_xmin = xmin;
	_ymin = ymin;
	_xmax = xmax;
	_ymax = ymax;
	return *this;
}
ConfigReal& ConfigReal::setCamX(const float camx){
	_camx = camx;
	return *this;
}
ConfigReal& ConfigReal::setCamY(const float camy){
	_camy = camy;
	return *this;
}
ConfigReal& ConfigReal::setCamera(const float camx, const float camy){
	_camx = camx;
	_camy = camy;
	return *this;
}
ConfigReal& ConfigReal::setZoom(const float zoom){
	_zoom = zoom;
	return *this;
}

float ConfigReal::getXMin() const{
	return _xmin;
}
float ConfigReal::getXMax() const{
	return _xmax;
}
float ConfigReal::getYMin() const{
	return _ymin;
}
float ConfigReal::getYMax() const{
	return _ymax;
}
void ConfigReal::getCoords(float &xmin, float &ymin, float &xmax, float &ymax) const{
	xmin = _xmin;
	ymin = _ymin;
	xmax = _xmax;
	ymax = _ymax;
}
float ConfigReal::getCamX() const{
	return _camx;
}
float ConfigReal::getCamY() const{
	return _camy;
}
void ConfigReal::getCamera(float &camx, float &camy) const{
	camx = _camx;
	camy = _camy;
}
float ConfigReal::getZoom() const{
	return _zoom;
}
