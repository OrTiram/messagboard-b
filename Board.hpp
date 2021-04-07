#include "Direction.hpp"
#include <string>
#include <map>
#include <climits>

namespace ariel{
	class Board{
		private:
		
        std::map<unsigned int, std::map<unsigned int, char>> board;
        unsigned int lower_row;//min row
        unsigned int lower_col;//min col
        unsigned int upper_row;//max row
        unsigned int upper_col;//max col

		
		public:
		
		Board();
		~Board();
		
		void post(unsigned int row, unsigned int col, Direction d, const std::string &mes);
		
		std::string read(unsigned int row, unsigned int col, Direction d, unsigned int len);
		
		void show();
	};
};