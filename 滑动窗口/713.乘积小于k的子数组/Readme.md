### 713.乘积小于k的子数组

1. 滑动窗口
   
   - 每次以右边界为定点，计算当前右边界的累乘积
   - 寻找满足条件的左边界
   - 计算区间 [left, right] 间满足条件的个数为 right - left + 1
   - 区间数为 [left, right], [left + 1, right] ... [right, right]
   
[Leetcode Link](https://leetcode-cn.com/problems/subarray-product-less-than-k/)