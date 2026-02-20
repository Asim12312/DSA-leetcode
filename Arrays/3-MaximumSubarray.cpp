// Problem: Maximum Subarray
// Link: https://leetcode.com/submissions/detail/1853041016/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        for(int i=1;i<nums.size(); i++){
            currentSum = max(nums[i], currentSum+nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};