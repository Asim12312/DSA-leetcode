// Problem: Container With Most Water
// Link: https://leetcode.com/submissions/detail/1725130654/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size()-1;
        
        while(left < right){
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            int area = width * minHeight;
            maxWater = max(area, maxWater);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
         return maxWater;
    }
   
};
