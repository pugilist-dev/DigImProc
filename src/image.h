#pragma once
#include <vector>
#include <string>

namespace irw {
	class Image{
		public :
			Image(){};
			Image(const unsigned int& cols, const unsigned int& rows): cols_(cols), rows_(rows) {			}
			int rows() const {return rows_;}
			int cols() const {return cols_;}
			bool ReadPgm(const std::string& filename);
			bool WritePgm(const std::string& filename) const;
		protected :
			std::string magic_number_;
			unsigned int cols_=0, rows_=0,max_color_=0;
			struct pixels_{
				unsigned int r,g,b;
			};
			std::vector<pixels_> data_;

	};
}// namespace irw
