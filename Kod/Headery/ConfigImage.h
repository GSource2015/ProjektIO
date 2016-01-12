#ifndef _CONFIGIMAGE_H_
#define _CONFIGIMAGE_H_

class ConfigImage{
public:
	ConfigImage(const int wimg = 0, const int himg = 0);

	int getImgWidth();
	int getImgHeight();
	void getImgSize(int& width, int& height);
	float getScaleX();
	float getScaleY();
	void getScale(float& scalex, float& scaley);

	ConfigImage& setImgWidth(const int width);
	ConfigImage& setImgHeight(const int height);
	ConfigImage& setImgSize(const int width, const int height);
	ConfigImage& setScaleX(const float scalex);
	ConfigImage& setScaleY(const float scaley);
	ConfigImage& setScale(const float scalex, const float scaley);

	void calculateRatio();
protected:
	int _wimg, _himg;
	float _scalex, _scaley;
};

#endif
