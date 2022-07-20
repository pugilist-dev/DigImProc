#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <image.h>
using std::cout; using std::endl;

int main(){
	irw::Image img;
	bool status = false;
	cout << "Image size: " << img.rows() << " " <<img.cols()<< endl;

	std::string file_name = "/home/raj/Documents/experiments/cpp_igor_ubonn/experiments/DigImProc/data/pbmlib.ascii.ppm";
    std::string down2_name = "/home/raj/Documents/experiments/cpp_igor_ubonn/experiments/DigImProc/data/pbmlib.ascii_down.ppm";

    status = img.ReadPgm(file_name);
    if (status){
    	cout << "Image was read successfully"<< endl;
    	status = false;
    }
    else{
    	cout << " failed to read the image"<< endl;
    }

    cout << "Image read of size: " << img.rows() << " " << img.cols()<< endl;
    status = img.WritePgm(down2_name);
    if (status){
    	cout << "Image was written successfully"<< endl;
    	status = false;
    }
    else{
    	cout << " failed to write the image"<< endl;
    }

    return 0;
}