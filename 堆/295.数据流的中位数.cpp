/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode.cn/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (53.79%)
 * Likes:    919
 * Dislikes: 0
 * Total Accepted:    123.4K
 * Total Submissions: 229.4K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 *
 *
 * 例如 arr = [2,3,4] 的中位数是 3 。
 * 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
 *
 *
 * 实现 MedianFinder 类:
 *
 *
 *
 * MedianFinder() 初始化 MedianFinder 对象。
 *
 *
 * void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
 *
 *
 * double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10^-5 以内的答案将被接受。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * 输出
 * [null, null, null, 1.5, null, 2.0]
 *
 * 解释
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 * 提示:
 *
 *
 * -10^5 <= num <= 10^5
 * 在调用 findMedian 之前，数据结构中至少有一个元素
 * 最多 5 * 10^4 次调用 addNum 和 findMedian
 *
 *
 */

// @lc code=start

// #include <iostream>
// #include <queue>

// using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // small 里面放的是大于中位数的子集，这样 small.top() 就是大于中位数子集中最小的数
        // large 里面放的是小于中位数的子集，这样 large.top() 就是小于中位数子集中最大的数
        // num 如果比大于中位数子集中最小的数还要小，那它就应放入小于中位数的子集中，并检查是否要替换
        if (small.empty() || num < small.top())
        {
            large.push(num);
            if (large.size() - small.size() > 1)
            {
                small.push(large.top());
                large.pop();
            }
        }
        else
        {
            small.push(num);
            if (small.size() - large.size() > 1)
            {
                large.push(small.top());
                small.pop();
            }
        }
    }

    double findMedian()
    {
        if (large.size() > small.size())
        {
            return large.top();
        }
        else if (large.size() < small.size())
        {
            return small.top();
        }

        return (large.top() + small.top()) / 2.0;
    }

private:
    priority_queue<int> large;                                      // 大顶堆
    priority_queue<int, std::vector<int>, std::greater<int>> small; // 小顶堆
};

// int main(int argc, char *argv[])
// {
//     MedianFinder medianFinder;
//     medianFinder.addNum(1);
//     medianFinder.addNum(2);
//     cout << medianFinder.findMedian() << endl;;
//     medianFinder.addNum(3);
//     cout << medianFinder.findMedian() << endl;
// }

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
