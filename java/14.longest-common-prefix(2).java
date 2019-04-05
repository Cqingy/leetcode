/*
 * @lc app=leetcode id=14 lang=java
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.18%)
 * Total Accepted:    432.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0)return "";
        return longestCommonPrefix(strs, 0, strs.length - 1);
    }

    private String longestCommonPrefix(String[] strs, int left, int right){
        if(left == right){
            return strs[left];
        }else{
            int mid = (left + right) / 2;
            String left_sub = longestCommonPrefix(strs, left, mid);
            String right_sub = longestCommonPrefix(strs, mid + 1, right);
            return commonPrefix(left_sub, right_sub);
        }
    }

    private String commonPrefix(String left_sub, String right_sub){
        int len = Math.min(left_sub.length(), right_sub.length());
        for(int i = 0; i < len; i++){
            if(left_sub.charAt(i) != right_sub.charAt(i))return left_sub.substring(0, i);
        }
        return left_sub.substring(0, len);
    }
}

