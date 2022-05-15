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
struct Reversed{
    ListNode* segStart;
    ListNode* segEnd;
};
class Solution {
private:
    Reversed reverseSegment(ListNode* start, int elementNum){
        ListNode* cur = start;
        ListNode* prv = nullptr;
        ListNode* next = start->next;
        
        while(cur && elementNum){
            cur->next = prv;
            prv = cur;
            cur = next;
            if(next)
                next = cur->next;
            elementNum--;
        }
        
        Reversed rev;
        rev.segStart = prv;
        rev.segEnd = start;
        return rev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode* temp = head;
        ListNode* ans = nullptr;
        ListNode* prv = nullptr;
        while(true){
            bool flag = true;
            ListNode* st = temp;
            for (int i = 0; i < k; i++){
                if(!temp){
                    flag = false;
                    break;
                }
                temp = temp->next;
            }
            
            if(flag){
                Reversed rev = reverseSegment(st, k);
                if(!ans)
                    ans = rev.segStart, prv = rev.segEnd;
                else{
                    prv->next = rev.segStart;
                    prv = rev.segEnd;
                }
            }
            else{
                prv->next = st;
                break;
            }
        }
        return ans;
    }
};