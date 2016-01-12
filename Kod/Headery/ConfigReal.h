#ifndef _CONFIGREAL_H_
#define _CONFIGREAL_H_

class ConfigReal{
public:
	ConfigReal(const float xmin = -1, const float ymin = -1, const float xmax = 1, const float ymax = 1, const float camx = 0, const float camy = 0, const float zoom = 1);

	ConfigReal& setXMin(const float xmin);
	ConfigReal& setXMax(const float xmax);
	ConfigReal& setYMin(const float ymin);
	ConfigReal& setYMax(const float ymax);
	ConfigReal& setCoords(const float xmin, const float ymin, const float xmax, const float ymax);
	ConfigReal& setCamX(const float camx);
	ConfigReal& setCamY(const float camy);
	ConfigReal& setCamera(const float camx, const float camy);
	ConfigReal& setZoom(const float zoom);

	float getXMin() const;
	float getXMax() const;
	float getYMin() const;
	float getYMax() const;
	void getCoords(float &xmin, float &ymin, float &xmax, float &ymax) const;
	float getCamX() const;
	float getCamY() const;
	void getCamera(float &camx, float &camy) const;
	float getZoom() const;

protected:
	float _xmin, _ymin, _xmax, _ymax;
	float _camx, _camy, _zoom;
};

#endif
