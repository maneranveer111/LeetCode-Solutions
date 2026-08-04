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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = (l1) ? l1 : l2;
        return dummy.next;
    } 

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* ans = nullptr;
        ListNode* curr = nullptr;

        for(auto li : lists) {
            ans = merge(curr, li);
            curr = ans;
        }

        return ans;
    }
};