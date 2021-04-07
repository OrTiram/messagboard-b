#include "Board.hpp"
#include <iostream>
using namespace std;

namespace ariel{

        Board::Board(){
        lower_row = UINT_MAX;
        lower_col = UINT_MAX;
        upper_row = 0;
        upper_col = 0;
        }

        Board:: ~Board(){

        }
				
		void Board::post(unsigned int row, unsigned int col, Direction d, const string &mes ){
			if(mes.empty()){
				return;
		}
		if(row < this->lower_row){
			this->lower_row = row;
		}
		
		if(col < this->lower_col){
			this->lower_col = col;
		}
		
		if(d == Direction :: Horizontal){
			if(this->upper_row < row){
				this->upper_row = row;
			}
			
			if(this->upper_col < col + mes.length() - 1){
				this->upper_col = col + mes.length() - 1;
			}
			
			for(unsigned int i = 0, c = col; i < mes.length(); i++, c++){
				this->board[row][c] = mes.at(i);
			}
		}
		
		else{
			if(this->upper_col < col){
				this -> upper_col = col;
			}
			
			if(this->upper_row < row + mes.length() -1){
				this -> upper_row = row + mes.length() -1;;
			}
			
			for(unsigned int i = 0, r = row; i < mes.length(); i++, r++){
				this->board[r][col] = mes.at(i);
			}
		}
	}	
		
		string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int len){
			string ans;
			if(d == Direction :: Horizontal){
				for(unsigned int i = 0, c = col; i < len; c++, i++){
					if(this->board[row][c] == 0){
                        ans += '_';
					}
					else{
					    ans += board[row][c];

					}
				}
			}
			else{
				for(unsigned int i = 0, r = row; i < len; r++, i++){
					if(this->board[r][col] == 0){
                        ans += '_';
					}
					else{
						ans+=board[r][col] ;
					}
				}
			}
			return ans;
				
		}
		
		void Board::show(){
			for(unsigned int i = this->lower_row; i <= upper_row; i++){
				for(unsigned int j = this->lower_col; j <= upper_col; j++){
					if(this-> board [i][j] == 0){
                        cout<< '_';
					}
					else{
						cout << this->board [i][j];
					}
				}
				cout << endl;
			}
		}
	
};