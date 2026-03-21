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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>result(k,NULL);
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        int partsize=count/k;
        int extrasize=count%k;
        ListNode* curr=head;
        for(int i=0;i<k && curr;i++){
            result[i]=curr;
            int currSize=partsize+(extrasize>0?1:0);
            extrasize--;
            for(int j=1;j<currSize;j++){
                curr=curr->next;
            }
            ListNode* nextPart=curr->next;
            curr->next=NULL;
            curr=nextPart;
        }
        return result;
        
    }
};