// Problem: Find Peak Element
// Link: https://leetcode.com/problems/find-peak-element/post-solution/?submissionId=1931444572
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int max = 0;
        int i;
        for( i = 0; i<size; i++){
            if(nums[i] > nums[max]){
                max = i;
            }
        }
        return max;
    }
};