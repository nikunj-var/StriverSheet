class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);
        }
        int i = 0;
        while (i < (nums.size() - k))
        {
            q.pop();
            i++;
        }
        return q.top();
    }
};