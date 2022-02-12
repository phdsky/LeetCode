### 62.不同路径

1. 动态规划
   
   第(i, j)位置可以由(i - 1, j) 和 (i, j - 1)两个位置递推过来，由此可得递推方程。

   由于每次只能向下或者向右移动一步，因此初始化条件到达(i, 0) 和 (0, j)路径数都为1。
   
[Leetcode Link](https://leetcode-cn.com/problems/unique-paths/)