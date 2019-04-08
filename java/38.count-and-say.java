/*
 * @lc app=leetcode id=38 lang=java
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.89%)
 * Total Accepted:    270K
 * Total Submissions: 675.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
    public StringBuilder numberProduce(StringBuilder n){
        StringBuilder result = new StringBuilder("");
        int i = 0;
        while(i < n.length()){
            int num = 1;
            char old_char = n.charAt(i);
            while(i+1 < n.length() && n.charAt(i+1) == old_char){
                ++i;
                ++num;
            }
            ++i;
            result.append(num).append(old_char);
        }
        return result;
    }

    public String countAndSay(int n) {
        StringBuilder result = new StringBuilder("1");
        for(int i = 1; i < n; i++){
            result = numberProduce(result);
        }
        return result.toString();
    }
}

