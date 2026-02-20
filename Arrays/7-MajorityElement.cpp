// Problem: Majority Element
// Link: https://leetcode.com/submissions/detail/1715489825/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int freq = 0;
        for (int i=0;i<nums.size();i++){
            if(freq == 0){
                    result = nums[i];
            }
            if(result == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return result;
    }
};