class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int count = 0;
        int sum = 0;
        for(int i = 0; i<size; i++){
            if(nums[i] == k){
                sum = 0;
                count++;
            }
            else if(nums[i] > k){
                sum = 0;
                continue;
            }
            else if(nums[i] < k){
                sum += nums[i];
                if(sum == k){
                    count++;
                    sum = nums[i];
                }
            }
        }
        return count;
    }
};