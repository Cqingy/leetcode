/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.89%)
 * Total Accepted:    372.5K
 * Total Submissions: 909.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 0;
        int len = digits.length - 1;
        int temp = digits[len] + 1;
        carry = temp / 10;
        digits[len] = temp % 10;
        --len;
        while(len >= 0 && carry != 0){
            temp = digits[len] + carry;
            carry = temp / 10;
            digits[len--] = temp % 10;
        }
        if(len < 0 && carry != 0){
            int[] new_digits = new int [digits.length + 1];
            new_digits[0] = 1;
            return new_digits;
        }
        return digits;
    }
}

