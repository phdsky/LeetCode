### 986.区间列表的交集

1. 归并区间，每次计算两个区间的交集：
   
   如果存在交集，则将交集加入结果中；同时将右端较小的区间去除，因为右端较小的区间更不可能与其他区间产生交集。

   如果不存在交集，则直接去除右端较小的区间即可。
   
[Leetcode Link](https://leetcode-cn.com/problems/interval-list-intersections/)