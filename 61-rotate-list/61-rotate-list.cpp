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
    
    int getLength(ListNode* head){
        ListNode* temp = head;
        int x=0;
        while(temp!=NULL){
            temp = temp->next;
            x++;
        }
        return x;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        k = k%getLength(head);
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(k--){
            while(temp!=NULL && temp->next!=NULL){
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            prev->next = NULL;
            head = temp;
        }
        return head;
    }
};