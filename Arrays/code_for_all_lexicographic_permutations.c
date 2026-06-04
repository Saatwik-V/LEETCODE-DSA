#include <stdio.h>

// swap function
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// reverse function
void reverse(int *nums, int l, int r)
{
    while (l < r)
    {
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }
}

// next permutation (same as yours)
int nextPermutation(int* nums, int numsSize)
{
    int index = -1;

    for(int i = numsSize - 2; i >= 0; i--)
    {
        if(nums[i] < nums[i+1])
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        reverse(nums, 0, numsSize - 1);
        return 0; // no more permutations
    }

    for(int i = numsSize - 1; i > index; i--)
    {
        if(nums[i] > nums[index])
        {
            swap(&nums[i], &nums[index]);
            break;
        }
    }

    reverse(nums, index + 1, numsSize - 1);
    return 1;
}

// simple sort (for starting permutation)
void sort(int *nums, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] > nums[j])
            {
                swap(&nums[i], &nums[j]);
            }
        }
    }
}

// print array
void printArray(int *nums, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

// generate all permutations
void generatePermutations(int *nums, int n)
{
    sort(nums, n); // start from smallest

    do {
        printArray(nums, n);
    } while(nextPermutation(nums, n));
}

// driver
int main()
{
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    generatePermutations(nums, n);

    return 0;
}