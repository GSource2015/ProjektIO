
#include "FileTMReader.h"
#include <wx/colour.h>
#include <wx/wx.h>


FileTMReader::FileTMReader(string path) : FileTM(path){
}

Theme FileTMReader::readTheme(){
	_file = fopen(_path.c_str(), "rb");
	if (!_file){
		throw FileException(_path);
	}		
	unsigned char buff[2];
	fread(buff, 1, 2, _file);	
	if (_header[1] != buff[0] || _header[0] != buff[1]){
		fclose(_file);
		throw FileException(_path);
	}	
	fread(buff, 1, 2,_file);	
	Theme thm = getTheme();
	thm.setTheme((Theme::main_theme)buff[0]);
	thm.isDefault = buff[1];

	fclose(_file);
	return thm;
}

Level FileTMReader::readMap(){
	_file = fopen(_path.c_str(), "rb");
	if (!_file){
		throw FileException(_path);
	}
	unsigned char buff[255];
	fread(buff, 1, 3, _file);
	if (_header[0] != buff[0] || _header[1] != buff[1]){
		fclose(_file);
		throw FileException(_path);
	}
	//wxLogError("%d", buff[2]);
	fread(buff, 1, buff[2], _file);
	string name = (char*)buff;
	
	fread(buff, 1, 2, _file);
	//wxLogError("%d, %d", buff[0], buff[1]);
	unsigned char w = buff[0];
	unsigned char h = buff[1];
	Level lvl(w, h);
	lvl.setName(name);
	Board& brd = lvl.getBoard();
	
	fread(buff, 1, w*h,_file);
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			brd(j, i, buff[i*w + j]);
		}
	}
	fread(buff, 1, 2,_file);	
	Theme& thm = lvl.getTheme();
	bool def = buff[1];
	if (!def)
		thm = getTheme();
	thm.setTheme((Theme::main_theme)buff[0]);
	thm.isDefault = def;
	fclose(_file);
	return lvl;
	

}

Theme FileTMReader::getTheme(){
	Theme thm;
	unsigned long col;
	unsigned char buff[255];
	fread(buff, 1, 1, _file);
	fread(buff, 1, buff[0], _file);
	string name = (char *)buff;
	
	fread(buff, 1, 2, _file);
	//Tutaj kod na wcztytywanie obrazka
	fread(&col, sizeof(unsigned long), 1, _file);
	thm.loadBackground(col);
	fread(buff, 1, 2, _file);
	//Tutaj kod na wcztytywanie obrazka
	fread(&col, sizeof(unsigned long), 1, _file);
	thm.loadWalls(col);
	for (int i = 0; i < 6; ++i){
		fread(buff, 1, 2, _file);
		//Tutaj kod na wcztytywanie obrazka
		fread(&col, sizeof(unsigned long), 1, _file);
		thm.loadFloor(i, col);
	}
	thm.setName(name);
	return thm;
}
