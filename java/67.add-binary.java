/*
 * @lc app=leetcode id=67 lang=java
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.40%)
 * Total Accepted:    289.4K
 * Total Submissions: 751.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
    public String addBinary(String a, String b) {
        StringBuilder res = new StringBuilder();
        int a_len = a.length() - 1;
        int b_len = b.length() - 1;
        int carry = 0;
        while(a_len >= 0 || b_len >= 0){
            int temp = ((a_len >= 0) ? a.charAt(a_len) : '0') - '0' + ((b_len >= 0) ? b.charAt(b_len) : '0') - '0' + carry;
            carry = temp / 2;
            res.append(temp % 2);
            --a_len;
            --b_len;
        }
        if(carry != 0) res.append(carry);
        res = res.reverse();
        return res.toString();
    }
}

