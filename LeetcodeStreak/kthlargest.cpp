#include <iostream>
#include <queue>
using namespace std;
class KthLargest
{
public:
    priority_queue<int> q;
    int size;
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            q.push(-nums[i]);
            if (q.size() > size)
            {
                q.pop();
            }
        }
    }

    int add(int val)
    {
        q.push(-val);
        if (q.size() > size)
        {
            q.pop();
        }
        return -q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */