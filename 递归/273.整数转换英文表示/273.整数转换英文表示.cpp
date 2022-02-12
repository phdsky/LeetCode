/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 *
 * https://leetcode-cn.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (36.66%)
 * Likes:    240
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 78.1K
 * Testcase Example:  '123'
 *
 * 将非负整数 num 转换为其对应的英文表示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num = 123
 * 输出："One Hundred Twenty Three"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num = 12345
 * 输出："Twelve Thousand Three Hundred Forty Five"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num = 1234567
 * 输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：num = 1234567891
 * 输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven
 * Thousand Eight Hundred Ninety One"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        string s;
        if (num >= billion) {
            s += numberToWords(num / billion);
            s += " Billion";
            num %= billion;
        }
        if (num >= million) {
            if (!s.empty()) {
                s += ' ';
            }
            s += numberToWords(num / million);
            s += " Million";
            num %= million;
        }
        if (num >= thousand) {
            if (!s.empty()) {
                s += ' ';
            }
            s += numberToWords(num / thousand);
            s += " Thousand";
            num %= thousand;
        }
        if (num >= hundred) {
            if (!s.empty()) {
                s += ' ';
            }
            s += numberToWords(num / hundred);
            s += " Hundred";
            num %= hundred;
        }
        for (auto [k, v] : numberString) {
            if (num >= k) {
                num -= k;
                if (!s.empty()) {
                    s += ' ';
                }
                s += v;
            }
        }

        return s;
    }

private:
    const int billion = 1000000000;
    const int million = 1000000;
    const int thousand = 1000;
    const int hundred = 100;

    map<int, string, greater<int>> numberString = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
    };
};
// @lc code=end

