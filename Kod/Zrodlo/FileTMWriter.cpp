
#include "FileTMWriter.h"
#include <wx/colour.h>


FileTMWriter::FileTMWriter(string path ) : FileTM(path){
}

void FileTMWriter::writeTheme(Theme& thm){
	_file = fopen(_path.c_str(), "wb+");
	if (!_file){
		throw FileException(_path);
	}
	unsigned char header2[2] = {_header[1], _header[0]};
	fwrite(header2, 2, 1, _file);
	unsigned char thminfo[2] = {(unsigned char)thm.getTheme(), thm.isDefault};
	fwrite(thminfo, 1, 2, _file);
	appendTheme(thm);
	fclose(_file);
}

void FileTMWriter::writeMap(Level& lvl){
	_file = fopen(_path.c_str(), "wb+");
	if (!_file){
		throw FileException(_path);
	}
	Board& brd = lvl.getBoard();
	Theme& thm = lvl.getTheme();
	string name = lvl.getName();
	fwrite(_header, 2, 1, _file);
	
	unsigned char len = name.length()+1;
	fwrite(&len, 1, 1, _file);
	fwrite(name.c_str(), 1, len, _file);
	
	unsigned char size[2] = {brd.getWidth(), brd.getHeight()};
	fwrite(size, 1, 2, _file);
	
	for (int i = 0; i < size[1]; ++i){
		fwrite(brd._fields[i], 1, size[0], _file);
	}
	unsigned char thminfo[2] = {(unsigned char)thm.getTheme(), thm.isDefault};
	fwrite(thminfo, 1, 2, _file);
	if (thminfo[1] == false)
		appendTheme(thm);
	fclose(_file);

}

void FileTMWriter::appendTheme(Theme& thm){
	string name = thm.getName();
	unsigned char len = name.length()+1;
	fwrite(&len, 1, 1, _file);
	fwrite(name.c_str(), 1, len, _file);
	
	unsigned char rozm[2] = {0, 0};
	fwrite(rozm, 1, 2, _file);
	unsigned long col = thm.getBackground().GetRGB();
	fwrite(&col, sizeof(unsigned long), 1, _file);
	fwrite(rozm, 1, 2, _file);
	col = thm.getWalls().GetRGB();
	fwrite(&col, sizeof(unsigned long), 1, _file);
	for (int i = 0; i < 6; ++i){	
		fwrite(rozm, 1, 2, _file);	
		col = thm.getFloor(i).GetRGB();
		fwrite(&col, sizeof(unsigned long), 1, _file);
	}
}
