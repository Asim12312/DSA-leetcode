//Problem : Valid Anagram
//link : https://leetcode.com/problems/valid-anagram/
//Time complexity : O(nlogn)
//Space complexity : O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
       sort(s.begin(), s.end());
       sort(t.begin(), t.end());
       if(s == t){
        return true;
       }
       return false;

    }
};