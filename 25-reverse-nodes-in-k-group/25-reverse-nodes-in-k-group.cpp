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
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(temp!=NULL){
                temp = temp->next;
            }else{
                return head;
            }
        }
        
        int x=0;
        ListNode* prev = NULL, *curr = head, *next = head->next;
        while(curr && x<k){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr) next = curr->next;
            x++;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
        
    }
};