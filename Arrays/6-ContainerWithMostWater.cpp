// Problem: Container With Most Water
// Link: https://leetcode.com/submissions/detail/1725130654/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size-1;
        int max_water = 0;
        int width = 0;
        int current_height;

        while(left < right){
            width = right - left;
            current_height = min(height[left], height[right]);
            max_water = max(max_water, width*current_height);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_water;
    }
};
