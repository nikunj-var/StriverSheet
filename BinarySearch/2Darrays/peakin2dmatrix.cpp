// steps
// Let's assume that the width of the array is bigger than the height, otherwise, we will split in another direction.
// Split the array into three parts: central column left side and right side.
// Go through the central column and two neighbor columns and look for maximum.
// If it's in the central column - this is our peak.
// If it's on the left side, run this algorithm on subarray left_side + central_column.
// If it's on the right side, run this algorithm on subarray right_side + central_column


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        int startcol = 0;
        int endcol = col - 1;
        vector<int> ans;
        while (startcol <= endcol)
        {
            int midcol = startcol + (endcol - startcol) / 2;
            int ansrow = 0;

            for (int i = 0; i < row; i++)
            {
                ansrow = (mat[i][midcol] >= mat[ansrow][midcol]) ? i : ansrow;
            }

            bool left = (midcol - 1 >= startcol) && (mat[ansrow][midcol] < mat[ansrow][midcol - 1]);
            bool right = (midcol + 1 <= endcol) && (mat[ansrow][midcol] < mat[ansrow][midcol + 1]);

            if (!left && !right)
            {
                ans.push_back(ansrow);
                ans.push_back(midcol);
                return ans;
            }
            else if (right)
            {
                startcol = midcol + 1;
            }
            else
            {
                endcol = midcol - 1;
            }
        }
        return {-1, -1};
    }
};