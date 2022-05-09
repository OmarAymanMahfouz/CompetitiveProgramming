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
    void reorderList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int idx = 0, cnt = 0;
        while(temp){
            if (cnt % 2 == 1)
                temp->val = vec[vec.size() - idx - 1], idx++;
            else
                temp->val = vec[idx];
            
            cnt++;
            temp = temp->next;
        }
    }
};