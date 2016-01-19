#include "FileTM.h"

FileTM::FileTM(string path) : _path(path){
	_header[0] = 0xAD;
	_header[1] = 0xDA;
}
bool FileTM::isAssociated(){
	return !_path.empty();

}
void FileTM::setPath(const string &path){
	_path = path;
}
void FileTM::setPath(const char *path){
	_path = path;
}
void FileTM::getPath(const string &path){
	_path = path;
}
