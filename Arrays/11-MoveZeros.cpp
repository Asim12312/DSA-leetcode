// Problem: Move Zeros
// Link: https://leetcode.com/problems/move-zeroes/post-solution/?submissionId=1930683105
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        int temp = 0;

        for (int i=0; i<size; i++){
            if(nums[i] != 0){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
            
        }
    }
};