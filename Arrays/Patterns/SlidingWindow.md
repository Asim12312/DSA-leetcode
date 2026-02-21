## chatgpt: https://chatgpt.com/share/699937c1-d75c-800b-8993-a264ddac2561

# Sliding Window in Data Structures & Algorithms (DSA)
1. Introduction

The Sliding Window technique is used to solve problems involving:

Arrays

Strings

Subarrays

Substrings

It is mainly used when:

We need to find something among contiguous elements

The brute-force solution takes O(n²) time

We can optimize it to O(n)

2. Why Sliding Window?
Brute Force Approach

For example:

Find maximum sum of subarray of size k

Brute force:

Generate all subarrays of size k

Calculate sum for each

Time Complexity: O(n × k) or O(n²)

Sliding Window Approach

Instead of recalculating sum:

Subtract first element of window

Add next element

Time Complexity: O(n)

3. Types of Sliding Window
A. Fixed Size Sliding Window

Window size remains constant (k).

Example:

Maximum sum of subarray of size k

First negative number in every window of size k

B. Variable Size Sliding Window

Window size changes based on condition.

Example:

Longest substring without repeating characters

Smallest subarray with sum ≥ target

4. Fixed Size Sliding Window – Example
Problem 1: Maximum Sum Subarray of Size K
Problem Statement

Given an array of integers and a number k, find the maximum sum of any contiguous subarray of size k.

Example
Input: arr = [2,1,5,1,3,2], k = 3
Output: 9
Explanation: Subarray [5,1,3] has maximum sum = 9
Brute Force (O(n*k))
int maxSum(vector<int>& arr, int k) {
    int n = arr.size();
    int max_sum = 0;

    for(int i = 0; i <= n-k; i++) {
        int sum = 0;
        for(int j = i; j < i+k; j++) {
            sum += arr[j];
        }
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
Sliding Window (O(n))
Steps:

Compute sum of first k elements

Slide window:

Subtract first element

Add next element

Update max

int maxSum(vector<int>& arr, int k) {
    int n = arr.size();
    
    int window_sum = 0;
    for(int i = 0; i < k; i++) {
        window_sum += arr[i];
    }

    int max_sum = window_sum;

    for(int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

Time Complexity: O(n)
Space Complexity: O(1)

5. Variable Size Sliding Window

Used when:

Condition depends on sum or characters

Window expands and shrinks dynamically

Template for Variable Window
int left = 0;
for(int right = 0; right < n; right++) {

    // expand window
    // add arr[right]

    while(condition is violated) {
        // shrink window
        left++;
    }

    // update answer
}
6. Problem 2: Longest Substring Without Repeating Characters
Problem Statement

Given a string, find the length of the longest substring without repeating characters.

Example
Input: "abcabcbb"
Output: 3
Explanation: "abc"
Solution Using Sliding Window
Idea:

Use a set or map

Expand window with right pointer

If duplicate found → move left pointer

int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int left = 0;
    int maxLen = 0;

    for(int right = 0; right < s.length(); right++) {
        
        while(st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

Time Complexity: O(n)
Space Complexity: O(1) (at most 26/128 characters)

7. Problem 3: Smallest Subarray with Sum ≥ Target
Problem Statement

Given an array and a target sum, find the minimum length of a contiguous subarray whose sum ≥ target.

Example
Input: arr = [2,3,1,2,4,3], target = 7
Output: 2
Explanation: [4,3]
Solution (Variable Window)
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for(int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while(sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

Time Complexity: O(n)

8. Important Patterns
Pattern 1: Count Occurrences

Example:

Count substrings with exactly k distinct characters

Use:

HashMap

Expand right

Shrink left if distinct > k

Pattern 2: Anagram Problems

Example:

Find all anagrams of pattern in string

Technique:

Frequency array of size 26

Fixed window of size pattern length

Pattern 3: Maximum/Minimum in Window

Example:

Sliding Window Maximum

Use:

Deque (Monotonic Queue)

Maintain decreasing order

9. Problem 4: Sliding Window Maximum (Hard)
Problem

Return maximum element in every window of size k.

Example
Input: [1,3,-1,-3,5,3,6,7], k=3
Output: [3,3,5,5,6,7]
Optimal Solution Using Deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for(int i = 0; i < nums.size(); i++) {

        // Remove out-of-window elements
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();

        // Remove smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k-1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

Time Complexity: O(n)
Space Complexity: O(k)

10. When to Use Sliding Window?

Use sliding window when:

✔ Problem involves contiguous subarray/substring
✔ Brute force is O(n²)
✔ Need max/min/longest/shortest
✔ Window can expand and shrink

11. Comparison: Brute Force vs Sliding Window
Approach	Time Complexity
Brute Force	O(n²)
Sliding Window	O(n)
12. Common Interview Problems

Maximum sum subarray of size k

Longest substring without repeating characters

Minimum window substring

Sliding window maximum

Fruit into baskets

Subarray product less than k

Count number of nice subarrays

13. Key Takeaways

Two pointers: left and right

Fixed window → simple subtraction/addition

Variable window → while loop to shrink

Always think: Can I avoid recomputing the whole window?

Sliding window usually reduces O(n²) → O(n)