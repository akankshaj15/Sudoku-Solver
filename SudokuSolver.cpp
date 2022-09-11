#include <bits/stdc++.h>

using namespace std;
//global Matrix
int n=9;
int mat[9][9];

bool is_possible(int row,int col,int opt){
	//check rows and cols
	for(int i=0;i<n;i++){
		if(mat[i][col]==opt or mat[row][i]==opt){
			return false;
		}
	}
	//now check sub grid;
	//for subgrid (row/3)*3 and (col/3)*3 
	int start_indexRow = (row/3)*3;
	int start_indexCol = (col/3)*3;

	for(int i=start_indexRow;i<start_indexRow+3;i++){
		for(int j=start_indexCol;j<start_indexCol+3;j++){
			if(mat[i][j]==opt){
				return false;
			}
		}
	} 

	// at last
	return true;
}

bool solveSudoku(int row,int col){
	if(row==n){
		//sudokus olved
		return true;
	}
	if(col==n){
		//last col
		return solveSudoku(row+1,0);
	}
	if(mat[row][col]!=0){
		//if already filled continue
		return solveSudoku(row,col+1);
	}
	//now must be filed
	for(int opt=1;opt<=9;opt++){
		if(is_possible(row,col,opt)){
			mat[row][col]=opt;
			bool rest_suduko=solveSudoku(row,col+1);
			if(rest_suduko){
				return true;
			}
			//backtrack
			mat[row][col]=0;
		}
	}

	// at last
	return false;
}

int main(){	
	cout<<"ENTER the SUDOKU in Desird Format"<<endl;
	//enter the Sudoku Matrix to be solved where Blank Spaces == 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}

	bool ans=solveSudoku(0,0);

	if(ans){
		cout<<endl;
		cout<<"Here is the Solution:-"<<endl;
		//print
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}else{
		cout<<"NOT POSSIBLE TO SOLVE"<<endl;
	}

	return 0;
}
