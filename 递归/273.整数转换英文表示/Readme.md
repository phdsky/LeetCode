### 273.整数转换英文表示

1. 递归
   
   题目中转换整数的范围为[0, INT_MAX/2^31-1/2147483647]，即从零最大到十亿级别。
   
   从例子中的英文表达可归纳提取出几个基数，基本以三位数为一组（十亿billion、百万million、千thousand、百hundred）
   
   正确提取这四位基数断位符后，只要按照基数从大到小递归构建字符串即可，最终的十位和个位由哈希表递减给出。

[Leetcode Link](https://leetcode-cn.com/problems/integer-to-english-words/)