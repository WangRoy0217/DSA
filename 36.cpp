/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

*/


#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char input;
        cout<<board.size();
        for(int i=0;i<9;i++)
        {
            bool col[9] = {false};
            bool row[9] = {false};
            bool blocks[9] = {false};
            for(int j=0;j<9;j++)
            {
                input = board[i][j];
                if(input != '.')
                {
                    if(col[input - '1'])
                        return false;
                    col[input - '1'] = true;
                }

                input = board[j][i];
                if(input != '.')
                {
                    if(row[input - '1'])
                        return false;
                    row[input - '1'] = true;
                }
                

                input = board[((i/3)*3 + j/3)][((i%3)*3) + j%3];
                if(input != '.')
                {
                    if(blocks[input - '1'])
                        return false;
                    blocks[input - '1'] = true;
                }
            }
        }
        return true;
    }
};
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //M1-Imp 1 traverse. better bitmasking
        int N = board.size();
        vector<int> row(N), coln(N), box(N); //bitmask for each of the 3 rules to check
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') continue;

                int curr = 1 << (board[i][j] - '0' - 1);
                cout<<i<<","<<j<<" "<<board[i][j]<<", "<<curr;
                if (row[i] & curr) return false;
                row[i] |= curr;
                //cout<<","<<row[i]<<endl;
                
                if (coln[j] & curr) return false;
                coln[j] |= curr;
                //cout<<",//"<<coln[j]<<endl;
                
                if (box[(i/3) * 3 + j / 3] & curr) return false;
                box[(i/3) * 3 + j / 3] |= curr;
                cout<<",//"<<(i/3) * 3 + j / 3<<endl;
            }
        }
        return true;
    }
};
int main()
{
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','5','.','.','.','.','6','.'},
        {'5','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    Solution s;
    cout<<s.isValidSudoku(board);
    
    
}