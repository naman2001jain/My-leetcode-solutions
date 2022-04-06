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
    
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = NULL, *curr = head, *next = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = next;
            if(curr!=NULL) next = curr->next;
        }
        head = prev;
        return head;
    }
    
    void printList(ListNode* head){
        if(head==NULL){
            return;
        }
        while(head!=NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revList = reverse(slow);
        //printing the revList
        // printList(revList);
        
        ListNode* start = head;
        while(start!=NULL && revList!=NULL){
            if(start->val != revList->val){
                return false;    
            }
            start = start->next;
            revList = revList->next;
        }
        return true;
    }
};