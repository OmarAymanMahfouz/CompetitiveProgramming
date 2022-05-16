/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        
        Node* temp = head;
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            
            temp = temp->next->next;
        }
        
        Node* ans = head->next;
        Node* anstemp = ans;
        temp = head;
        
        
        
        while(anstemp->next){
            temp->next = anstemp->next;
            anstemp->next = anstemp->next->next;
            temp = temp->next;
            anstemp = anstemp->next;
        }
        temp->next = nullptr;

        return ans;
    }
};