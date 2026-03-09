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
        ListNode resultHead = null;
        ListNode resultTail = null;
        int carry=0,newDigit;
        while(!(l1==null && l2==null)){
            int digit1= l1== null ? 0: l1.val;
            int digit2= l2== null ? 0: l2.val;
            int  sum = digit1 + digit2 + carry;
            
            newDigit = sum  %  10 ;
            carry = sum / 10 ;
            ListNode newNode = new ListNode(newDigit);
            if(resultHead==null){
                resultHead = newNode;
            }else{
                resultTail.next = newNode;
            }   
            resultTail = newNode;

            if(l1!=null)l1=l1.next;
            if(l2!=null)l2=l2.next;
        }
        if(carry!=0){
            ListNode newNode = new ListNode(carry);
            resultTail.next = newNode;
        }

        return resultHead;
        
    }
}