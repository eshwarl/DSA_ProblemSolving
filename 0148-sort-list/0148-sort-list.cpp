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

//merge function
ListNode* merge(ListNode* left,ListNode* right){
    if(!left)return right;
    if(!right)return left;
    if(left->val < right->val){
        left->next=merge(left->next,right);
        return left;
    }else{
        right->next=merge(left,right->next);
        return right;
    }
}


//finding middle for divide 
 ListNode* findMiddle(ListNode* head){
    if(!head)return head;
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
 }


public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return  head;
        ListNode* middle=findMiddle(head);
        ListNode* secondHalf=middle->next;
        middle->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(secondHalf);
        return merge(left,right);
    }
};