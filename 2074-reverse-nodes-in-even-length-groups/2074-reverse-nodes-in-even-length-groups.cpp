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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        int groupSize = 1;

        while (curr) {
            ListNode* groupStart = curr;
            int count = 0;

            // Step 1: Count actual nodes in this group
            while (curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            // Step 2: If even → reverse this group
            if (count % 2 == 0) {
                ListNode* prevNode = curr;  // next group's start
                
                ListNode* temp = groupStart;
                
                for (int i = 0; i < count; i++) {
                    ListNode* next = temp->next;
                    temp->next = prevNode;
                    prevNode = temp;
                    temp = next;
                }

                // connect previous part
                ListNode* tail = groupStart;
                prev->next = prevNode;
                prev = tail;
            } 
            else {
                // just move prev forward
                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }

            groupSize++;
        }

        return dummy->next;
    }
};