int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    int **res = malloc(sizeof(int *) * numsSize * 10);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i && nums[i] == nums[i - 1])
            continue;
        for (int j = numsSize - 1; j >= i + 3; j--)
        {
            if (j < numsSize - 1 && nums[j] == nums[j + 1])
                continue;
            int l = i + 1, r = j - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r] + nums[j];
                if (sum > target)
                    do
                    {
                        r--;
                    } while (l < r && nums[r] == nums[r + 1]);
                else if (sum < target)
                    do
                    {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                else
                {
                    int *t = malloc(sizeof(int) * 4);
                    t[0] = nums[i];
                    t[1] = nums[l];
                    t[2] = nums[r];
                    t[3] = nums[j];
                    res[(*returnSize)++] = t;
                    do
                    {
                        r--;
                    } while (l < r && nums[r] == nums[r + 1]);
                    do
                    {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                }
            }
        }
    }
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 4;
    return res;
}

int main()
{
    int nums[] = {2, 4, 0, 4, -3, -3}, numsSize = 6, target = 0, returnSize, *returnColumnSizes;
    int **result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
}