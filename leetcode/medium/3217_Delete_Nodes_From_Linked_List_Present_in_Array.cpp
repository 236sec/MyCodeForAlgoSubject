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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != nullptr) {
            if (!numsSet.contains(current->val)) {
                prev->next = current;
                prev = prev->next;
            }
            current = current->next;
        }

        prev->next = nullptr;
        return dummy->next;
    }
};