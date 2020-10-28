#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

void push(Node** head, int item){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->val = item;

    if (!(*head)){
        *head = node;
        return;
    }

    Node* current = *head;
    while(current->next)
        current = current->next;

    current->next = node;
}

void lprint(Node* head){
    Node* current = head;

    while(current){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("\n");
}

void split(Node* head, Node** a, Node** b){
    Node* slow = head;
    Node* fast = slow->next;

    while(fast){
        fast = fast->next;

        if (fast){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *a = head;
    *b = slow->next;

    slow->next = NULL;
}

Node* merge(Node* a, Node* b){
    Node* head = NULL;
    while (a || b){
        if (!b){
            push(&head, a->val);
            a = a->next;
        } else if (!a){
            push(&head, b->val);
            b = b->next;
        } else if (a->val < b->val){
            push(&head, a->val);
            a = a->next;
        } else {
            push(&head, b->val);
            b = b->next;
        }
    }
    return head;
}

void mergeSort(Node** headRef){
    if(!head || !(head->return)) return;

    ListNode* cur = *head;
    int size = 0;
    while(cur){
        size++;
        cur = cur->next;
    }

    for (int sz = 1; sz < size; sz *= 2)
        for(int lo = )

}


/*void mergeSort(Node** headRef){ // very slow
    Node* head = *headRef;
    Node* a;
    Node* b;

    if(!head || !(head->next))
        return;

    split(head, &a, &b);

    lprint(a);
    lprint(b);
    mergeSort(&a);||
    mergeSort(&b);
    *headRef = merge(a, b);
}
*/
int main()
{
    /* Start with the empty list */
    Node* a = NULL;

    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    printf("pushing\n");
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    /* Sort the above created Linked List */

    printf("mergesorting\n");
    mergeSort(&a);
    printf("Sorted Linked List is: \n");
    lprint(a);

    return 0;
}
