#include "FileException.h"

FileException::FileException(std::string path) throw(){
	_path = path;
}
FileException::~FileException() throw(){

}
const char* FileException::what() const throw(){
	return "File couldn't be opened, or wrong data inside or wrong name";
}

std::string FileException::getPath() const throw(){
	return _path;
}
