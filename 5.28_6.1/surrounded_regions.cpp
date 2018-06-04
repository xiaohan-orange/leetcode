#include<vector>
#include<iostream>
using namespace std;
void help(vector<vector<char>>& board,int i,int j){
	if(board[i][j]=='O'){
		board[i][j]='$';
		if(i>0&&board[i-1][j]=='O'){
			help(board,i-1,j);
		}
		if(j<board[i].size()-1&&board[i][j+1]=='O'){
			help(board,i,j+1);
		}
		if(i<board.size()-1&&board[i+1][j]=='O'){
			help(board,i+1,j);
		}
		if(j>0&&board[i][j-1]=='O'){
			help(board,i,j-1);
		}
	}
}
void solve(vector<vector<char>>& board){
	if(board.empty()||board[0].empty()){
		return;
	}
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if((i==0||j==0||i==board.size()-1||j==board[i].size()-1)
					&&board[i][j]=='O'){
				help(board,i,j);
			}
		}
	}
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			if(board[i][j]=='O'){
				board[i][j]='X';
				continue;
			}
			if(board[i][j]=='$'){
				board[i][j]='O';
			}
		}
	}
}

int main(){
	vector<vector<char>> board={
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'}
	};
	solve(board);
	for(auto &a:board){
		for(auto &b:a){
			cout<<b<<" ";
		}
		cout<<endl;
	}
	return 0;
}
