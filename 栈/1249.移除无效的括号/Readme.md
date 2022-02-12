### 1249.移除无效的括号

1. 栈
   
   利用栈存储'('的位置，每次遇到')'可能会存在以下两种情况：
   - 如果栈中还有未匹配的'('，则将其弹出栈；
   - 如果之前已经没有'('，则将该')'字符从字符中删除。
   
   剩余栈中未匹配成功的'('，将其从字符中删除。

[Leetcode Link](https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/)