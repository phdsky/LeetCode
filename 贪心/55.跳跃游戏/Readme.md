### 55.跳跃游戏

1. 贪心
   
   从后往前遍历数组，如果当前遇到的元素可以到达最后一行，则截断后边的元素；
   
   否则继续向前遍历，若最后剩下步数大于1，则可以判断为无法到达，否则可以到达；时间复杂度O(n)。

[Leetcode Link](https://leetcode-cn.com/problems/jump-game/)