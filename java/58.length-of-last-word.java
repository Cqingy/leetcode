/*
 * @lc app=leetcode id=58 lang=java
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.20%)
 * Total Accepted:    256.5K
 * Total Submissions: 796.2K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
    public int lengthOfLastWord(String s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ' '){
                ++i;
                while(i < s.length() && s.charAt(i) == ' '){
                    ++i;
                }
                if(i < s.length()){
                    res = 1;
                }else{
                    break;
                }
            }else{
                ++res;    
            }
        }
        return res;
    }
}

