https : // www.codingninjas.com/studio/problems/insert-node-at-the-beginning_8144739?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

        Node *
        insertAtFirst(Node *list, int newValue)
{
    Node *temp = new Node(newValue);

    temp->next = list;
    list = temp;
    return list;
}