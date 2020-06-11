/*

Problem Statement!!!

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

*/
class Solution
{
public:
    void sortColors(vector<int> &v)
    {
        int n = v.size();
        int c0 = 0, c1 = 0, c2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] == 0)
                c0++;

            if (v[i] == 1)
                c1++;

            if (v[i] == 2)
                c2++;
        }
        for (int i = 0; i < c0; ++i)
            ans.push_back(0);
        for (int i = c0 + 1; i < c0 + 1 + c1; ++i)
            ans.push_back(1);
        for (int i = c0 + 2 + c1; i < c0 + 2 + c1 + c2; ++i)
            ans.push_back(2);
        for (int i = 0; i < n; ++i)
            v[i] = ans[i];
    }
};