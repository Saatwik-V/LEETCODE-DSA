/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start

//Strings
//find-the-index-of-the-first-occurrence-in-a-string        
//Time Complexity: O(n*m) where n is the length of haystack and m is the length of needle. In the worst case, we may have to compare each character of haystack with each character of needle, leading to O(n*m) time complexity.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the variables used in the function. We are not using any additional data structures that grow with the input size.
//Approach: We can iterate through each character of haystack and compare it with the corresponding character of needle. If we find a mismatch, we can break out of the inner loop and continue checking from the next character in haystack. If we successfully match all characters of needle, we can return the starting index of the match in haystack. If we reach the end of haystack without finding a match, we can return -1 to indicate that needle is not present in haystack. We can also use the Boyer-Moore algorithm to optimize the search by skipping unnecessary comparisons based on the characters in needle and their positions in haystack. This involves creating a shift table that tells us how far to skip ahead in haystack when a mismatch occurs, allowing us to avoid checking characters that we know cannot match. The shift table is constructed based on the last occurrence of each character in needle, and we can use it to efficiently search for needle in haystack.
void shifttable(char* needle,int **a)
{
    int m=strlen(needle);
    
    for(int i=0;i<26;i++)
    {
        (*a)[i]=m;
    }
    for(int i=0;i<m-1;i++)
    {
        (*a)[needle[i]-'a']=m-1-i;
    }
    
}

int strStr(char* haystack, char* needle) {
    int m=strlen(haystack),k;
    int n=strlen(needle);
    int* table=(int*)malloc(26*sizeof(int));
    shifttable(needle,&table);
    int i=n-1;
    while(i<m)
    {
        k=0;
        while(k<n&&needle[n-1-k]==haystack[i-k])
        {
            k++;
        }
        if(k==n)
        {
            return i-n+1;
        }
        else{
            i+=table[haystack[i]-'a'];}
    }
    return -1;

    
}

//for 256 table[256] for uppercase,lowercase and digits use this
//table[(unsigned char)needle[i]]=m-1-i;
// @lc code=end

