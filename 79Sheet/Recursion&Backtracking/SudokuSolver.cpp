#include <vector>
using namespace std;

class Solution
{
public:
    bool issafe(int row, int col, vector<vector<char>> &board, char val)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
            if (board[i][col] == val)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (issafe(row, col, board, val))
                        {
                            board[row][col] = val;
                            bool solutionpossible = solve(board);
                            if (solutionpossible)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};