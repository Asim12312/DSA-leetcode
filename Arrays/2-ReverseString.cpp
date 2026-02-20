// Problem: Reverse String
// Link: https://leetcode.com/submissions/detail/1908901472/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        char temp;

       while(start<end){
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start = start+1;
            end = end-1;
       }
    }
};