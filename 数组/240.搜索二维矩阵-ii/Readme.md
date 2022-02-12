### 240.搜索二维矩阵-ii

1. 对于右上角某个数，小于该数都在矩阵上半部分，大于该数都在矩阵下半部分；
   因此从右上角数开始搜素，如果小于该数，则往左搜索，大于该数，则往下搜索。

[Leetcode Link](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)