

void moveZeroes(int *nums, int numsSize)
{
    int i = 0, j = 0;
    int temp;
    while (i < numsSize)
    {
        if (nums[i] != 0)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
        i++;
    }
}