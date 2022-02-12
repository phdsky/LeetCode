### 128.最长连续序列

1. 哈希表
   
   首先使用 set 将原数组去重并放入 hash，针对每个元素 n，只要利用 hash 查找 n+1 是否在哈希表中即可
   由于被枚举过的后续元素已不再可能是最长连续序列中的元素之一（最长序列的元素是连续的），因此可以跳过以避免 TLE
   
[Leetcode Link](https://leetcode.cn/problems/longest-consecutive-sequence/)