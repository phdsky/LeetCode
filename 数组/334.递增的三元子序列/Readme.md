### 334.递增的三元子序列

1. a 始终记录最小元素，b 为某个子序列里第二大的数。
   接下来不断更新 a，同时保持 b 尽可能的小。
   如果下一个元素比 b 大，说明找到了三元组。

[Leetcode Link](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)