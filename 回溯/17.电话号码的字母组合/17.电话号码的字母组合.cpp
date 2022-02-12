/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.68%)
 * Likes:    1817
 * Dislikes: 0
 * Total Accepted:    449.9K
 * Total Submissions: 779.4K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    vector<string> combinations;
    unordered_map<char, string> typpingMap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void combine(const string &digits, int index, string &letter) {
        if (index == digits.length()) {
            combinations.push_back(letter);
            return;
        }

        char ch = digits[index];
        string holder = typpingMap[ch];

        for (int i = 0; i < holder.length(); ++i) {
            letter += holder[i];
            combine(digits, index + 1, letter);
            letter = letter.substr(0, letter.length() - 1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return combinations;

        string letter = "";
        combine(digits, 0, letter);

        return combinations;
    }
};
// @lc code=end

