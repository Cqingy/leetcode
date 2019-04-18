import java.util.ArrayList;

/*
 * @lc app=leetcode id=500 lang=java
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (61.85%)
 * Total Accepted:    85.8K
 * Total Submissions: 138.5K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
class Solution {
    public String[] findWords(String[] words) {
        ArrayList<String> res = new ArrayList<>(); 
        Map<Character, Integer> keyboard = new HashMap<>();
        keyboard.put('q', 1);
        keyboard.put('Q', 1);
        keyboard.put('w', 1);
        keyboard.put('W', 1);
        keyboard.put('e', 1);
        keyboard.put('E', 1);
        keyboard.put('r', 1);
        keyboard.put('R', 1);
        keyboard.put('t', 1);
        keyboard.put('T', 1);
        keyboard.put('y', 1);
        keyboard.put('Y', 1);
        keyboard.put('u', 1);
        keyboard.put('U', 1);
        keyboard.put('i', 1);
        keyboard.put('I', 1);
        keyboard.put('o', 1);
        keyboard.put('O', 1);
        keyboard.put('p', 1);
        keyboard.put('P', 1);
        keyboard.put('a', 2);
        keyboard.put('A', 2);
        keyboard.put('s', 2);
        keyboard.put('S', 2);
        keyboard.put('d', 2);
        keyboard.put('D', 2);
        keyboard.put('f', 2);
        keyboard.put('F', 2);
        keyboard.put('g', 2);
        keyboard.put('G', 2);
        keyboard.put('h', 2);
        keyboard.put('H', 2);
        keyboard.put('j', 2);
        keyboard.put('J', 2);
        keyboard.put('k', 2);
        keyboard.put('K', 2);
        keyboard.put('l', 2);
        keyboard.put('L', 2);
        keyboard.put('z', 3);
        keyboard.put('Z', 3);
        keyboard.put('x', 3);
        keyboard.put('X', 3);
        keyboard.put('c', 3);
        keyboard.put('C', 3);
        keyboard.put('v', 3);
        keyboard.put('V', 3);
        keyboard.put('b', 3);
        keyboard.put('B', 3);
        keyboard.put('n', 3);
        keyboard.put('N', 3);
        keyboard.put('m', 3);
        keyboard.put('M', 3);
        for(String word : words){
            if(word == null){
                res.add(word);
                continue;
            }
            int temp = keyboard.get(word.charAt(0));
            boolean flag = true;
            for(int j = 1; j < word.length(); j++){
                if(temp != keyboard.get(word.charAt(j))){
                    flag = false;
                    break;
                } 
            }
            if(flag == true) res.add(word);
        }
        return res.toArray(new String[res.size()]);
    }
}

