### 583.两个字符串的删除操作

1. 动态规划
   
   两个字符分别减去最长公共子序列剩余的字符，从原字符去除即可使两个字符串相等
   
   因此两个字符串相互演变所需的步数为：两个字符串长度之和 - 2 * 两个字符串最长公共子序列

   最长公共子序列求解见题 [1143.最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence)

[Leetcode Link](https://leetcode-cn.com/problems/delete-operation-for-two-strings/)