### 201.数字范围按位与

1. 位运算：

   例如，计算从 5 到 7 按位与：

   5: 0 1 0 1

   6: 0 1 1 0
   
   7: 0 1 1 1
   
   =======
   
   &  0 1 0 0

   因此只需要计算 left -> right 有多少位数，将右移后的数左移相应位数即可。
   
[Leetcode Link](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)