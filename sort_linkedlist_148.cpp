/**
 * @brief I think this is a great example to understand divide and conquer
 * basically, at the lowest level of recursion, the base cases are
 * either one single node or 2 nodes (swap the value if the 2 nodes' values are in descending orde)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        auto res = helper(head);
        return res;
    }

    ListNode * helper(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        if (head->next == nullptr) {
            return head;
        }

        if (head->next->next == nullptr) {
            // swap
            if (head->next->val < head->val) {
                int tmp = head->val;
                head->val = head->next->val;
                head->next->val = tmp;
            }
            return head;
        }

        // 3 nodes at least
        
        ListNode *left = head, *pre = nullptr, *right = head;
        while (right != nullptr && right->next != nullptr) {
            if (pre == nullptr) {
                pre = left;
            } else {
                pre = pre->next;
            }
            left = left->next;
            right = right->next->next;
            // head, and left
        }

        // set left
        pre->next = nullptr;

        // divide
        auto left_side = helper(head);
        auto right_side = helper(left);


        // conqure -> don't forget to combine the 2 parts
        ListNode *a = left_side, *b = right_side;
        // a: 2 b: 1, 1
        // a: 2 b: 3, 2
        // a: 4, b: 3 3
        // 
        ListNode *cur = new ListNode(0) , *tmp = cur;
        while (a != nullptr && b != nullptr) {
            if (a->val > b->val) {
                tmp->next = b;
                b = b->next;
            } else {
                tmp->next = a;
                a = a->next;
            }
            tmp = tmp->next;
        }

        while (a != nullptr) {
            tmp->next = a;
            a = a->next;
            tmp = tmp->next;
        }

        while (b != nullptr) {
            tmp->next = b;
            b = b->next;
            tmp = tmp->next;
        }

        return cur->next;
    }
};