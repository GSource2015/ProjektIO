#ifndef _MAPIMAGE_H_
#define _MAPIMAGE_H_
#include "ConfigImage.h"
#include "ConfigReal.h"
#include "Level.h"
#include <wx/image.h>
class MapImage : public ConfigImage, public ConfigReal{
public:
	MapImage(const int wimg = 0, const int himg = 0, const float xmin = -1, const float ymin = -1, const float xmax = 1, const float ymax = 1, const float camx = 0, const float camy = 0, const float zoom = 1);
	MapImage(Level& map, const int wimg = 0, const int himg = 0);
	wxImage drawMap(Level& map);
	void adjustParameters(Level& map);
};

#endif
