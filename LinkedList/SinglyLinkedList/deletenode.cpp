class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *prev = node;
        ListNode *temp = node;

        while (temp->next != 0)
        {
            prev = temp;
            temp->val = temp->next->val;
            temp = temp->next;
        }
        prev->next = 0;
    }
};