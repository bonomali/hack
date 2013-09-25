// Merge two sorted list

struct Node{
    int value;
    Node* next;
}

static Node* mergeSortedList(Node* l1, Node* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->value < l2->value){
        l1->next = mergeSortedList(l1->next, l2);
        return l1;
    }else{
        l2->next = mergeSortedList(l1, l2->next);
        return l2;
    }
}
