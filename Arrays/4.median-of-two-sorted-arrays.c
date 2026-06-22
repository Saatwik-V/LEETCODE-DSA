/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
//Arrays
//median-of-two-sorted-arrays
//Time Complexity: O(m+n) where m is the size of nums1 and n is the size of nums2. We are merging both arrays into a new array, which takes linear time     
//Space Complexity: O(m+n) where m is the size of nums1 and n is the size of nums2. We are creating a new array to store the merged elements, which requires additional space proportional to the combined size of the input arrays.        
//Approach: We can merge the two sorted arrays into a new array while maintaining the sorted order. We use two pointers to traverse both arrays and compare their elements, adding the smaller element to the new array. Once we have merged both arrays, we can calculate the median based on the total number of elements in the merged array. If the total number of elements is odd, the median is the middle element. If it is even, the median is the average of the two middle elements.     
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m=nums1Size,i=0,j=0,k=0;
    int n=nums2Size;
    int *a=(int *)malloc((m+n)*sizeof(int));
    while(i<m&&j<n)
    {
        if(nums1[i]<nums2[j])
        {
            a[k]=nums1[i];
            i++;
        }
        else{
            a[k]=nums2[j];
            j++;
        }
        k++;
    }
    if(i>=m)
    {
        while(j<n)
        {
            a[k]=nums2[j];
            j++;
            k++;
        }
    }
    else{
        while(i<m)
        {
            a[k]=nums1[i];
            i++;
            k++;

        }
    }
    double res=0;
if(k%2==0)
{
    res=(a[k/2-1]+a[k/2])/2.0;
}
else{
    res=a[(k-1)/2];
}
return res;
    
}
// @lc code=end

