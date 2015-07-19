class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node ==NULL)
            return;
        node->val = node->next->val;
        delete(node->next);
        node->next= node->next->next;
        return;
    }
};
