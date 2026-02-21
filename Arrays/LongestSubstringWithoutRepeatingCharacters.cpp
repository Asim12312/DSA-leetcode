// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right=0;
        int max_length = 0;

        for(right ; right<s.size(); right++){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            max_length = max(max_length, right-left+1);
        }
        return max_length;
    }
};