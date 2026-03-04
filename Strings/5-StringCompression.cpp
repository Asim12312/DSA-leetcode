
//Problem : String compression
//link : https://leetcode.com/problems/string-compression/post-solution/?submissionId=1937578654/
//Time complexity : O(n)
//Space complexity : O(n)

class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int n = chars.size();
        int count = 1;

        for(int i = 1; i <= n; i++) {
            if(i < n && chars[i] == chars[i-1]) {
                count++;
            } 
            else {
                s += chars[i-1];
                if(count > 1) {
                    s += to_string(count);
                }
                count = 1;
            }
        }

        chars.clear();
        for(char c : s) {
            chars.push_back(c);
        }

        return chars.size();
    }
};