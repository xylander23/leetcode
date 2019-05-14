本库主要记录平时练习或者公司抽的leetcode的题目答案
[toc]
# 第678题
**题目：**
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
简单的来说就是匹配符号，左括号必须和右括号数量完全匹配才行。但是在本题有一点要注意的是，*可以变成左括号或者右括号。
**思路：**
在这里直接看，很容易想到数据结构的栈的习题。只要把左括号放入栈中，然后遇到右括号弹出来就可以了，但是这个里面又有一个问题是这个*号是要怎么处理：是变左括号，还是右括号，还是不变。
如果是遇到左括号，那么就直接弹入栈中。
如果遇到星号怎么办，是变还是不变左括号呢？
从题目可知，如果一个左括号和星号单独在一起的时候，是肯定可以符合题意的，那么如果遇到星，我们也让左括号弹出来，但是我们用另一个变量来记录这种情况，这个变量其实就是记录弹出左括号但是还没用的数量。如果栈里面有左括号，那么弹出，加2（这是因为这里其实有两个可以变成左括号），如果栈空，那么就加1。
这种想法类似数据结构在提到栈的时候，会有一个应用是后缀表示的计算，如果遇到比自己高级的运算符，那么就要把栈的运算符弹出来，然后再放新的进去。
所以我们也可以默认*的等级是比左括号低的，所以遇到栈里面有左括号时，那么就要弹出一个左括号。
最后右括号，如果栈不为空，弹栈；如果为空，就看可变左括号的变量，如果小于0，就返回False。
最后如果栈为空，那么就为True，否则为False。

