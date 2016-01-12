#include "MapImage.h"

MapImage::MapImage(const int wimg, const int himg, const float xmin, const float ymin, const float xmax, const float ymax, const float camx, const float camy, const float zoom) :
ConfigImage(wimg, himg), ConfigReal(xmin, ymin, xmax, ymax, camx, camy, zoom){
}
MapImage::MapImage(Level& map, const int wimg, const int himg) : ConfigImage(wimg, himg){
	adjustParameters(map);
}
wxImage MapImage::drawMap(Level& map){

}

void MapImage::adjustParameters(Level& map){
	Board& board = map.getBoard();
	int w, h;
	board.getSize(w, h);
	_xmin = -(w / 2.0f);
	_ymin = -(h / 2.0f);
	_xmax = w / 2.0f;
	_ymax = h / 2.0f;
	_camx = 0;
	_camy = 0;
	_zoom = 0;
}
