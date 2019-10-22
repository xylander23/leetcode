[TOC]

本库主要记录平时练习或者公司抽的[leetcode](https://leetcode.com/)的题目答案

# 678
**题目：**
Given a string containing only three types of characters: '(', ')' and '*', write a function to check 
whether this string is valid. We define the validity of a string by these rules:

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

遇到右括号，如果栈不为空，弹栈；如果为空，就看可变左括号的变量，如果小于0，就返回False。

最后如果栈为空，那么就为True，否则为False。
# 881
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

**思路**
这个问题简化的话就是最大的数是否可以再带一个数列最小数的问题。然后，思路有点像归并排序算法类似，用两个指针来遍历数组。首先我们对数列进行一个排序，然后一个指头部（最大），一个指尾部（最小值），然后从头部开始遍历：
    1. 如果最大值减limit等于0，那么直接遍历下一个数，n加1
    2. 如果最大值limit大于0，那么判断这个差是否大于最小值，如果是那么最小值指针减1。
    3. 否则，n加1
最后返回n即为答案。

# 991
**题目：**
On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.
简单说，就是只有-1和*2的操作，计算X要多少步才可以到Y
**思路：**
其实X只有两个方向的路可以走，一个是变大（乘2），一个是变小（-1）。
所以如果Y小于X，只有一种方法，那就是减1，所以这种情况，步数就是X-Y

比较麻烦的是Y大于X，因为这个时候就两种操作都存在。

但是，我们可以直观看出，乘2的最快，所以我们可以把Y一直除二缩小，然后把Y变成比X小的数，这样就变成第一个问题了。
但如果Y变成一个奇数了怎么办，因为如果是乘二不可能出现奇数情况，所以这说明中间有减1的操作，让它变成奇数，而X减1其实就是Y加1了，所以我们可以给Y+1然后加上一个步数，最后就可以得出变换的步数。

# 1004
**题目：**
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s.
简单来说就是把尽可能的把0变成1以后得到最大串

**思路：**
https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247564/JavaC%2B%2BPython-Sliding-Window

这里有一种比较巧的思想，题目只是要得出最长的子串，那么我们就可以用两个指针，一个j指最终点一个i指起点。如果它们之间的0大于K，那么就右移i，不然就一直右移j。
最后你会发现，j就等于len(A)的长度，所以就是看怎么计算i，可以让子串更长。当K小于0以后，就说明之间0大于了最大值，那么就要移i向右，同时如果第i个是0，就要补1给K，不然就不用。

# 846

**题目：**

爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

**思想**

先给数组按从小到大排序，每次取数组第一个，然后开始找m+1,m+2..m+w-1的数，从数组中将它们弹出。弹完以后再取数组第一个数，循环下去，直到最后数组可以为空，那么就说明数组可以成顺子。

先判断数组是否能被W整除，如果不能，那就肯定不成立，返回false。

如果可以，先对数组进行升序排序，然后遍历Length(hand)/W次，每次再在找m+1,m+2..m+w-1的数，如果存在就弹出，不存在就报错。

最后如果没有报错，就说明成立，返回true。

# 763
**题目**
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

**思想**
判定子串成立的方式其实就是这个字串全部用完，所以如果子串的出现字数没有用完，那么就要继续遍历，否则就生成了最大的子串。
先Counter一下全部的元素，然后遍历字符串
减一个次数，更新candicate这个字典数据（candicate字典记录子串字符出现次数），length子串长度为1。
如果candicate的values()全是0，就是最佳的子串了。

