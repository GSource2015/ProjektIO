#include "CustomPanelEditor.h"


CustomPanelEditor::CustomPanelEditor(wxWindow *parent,
            wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            long style,
            const wxString& name):wxPanel(parent, winid, pos, size, style, name){
	_map = NULL;

	_drag = false;
}
CustomPanelEditor::~CustomPanelEditor(){
	if(_map != NULL)
		delete _map;
}

void CustomPanelEditor::mouseMove(wxMouseEvent& event){
	_x = event.GetPosition().x;
	_y = event.GetPosition().y;
	_img.updateActiveField(_x, _y);
	_can_click = false;	
	if(event.Dragging() && _drag){
		_img.moveCamera(_x, _y, _prev_x, _prev_y);
		_prev_x = _x;
		_prev_y = _y;
	}
	event.Skip();
}

MapImage& CustomPanelEditor::getMapImage(){
	return _img;
}
Level* CustomPanelEditor::getLevel(){
	return _map;
}
int CustomPanelEditor::getMouseX(){
	return _x;
}
int CustomPanelEditor::getMouseY(){
	return _y;
}
void CustomPanelEditor::getMousePos(int& x, int& y){
	x = _x;
	y = _y;
}


void CustomPanelEditor::mouseWheel(wxMouseEvent& event){
	int rot = event.GetWheelRotation();
	_img.zoomPercent(rot / 1000.0);
	event.Skip();
}

void CustomPanelEditor::mouseLDown(wxMouseEvent& event){
	_drag = true;
	_can_click = true;
	_prev_x = event.GetPosition().x;
	_prev_y = event.GetPosition().y;
	event.Skip();
}
void CustomPanelEditor::mouseRDown(wxMouseEvent& event){
	_can_click = true;
}

void CustomPanelEditor::mouseLUp(wxMouseEvent& event){
	if (_map != NULL){
		if (_can_click && !event.Dragging() && _img.getActiveX() != -1 && _img.getActiveY() != -1){
			Board& brd = _map->getBoard();
			int val = brd(_img.getActiveX(), _img.getActiveY());
			if (val < 5){
				brd(_img.getActiveX(), _img.getActiveY(), val + 1);
			}
		}
	}
	_drag = false;
	_can_click = true;
	event.Skip();
}

void CustomPanelEditor::mouseRUp(wxMouseEvent& event){
	if (_map != NULL){
		if (_can_click && !event.Dragging() && _img.getActiveX() != -1 && _img.getActiveY() != -1){
			Board& brd = _map->getBoard();
			int val = brd(_img.getActiveX(), _img.getActiveY());
			if (val > -1){
				brd(_img.getActiveX(), _img.getActiveY(), val - 1);
			}
		}
	}
	_can_click = true;
	event.Skip();
}

void CustomPanelEditor::setLevel(Level *lvl){
	
	if(_map != NULL){
//		delete _map;
	}
	_map = lvl;
	if (_map != NULL){
		_img.calculateRatio();
		_img.adjustParameters(*_map);
	}
}

