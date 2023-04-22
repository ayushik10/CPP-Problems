/* 002. ADD TWO NUMBERS.


You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros
                                                                                        */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {  
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 
        return prev;
   }
   void insertAtTail(ListNode* &head, ListNode* &tail, int value){
       ListNode* temp = new ListNode(value);

       if(head == NULL){
           head = temp;
           tail = temp;
           return;
       }
       else{
           tail->next = temp;
           tail = temp;
       }
   }
    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){

            int value1 = 0;

            if(l1 != NULL)
            value1 = l1->val;

            int value2 = 0;

            if(l2 != NULL)
            value2 = l2->val;

            int sum = carry+value1+value2;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;

            if(l1 != NULL)
            l1 = l1->next;

            if(l2 != NULL)
            l2 = l2->next;
        }
        return ansHead;
    } 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        ListNode* ans = add(l1 , l2);

        return ans;
    }
};
