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
    ListNode* reverseLlist(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        if(!head) return 0;
        if(!head->next->next){
            return head->val + head->next->val;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        ListNode* reverse = reverseLlist(slow);
        ListNode* curr = head;
        int maxSum = INT_MIN;
        while(curr && reverse){
            maxSum = max(maxSum, curr->val + reverse->val);
            curr = curr->next;
            reverse = reverse->next;
        }

        return maxSum;
    }
};