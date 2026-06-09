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
    ListNode* isValid(ListNode* node, int k) {
        ListNode* temp = node;
        while(node) {
            k--;
            if(k == 0)
                return node;
            node = node->next;
        }

        return nullptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !isValid(head, k)) 
            return head;
        ListNode* curr = head;
        int cnt = k;
        ListNode* nxt = nullptr;
        ListNode* temp = nullptr;

        while(curr && k) {
            nxt = curr->next;
            curr->next = temp;
            temp = curr;
            curr = nxt;
            k--;
        }

        head->next = reverseKGroup(curr, cnt);

        if(isValid(head, cnt))
            head = isValid(head, cnt);
            
        return temp;
    }
};