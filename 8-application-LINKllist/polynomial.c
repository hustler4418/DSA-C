#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int expo;
    int coeff;
    struct node *link;
} node;

node *insert(node *head, int c, int e) {  // insert at sorted link list by comparing exponent
    node *temp = malloc(sizeof(node));
    temp->coeff = c;
    temp->expo = e;
    temp->link = NULL;

    if (head == NULL || e>head->expo) {  // for first node or higher priority
        temp->link = head;
        head = temp;
    } else {  // for intermediate and last node
        node *ptr = head;
        while (ptr->link != NULL && ptr->link->expo >=e) {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return head;
}

node *create(node *head) {
    int n, coef, exp;
   
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter the coefficient of term %d: ", i);
        scanf("%d", &coef);

        printf("Enter the exponent of term %d: ", i);
        scanf("%d", &exp);
        head = insert(head, coef, exp);
    }
    return head; // Return the modified head
}

void print(node *head) {
    node *ptr = head;
    while (ptr != NULL) {
        printf("(%dx^%d)", ptr->coeff, ptr->expo);
        if (ptr->link != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }
        ptr = ptr->link; // Move to the next node after printing
    }
}

int main() {
    node *head = NULL;
    head = create(head);
    print(head);
    return 0;
}
