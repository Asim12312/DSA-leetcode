// Problem: Check if Array Is Sorted and Rotated
//link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/post-solution/?submissionId=1931519718
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int next = (i + 1) % n;
            if(nums[i] > nums[next])
                count++;
        }

        return count <= 1;
    }
};