#include<iostream>


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) {              //原链表为空
            return nullptr;
        }
        ListNode* pre;                      //指向前一个结点
        ListNode* current = head;           //指向当前结点
        ListNode* next = head->next;        //指向后一个结点
        head->next = nullptr;               //尾结点（原头结点）指针域置空
        while (next != nullptr) {
            pre = current;
            current = next;
            next = current->next;
            current->next = pre;
        }
        return current;
    }
};