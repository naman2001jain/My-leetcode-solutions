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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* dummy = new ListNode(-1);
        
        ListNode* res = dummy;
        ListNode* l1 = list1, *l2 = list2;
        while(l1 && l2){
            if(l1->val < l2->val){
                res->next = l1;
                l1 = l1->next;
            }else{
                res->next = l2;
                l2 = l2->next;
            }    
            res = res->next;
        }
        if(l1){
            res->next = l1;
        }
        if(l2){
            res->next = l2;
        }
        return dummy->next;
    }
};