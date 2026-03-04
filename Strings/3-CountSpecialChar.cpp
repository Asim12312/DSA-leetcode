
//Problem : Count Special Characters
//link : https://leetcode.com/problems/count-the-number-of-special-characters-i/
//Time complexity : O(n)
//Space complexity : O(n)

class Solution {
public:
    int numberOfSpecialChars(string word) {
           unordered_set<char> st(word.begin(), word.end());
           int count = 0;

           for(char c = 'a'; c<='z'; c++){
            if(st.count(c) && st.count(toupper(c))){
                count++;
            }
           }
           return count;
    
    }
};