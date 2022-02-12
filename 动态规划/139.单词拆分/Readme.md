### 139.单词拆分

1. 动态规划 + 哈希表
   
   dp[i] 代表 s[i] 字符当前是否可以被字典词拆分，每次从字符中截断相应字符在哈希表中查找即可

   时间复杂度O(n^2)
   
2. 动态规划

   根据单词长度特性，可去判断条件中的除哈希表, 减少空间复杂度
   
[Leetcode Link](https://leetcode-cn.com/problems/word-break/)