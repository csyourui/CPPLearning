////
////  test.cpp
////  test
////
////  Created by yourui on 2020/2/19.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <vector>
//using namespace std;
//
//bool validSudoku(vector<vector<char> > &board,int i, int j, char a) {
//    int x = 3*(i/3);
//    int y = 3*(j/3);
//    for(int k = 0; k < 9; k++){
//        if(board[i][k] == a) return false;
//        if(board[k][j] == a) return false;
//        if(board[x+k/3][y+k%3] == a) return false;
//    }
//    return true;
//}
//
//bool solveSudoku(vector<vector<char> >& board,int i, int j) {
//    if(i == 9) return true;
//    if(j == 9) return solveSudoku(board,i+1,0);
//    if(board[i][j] != '.') return solveSudoku(board,i,j+1);
//    
//    for(char c = '1'; c <= '9'; c++)
//    {
//        if(validSudoku(board, i, j, c))
//        {
//            board[i][j] = c;
//            if(solveSudoku(board, i, j+1)){
//                return true;
//            }
//            board[i][j] = '.';
//        }
//    }
//    return false;
//}
//void show(vector<vector<char> > &board){
//    for (int i = 0; i < board.size(); ++i)
//    {
//        for (int j = 0; j < board[0].size(); ++j)
//        {
//           printf("%c ",board[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main(){
//    vector<vector<char> > board = {
//        {'.','.','.','.','.','.','.','6','2'},
//        {'.','.','.','.','.','7','3','8','.'},
//        {'8','.','.','6','1','3','.','.','.'},
//        {'.','6','.','3','.','.','1','.','5'},
//        {'1','.','.','4','2','9','.','.','.'},
//        {'3','.','.','.','6','1','.','9','.'},
//        {'.','9','.','8','.','.','5','.','7'},
//        {'.','.','.','7','.','.','9','3','.'},
//        {'.','5','.','.','.','.','8','.','.'}};
//    show(board);
//    solveSudoku(board,0,0);
//    show(board);
//}
