// Problem: Median of Two Sorted Arrays
// Link: https://leetcode.com/submissions/detail/1590004511/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int size = length1 + length2;
        vector<int> final(size);
        
        int i = 0, j = 0, k = 0;
        while (i < length1 && j < length2) {
            if (nums1[i] < nums2[j]) {
                final[k++] = nums1[i++];
            } else {
                final[k++] = nums2[j++];
            }
        }

        while (i < length1) {
            final[k++] = nums1[i++];
        }

        while (j < length2) {
            final[k++] = nums2[j++];
        }

        if (size % 2 == 0) {
            return (final[size / 2 - 1] + final[size / 2]) / 2.0;
        } else { 
            return final[size / 2];
        }
    }
};