/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.99%)
 * Likes:    835
 * Dislikes: 0
 * Total Accepted:    197.4K
 * Total Submissions: 438.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  string add(string num1, string num2) {
    if (num1 == "0") {
      return num2;
    } else if (num2 == "0") {
      return num1;
    }

    int size1 = num1.size(), size2 = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int size = (size1 < size2) ? size1 : size2;

    string num = "";
    int plus = 0;
    for (int i = 0; i < size; i++) {
      int math = num1[i] + num2[i] + plus - '0' - '0';
      if (math <= 9) {
        num += math + '0';
        plus = 0;
      } else {
        num += math - 10 + '0';
        plus = 1;
      }
    }

    if (size1 == size2) {
      if (plus == 1) {
        num += plus + '0';
        plus = 0;
      }
    } else if (size1 > size2) {
      for (int j = size; j < size1; j++) {
        int math = num1[j] + plus - '0';
        if (math <= 9) {
          num += math + '0';
          plus = 0;
        } else {
          num += math - 10 + '0';
          plus = 1;
        }
      }
    } else {  // size1 < size2
      for (int j = size; j < size2; j++) {
        int math = num2[j] + plus - '0';
        if (math <= 9) {
          num += math + '0';
          plus = 0;
        } else {
          num += math - 10 + '0';
          plus = 1;
        }
      }
    }
    if (plus != 0) {
      num += plus + '0';
    }

    reverse(num.begin(), num.end());
    return num;
  }

  string multiplyChar(string num, char ch) {
    if (ch == '0') {
      return "0";
    }

    int size = num.size();
    reverse(num.begin(), num.end());

    string mul = "";
    int plus = 0;
    for (int i = 0; i < size; i++) {
      int math = (num[i] - '0') * (ch - '0') + plus;
      if (math <= 9) {
        mul += math + '0';
        plus = 0;
      } else {
        mul += math % 10 + '0';
        plus = math / 10;
      }
    }
    if (plus != 0) {
      mul += plus + '0';
    }

    reverse(mul.begin(), mul.end());
    return mul;
  }

  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    string num = "";
    for (int i = num1.size() - 1, j = 0; i >=0; i--, j++) {
      string mul = multiplyChar(num2, num1[i]);
      string last = "";
      int k = j;
      while (k--) {
        last += "0";
      }
      num = add(num, mul + last);
    }

    return num;
  }
};

// @lc code=end

