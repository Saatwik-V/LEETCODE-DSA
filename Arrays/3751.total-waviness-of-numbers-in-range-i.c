/*
 * @lc app=leetcode id=3751 lang=c
 *
 * [3751] Total Waviness of Numbers in Range I
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//total-waviness-of-numbers-in-range-i
//Time Complexity: O(n * m) where n is the number of integers in the range [num1, num2] and m is the number of digits in the largest number in the range. This is because we need to iterate through each integer in the range and for each integer, we need to check its digits to determine if it is a "wavy" number.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store intermediate variables and the result.
//Approach: We can iterate through each integer in the range [num1, num2] and check if it is a "wavy" number. A "wavy" number is defined as a number where each digit is either greater than both of its neighbors or less than both of its neighbors. To check if a number is "wavy", we can extract its digits and compare each digit with its neighbors. We can use an array to store the digits of the number and then iterate through the array to check the "waviness" condition. If a number is found to be "wavy", we can increment our result counter. Finally, we return the total count of "wavy" numbers in the range.      
#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void reverse(int *nums,int l,int r)
{
    while(l<r)
    {
        swap(&nums[l],&nums[r]);
        l++;
        r--;
    }
}



int totalWaviness(int num1, int num2) {
    int result=0,s,k=0,temp;
    int *c=(int*)malloc(6*sizeof(int));
    for(int i=num1;i<=num2;i++)
    {
        k=0;
        temp=i; 
        while(temp>0)
        {
            s=temp%10;
            c[k]=s;
            k++;
            temp=temp/10;
        }
        reverse(c,0,k-1);
        for(int i=1;i<k-1;i++)
        {
            if((c[i]>c[i-1]&&c[i]>c[i+1])||(c[i]<c[i-1]&&c[i]<c[i+1]))
            {
                result+=1;
            }
        }
    }
    return result;
}
// @lc code=end

