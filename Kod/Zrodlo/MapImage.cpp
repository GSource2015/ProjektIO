#include "MapImage.h"
#include "Matrix2D.h"
#include <wx/wx.h>
#include <cmath>


//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start

MapImage::MapImage(const int wimg, const int himg, const float xmin, const float ymin, const float xmax, const float ymax, const float camx, const float camy, const float zoom) :
ConfigImage(wimg, himg), ConfigReal(xmin, ymin, xmax, ymax, camx, camy, zoom){
	_obramowanie = true;
	_thick = 0.3;
	_zoomx = 1;
	_zoomy = 1;
	_border = 0;
	_activex = -1;
	_activey = -1;
	_realx = 0;
	_realy = 0;
}
MapImage::MapImage(Level& map, const int wimg, const int himg) : ConfigImage(wimg, himg){
	adjustParameters(map);
	_obramowanie = true;
	_thick = 0.3;
	_zoomx = 1;
	_zoomy = 1;
	_border = 0;
	_activex = -1;
	_activey = -1;
	_realx = 0;
	_realy = 0;
}
void MapImage::drawMap(Level& map, wxDC& dc){
/*
	int wid, hei;
	Board& brd = map.getBoard();
	Theme& thm = map.getTheme();
	brd.getSize(wid, hei);

	dc.SetBackground(wxBrush(thm.getBackground()));
	dc.Clear();
	
	dc.SetPen(thm.getWalls());
	dc.SetBrush(thm.getWalls());

	
	Vector2D p1(0, 0);
	Vector2D p2(5, 5);
	p1.fit(_xmin, _ymin, _xmax, _ymax, 0, 0, _wimg - 1, _himg-1); 
	p2.fit(_xmin, _ymin, _xmax, _ymax, 0, 0, _wimg - 1, _himg-1); 
	
	dc.DrawLine(p1[0], p1[1], p2[0], p2[1]);	
*/
	Theme& thm = map.getTheme();

	dc.SetBackground(wxBrush(thm.getBackground()));
	dc.Clear();

	drawWalls(map, dc);
	drawFloor(map, dc);
 
			
	
}

void MapImage::adjustParameters(Level& map){
	Board& board = map.getBoard();
	int w, h;
	board.getSize(w, h);
	_xmin = -(w / 2.0f);
	_ymin = -(h / 2.0f);
	_xmax = w / 2.0f;
	_ymax = h / 2.0f;
	_border = _xmax > _ymax ? _xmax * 2 * 0.05 : _ymax * 2 * 0.05;
	_zoomx = _xmax < _ymax ? (_xmax + _border)/(_ymax + _border) : 1;
	_zoomy = _xmax > _ymax ? (_ymax + _border)/(_xmax + _border) : 1;
}

void MapImage::updateActiveField(int mouseX, int mouseY){
	Vector2D pos((float)mouseX, (float)mouseY);
	wxString str;

	pos.refit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
	Matrix2D transform(Matrix2D::getBasic());
	transform.translate(_camx, _camy).scale(1/(_zoom*_zoomx), 1/(_zoom*_zoomy));
	pos = transform*pos;
	_realx = pos[0];
	_realy = pos[1];
	bool cond1 = pos[0] >= _xmin + _thick/2 && pos[0] < _xmax + _thick/2.0;
	bool cond2 = pos[1] >= _ymin - _thick/2 && pos[1] < _ymax - _thick/2;
	
	if(cond1 && cond2){		
		pos[0] += _xmax - _thick/2.0;
		pos[1] += _ymax + _thick/2.0;
			
		float rx = pos[0] - int(pos[0]);
		float ry = pos[1] - int(pos[1]);	
		//if(rx >= _thick && ry >= _thick){
			_activex = pos[0];
			_activey =  pos[1];
		//}
//		else{
//			_activex = -1;
//			_activey = -1;
		}
//	}
	else{
		_activex = -1;
		_activey = -1;	
	}
}


	
void MapImage::drawWalls(Level& map, wxDC& dc){
	int wid, hei;
	Board& brd = map.getBoard();
	Theme& thm = map.getTheme();
	brd.getSize(wid, hei);
	Matrix2D transform(Matrix2D::getBasic());
	transform.scale(_zoom*_zoomx, _zoom*_zoomy).translate(-_camx, -_camy);	
	
	for (int h =0; h < hei; ++h){
		for (int w = 0; w < wid; ++w){
			int ind = brd(w, h);
			if (ind > -1){
				//Prostokaty ramki
				Vector2D p1(_xmin + w, _ymin + h + 1);
				Vector2D p2(_xmin + w + 1, _ymin + h + 1 - _thick);
				Vector2D p3(_xmin + w + _thick, _ymin + h);

				p1 = transform * p1;
				p2 = transform * p2;
				p3 = transform * p3;

				p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				p3.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				dc.SetPen(thm.getWalls());
				dc.SetBrush(thm.getWalls());
				dc.DrawRectangle(p1[0], p1[1], abs(p2[0]-p1[0])+1, abs(p2[1]-p1[1])+1);
				dc.DrawRectangle(p1[0], p1[1], abs(p3[0]-p1[0])+1, abs(p3[1]-p1[1])+1);
				

				if ((h > 0 && brd(w, h - 1) == -1) || h == 0){
					p1.setXY(_xmin + w, _ymin + h);
					p2.setXY(_xmin + w + 1 + _thick, _ymin + h - _thick);
					p1 = transform * p1;
					p2 = transform * p2;
					p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					dc.DrawRectangle(p1[0], p1[1], abs(p2[0]-p1[0]), abs(p2[1]-p1[1])+1);
				}

				if ((w < wid-1 && brd(w + 1, h) == -1) || w == wid - 1){
					p1.setXY(_xmin + 1 + w, _ymin + 1 + h);
					p2.setXY(_xmin + w + 1 + _thick, _ymin + h - _thick);
					p1 = transform * p1;
					p2 = transform * p2;

					p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					dc.DrawRectangle(p1[0], p1[1], abs(p2[0]-p1[0])+1, abs(p2[1]-p1[1]));
				}
				if(h == 0 && w == wid - 1){
					p1.setXY(_xmax, _ymin);
					p2.setXY(_xmax+_thick, _ymin-_thick);
					p1 = transform * p1;
					p2 = transform * p2;
					p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					dc.DrawRectangle((p1[0]), p1[1], abs(p2[0]-p1[0])+1, abs(p2[1]-p1[1])+1);					
				}
				if(_obramowanie){
					p1.setXY(_xmin, _ymin - _thick);
					p2.setXY(_xmin, _ymax);
					p3.setXY(_xmax + _thick, _ymax);
					Vector2D p4(_xmax + _thick, _ymin - _thick);
					
					p1 = transform * p1;
					p2 = transform * p2;
					p3 = transform * p3;
					p4 = transform * p4;
					p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					p3.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					p4.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
					dc.SetPen(wxColour("Black"));
					dc.DrawLine(p1[0], p1[1], p2[0], p2[1]);
					dc.DrawLine(p2[0], p2[1], p3[0], p3[1]);
					dc.DrawLine(p3[0], p3[1], p4[0], p4[1]);
					dc.DrawLine(p4[0], p4[1], p1[0], p1[1]);
												
				}
			}
		}
	}		
}

void MapImage::drawFloor(Level& map, wxDC& dc){
	int wid, hei;
	Board& brd = map.getBoard();
	Theme& thm = map.getTheme();
	brd.getSize(wid, hei);
	Matrix2D transform(Matrix2D::getBasic());
	transform.scale(_zoom*_zoomx, _zoom*_zoomy).translate(-_camx, -_camy);	
	for (int h = 0; h < hei; ++h){
		for (int w = 0; w < wid; ++w){
			int ind = brd(w, h);
			if (ind > -1){
				Vector2D p1(_xmin + w + _thick, _ymin + h + 1 - _thick);
				Vector2D p2(_xmin + w + 1, _ymin + h);
				p1 = transform * p1;
				p2 = transform * p2;
				p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				dc.SetBrush(thm.getFloor(ind));
				if(_obramowanie)
					dc.SetPen(wxColour("Black"));
				else
					dc.SetPen(thm.getFloor(ind));
				dc.DrawRectangle(p1[0], p1[1], abs(p2[0]-p1[0])+1, abs(p2[1]-p1[1])+1);
			}
			if(h == _activey && w == _activex){
				Vector2D p1(_xmin + w + _thick, _ymin + h + 1 - _thick);
				Vector2D p2(_xmin + w + 1, _ymin + h + 1 - _thick);
				Vector2D p3(_xmin + w + 1, _ymin + h);
				Vector2D p4(_xmin + w + _thick, _ymin + h);
				p1 = transform * p1;
				p2 = transform * p2;
				p3 = transform * p3;
				p4 = transform * p4;				
				p1.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				p2.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				p3.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				p4.fit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, _wimg - 1, _himg - 1);
				dc.SetPen(wxColour("Yellow"));
				dc.DrawLine(p1[0], p1[1], p2[0], p2[1]);
				dc.DrawLine(p2[0], p2[1], p3[0], p3[1]);
				dc.DrawLine(p3[0], p3[1], p4[0], p4[1]);
				dc.DrawLine(p4[0], p4[1], p1[0], p1[1]);
				dc.SetPen(wxColour("White"));
				dc.DrawLine(p1[0]+1, p1[1]+1, p2[0]-1, p2[1]+1);
				dc.DrawLine(p2[0]-1, p2[1]+1, p3[0]-1, p3[1]-1);
				dc.DrawLine(p3[0]-1, p3[1]-1, p4[0]+1, p4[1]-1);
				dc.DrawLine(p4[0]+1, p4[1]-1, p1[0]+1, p1[1]+1);
				dc.SetPen(wxColour("Black"));
				dc.DrawLine(p1[0]-1, p1[1]-1, p2[0]+1, p2[1]-1);
				dc.DrawLine(p2[0]+1, p2[1]-1, p3[0]+1, p3[1]+1);
				dc.DrawLine(p3[0]+1, p3[1]+1, p4[0]-1, p4[1]+1);
				dc.DrawLine(p4[0]-1, p4[1]+1, p1[0]-1, p1[1]-1);					
			}
		}
	}		
}


int MapImage::getActiveX(){
	return _activex;
}
int MapImage::getActiveY(){
	return _activey;
}

float MapImage::getRealX(){
	return _realx;	
}
float MapImage::getRealY(){
	return _realy;
}
void MapImage::moveCamera(int mx, int my, int px, int py){
	Vector2D pos1((float)mx, (float)my);
	Vector2D pos2((float)px, (float)py);
	
	pos1.refit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, (_wimg - 1), (_himg - 1));
	pos2.refit((_xmin - _border)*_scalex, (_ymin - _border)*_scaley, (_xmax + _border)*_scalex, (_ymax + _border)*_scaley, 0, 0, (_wimg - 1), (_himg - 1));
	Matrix2D transform(Matrix2D::getBasic());
	transform.translate(_camx, _camy).scale(1/(_zoom*_zoomx), 1/(_zoom*_zoomy));	
	pos1 = transform*pos1;			
	pos2 = transform*pos2;
	_camx -= pos1[0] - pos2[0];
	_camy -= pos1[1] - pos2[1];
	if(_camx > (_xmax + 0.2*_xmax + _border)*_scalex)
		_camx = (_xmax + 0.2*_xmax + _border)*_scalex;
	if(_camx < (_xmin - 0.2*_xmax - _border)*_scalex)
		_camx =  (_xmin - 0.2*_xmax - _border)*_scalex;
	if(_camy > (_ymax + 0.2*_ymax + _border)*_scaley)
		_camy = (_ymax + 0.2*_ymax + _border)*_scaley;
	if(_camy < (_ymin - 0.2*_ymax - _border)*_scaley)
		_camy =  (_ymin - 0.2*_ymax - _border)*_scaley;
}	

void MapImage::zoomPercent(float perc){
	float tmp = _zoom + _zoom*perc;
	if(tmp >= 0.1 && tmp <= 10)
		_zoom = tmp;
}
