// Problem: Contains Duplicate
// Link: https://leetcode.com/submissions/detail/1853009630/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       for(int i=1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]){
            return true;
        }
       }
       return false;
    }
};