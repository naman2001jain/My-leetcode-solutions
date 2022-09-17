/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
            if(l1==null){return l2;}
            if(l2==null){return l1;}
            ListNode list1 = l1;
            ListNode list2 = l2;
            ListNode res = new ListNode(-1);
            ListNode dummy = res;
            int sum = 0, carry = 0;
            while(list1!=null || list2!=null){
                sum = (list1!=null ? list1.val : 0) + (list2!=null ? list2.val : 0) + carry;
                carry = sum/10;
                res.next = new ListNode(sum%10);
                list1 = (list1!=null) ? list1.next : list1;
                list2 = list2!=null ? list2.next :  list2;
                res = res.next;
            }
            if(carry!=0){
                res.next = new ListNode(carry);
            }
            return dummy.next;
    }
}