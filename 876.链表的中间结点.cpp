/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        unordered_map<int, ListNode*> x;
        while(head != nullptr){
            x[length] = head;
            length ++;
            head = head->next;
        }
        int index;
        if(length & 1){
            index = (length - 1) / 2;
        }
        else{
            index = length / 2;
        }
        return  x[index];
    }
};
// @lc code=end

