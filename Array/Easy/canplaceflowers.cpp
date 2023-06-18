#include <vector>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        if (flowerbed.size() == 1 && n == 1 && flowerbed[0] == 0)
        {
            return true;
        }
        int count = 0;
        if (flowerbed.size() >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            count++;
            flowerbed[0] = 1;
        }
        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0)
        {
            count++;
            flowerbed[flowerbed.size() - 1] = 1;
        }
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i > 0 && i < flowerbed.size() && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        if (count >= n)
        {
            return true;
        }
        return false;
    }
};