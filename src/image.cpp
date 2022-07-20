#include "image.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <string>

using std::ifstream;
using std::endl;
using std::ofstream;
using std::cout;

namespace irw{
	bool Image::ReadPgm(const std::string& filename){
		ifstream fin;
		cout << filename.c_str() << endl;
		fin.open(filename, std::ios::binary);
		if (fin.is_open()){
			if (fin.fail()){throw("Can't open input file");}
			fin >> magic_number_;
			if(magic_number_.compare("P3")!= 0) {throw("Can't read the input file");}
		
			fin.get();
			fin >> cols_;
			fin >> rows_;
		
			Image(cols_, rows_);

			fin.get();
			fin >> max_color_;

			fin.get();
			for (unsigned int i=0; i<cols_*rows_; ++i){
				pixels_ pixel;
				fin >> pixel.r >> pixel.g >> pixel.b;
				data_.push_back(pixel);
			}
			fin.close();
			}
		else{ 
        	fin.close();
			return false; 
		}
		return true;
	}

	bool Image::WritePgm(const std::string& filename) const {
		ofstream fin;
		fin.open(filename, ifstream::out);
		if(fin.is_open()){
			fin << magic_number_<< endl;
			fin << cols_ << " "<< rows_ << endl;
			fin << max_color_ << " " << endl;

			for (unsigned int i=0; i<cols_*rows_; ++i){
				fin << data_[i].r << " " << data_[i].g << " " << data_[i].b << " ";
			}
			fin.close();
		}
		else{
			fin.close();
			return false;
		}
		return true;

	}
}