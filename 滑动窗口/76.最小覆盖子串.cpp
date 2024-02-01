/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.50%)
 * Likes:    2812
 * Dislikes: 0
 * Total Accepted:    509.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
/**
 * 滑动窗口 + 哈希表
 */

// #include <iostream>
// #include <string>

// using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";

        unordered_map<char, int> src, dst;
        for (auto &c : t)
            dst[c]++;

        // string result = "";
        bool find = false;
        size_t posL = 0, posR = INT_MAX;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            // 扩大窗口
            src[s[right]]++;

            while (check(src, dst))
            {
                // 此处不能使用 substr 来截取字符串，会产生大量副本
                // string substr = s.substr(left, right - left + 1);

                if ((right - left) < (posR - posL))
                {
                    // result = substr;
                    find = true;
                    posL = left;
                    posR = right;
                }

                // 缩小窗口
                src[s[left]]--;
                left++;
            }
        }

        if (!find)
            return "";

        return s.substr(posL, posR - posL + 1);
    }

private:
    bool check(auto &src, auto &dst)
    {
        for (auto &[k, v] : dst)
        {
            if (src[k] < v)
                return false;
        }

        return true;
    }
};

// int main(int argc, char *argv[])
// {
//     Solution solution;
//     cout << solution.minWindow("ADOBECODEBANC", "ABC");
// }
// @lc code=end
