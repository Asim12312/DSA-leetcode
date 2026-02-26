// Problem: Count element with maximum frequency
//link: https://leetcode.com/problems/count-elements-with-maximum-frequency/post-solution/?submissionId=1931474318
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        int maxFreq = 0;
        for(auto &i : freq){
            if(i.second > maxFreq){
                maxFreq = i.second;
            }
        }

        int totalFreq = 0;
        for(auto &i : freq){
            if(i.second == maxFreq){
                totalFreq += i.second;
            }
        }
        return totalFreq;
    }
};