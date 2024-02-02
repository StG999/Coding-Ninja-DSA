#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node* bubbleSortLL(Node *head){
    Node *dummy = (Node*)malloc(sizeof(Node));
    dummy->next = head;

    Node *traversal = head;
    int len = 0;
    while(traversal != NULL){
        len += 1;
        traversal = traversal->next;
    }

    for(int i = 0; i < len; i++){
        Node* iter1 = dummy->next;
        Node* iter2 = iter1->next;
        Node* prev = dummy;
        while(iter2 != NULL){
            if(iter1->value > iter2->value){
                //Node* temp = iter1;
                prev->next = iter2;
                iter1->next = iter2->next;
                iter2->next = iter1;

                prev = iter2;
                iter2 = iter1->next;
            }
            else{
                prev = iter1;
                iter2 = iter2->next;
                iter1 = iter1->next;
            }
        }
    }

    return dummy->next;
}

int main(){
    int n;
    scanf("%d", &n);

    Node *head = NULL;
    Node *temp = head;

    for(int i = 0; i < n; i++){
        if(head == NULL){
            head = (Node*)malloc(sizeof(Node));
            int val;
            scanf("%d", &val);
            head->value = val;
            head->next = NULL;
            temp = head;
        }
        else{
            Node* newNode = (Node*)malloc(sizeof(Node));
            int val;
            scanf("%d", &val);
            newNode->value = val;
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
    }

    head = bubbleSortLL(head);
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");

}