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
private:
    ListNode* reverseList(ListNode* l1){
        ListNode* prv = nullptr;
        while(l1){
            ListNode* next = l1->next;
            l1->next = prv;
            prv = l1;
            l1 = next;
        }
        return prv;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prv1 = nullptr;
        ListNode* prv2 = nullptr;
        int flow = 0;
        while(l1 && l2){
            flow = l1->val + l2->val + flow;
            l1->val = l2->val = flow % 10;
            flow /= 10;
            prv1 = l1;
            prv2 = l2;
            l1 = l1->next;
            l2 = l2->next;
            
        }
        bool isFirst = true;
        if (l2)
            isFirst = false;
        while(l1){
            flow += l1->val;
            l1->val = flow % 10;
            flow /= 10;
            prv1 = l1;
            l1 = l1->next;
        }
        while(l2){
            flow += l2->val;
            l2->val = flow % 10;
            flow /= 10;
            prv2 = l2;
            l2 = l2->next;
        }
        ListNode* x = new ListNode(flow);
        
        if (flow){
            if (isFirst)
                prv1->next = x;
            else
                prv2->next = x;
        }
        if(isFirst)
            return reverseList(temp1);
        return reverseList(temp2);
    }
};