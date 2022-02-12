/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.30%)
 * Likes:    501
 * Dislikes: 0
 * Total Accepted:    172.1K
 * Total Submissions: 316.7K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 * 
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        if (size1 < size2) {
            swap(num1, num2);
            swap(size1, size2);
        }

        int carry = 0;
        for (int i = 1; i <= size2; i++) {
            int num = num1[size1 - i] - '0' + num2[size2 - i] - '0' + carry;
            if (num > 9) {
                carry = 1;
                num -= 10;
            } else {
                carry = 0;
            }

            num1[size1 - i] = num + '0';
        }

        int id = size1 - size2 - 1;
        while (id >= 0 && carry == 1) {
            int num = num1[id] - '0' + carry;
            if (num > 9) {
                carry = 1;
                num -= 10;
            } else {
                carry = 0;
            }

            num1[id] = num + '0';
            id--;
        }

        if (carry == 1) {
            num1 = "1" + num1;
        }

        return num1;
    }
};
// @lc code=end

