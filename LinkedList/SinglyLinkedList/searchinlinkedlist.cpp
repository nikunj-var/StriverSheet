 link- https://www.codingninjas.com/studio/problems/search-in-a-linked-list_975381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

        int
        searchInLinkedList(Node<int> *head, int k)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}