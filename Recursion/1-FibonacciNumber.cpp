//Problem : Fibonacci number
//link : https://leetcode.com/problems/fibonacci-number/post-solution/?submissionId=1937639262
//Time complexity : O(2^n)
//Space complexity : O(n)

class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};