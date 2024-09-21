struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* tmp = head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
        }
        while(l1 != nullptr){
            int sum = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            l1 = l1->next;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
        }
        while(l2 != nullptr){
            int sum = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            l2 = l2->next;
            tmp->next = new ListNode(sum);
            tmp = tmp->next;
        }
        if(carry != 0){
            tmp->next = new ListNode(carry);
            tmp = tmp->next;
        }
        return head->next;
    }
};