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
public:
ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

       
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //twin sum

        ListNode* secondHalf= reverseList(slow);
        ListNode* firstHalf=head;
        int maxsum=0;
        while(secondHalf){
            int sum=firstHalf->val+secondHalf->val;
            maxsum=max(sum,maxsum);
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
            
        }
        return maxsum;
    }
};