import java.util.Deque;

/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.15%)
 * Total Accepted:    550.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
    public boolean isValid(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('(', -1);
        map.put('[', -2);
        map.put('{', -3);
        map.put(')', 1);
        map.put(']', 2);
        map.put('}', 3);
        ArrayDeque<Character> sta = new ArrayDeque<>();
        for(int i = 0; i < s.length(); i++){
            if(map.get(s.charAt(i)) < 0){
                sta.addLast(s.charAt(i));
            }else{
                if(!sta.isEmpty()){
                    if(map.get(s.charAt(i)) + map.get(sta.pollLast()) == 0){
                        continue;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(sta.isEmpty()){
            return true;
        }else{
            return false;
        }
    }
}

