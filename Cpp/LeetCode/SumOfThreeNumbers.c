// Find all triples from the given array that satisfy nums[i] + nums[j] + nums[k] == 0

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int icomp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	int **triple = malloc(sizeof(int *) * numsSize * 10);
	int i, j, l, mid, r, val, *blk;
	qsort(nums, numsSize, sizeof(int), icomp);
	*returnSize = 0;
	if (nums[numsSize - 1] >= 0)
		for (i = 0; i < numsSize - 2 && nums[i] <= 0; i++)
		{
			for (j = numsSize - 1; j > i + 1 && nums[j] >= 0; j--)
			{
				val = -nums[i] - nums[j];
				if (nums[j - 1] < val || nums[i + 1] > val)
					continue;
				for (l = i + 1, r = j - 1; l <= r;)
				{
					mid = (l + r) / 2;
					if (nums[mid] > val)
						r = mid - 1;
					else if (nums[mid] < val)
						l = mid + 1;
					else
					{
						blk = malloc(3 * sizeof(int));
						blk[0] = nums[i];
						blk[1] = nums[mid];
						blk[2] = nums[j];
						triple[*returnSize] = blk;
						(*returnSize)++;
						break;
					}
				}
				while (j > i + 1 && nums[j - 1] == nums[j])
					j--;
			}
			while (i < numsSize - 2 && nums[i + 1] == nums[i])
				i++;
		}
	if (*returnSize)
	{
		*returnColumnSizes = malloc(sizeof(int) * (*returnSize));
		for (i = 0; i < *returnSize; i++)
			returnColumnSizes[0][i] = 3;
	}
	return triple;
}

int main(void)
{
	int arr[] = {0, 0, 0}, returnSize, *returnColumnSizes;
	int **res = threeSum(arr, 3, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < returnColumnSizes[i]; j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
