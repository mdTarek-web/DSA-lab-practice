#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = NULL;

void print(){
    cout<<"-------Linked List-------"<<endl;
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;

}
void insertAtFirst(int v){
    Node *n1 = new Node;
    n1->data = v;
    n1->next = NULL;
    if(head==NULL){
        head = n1;
    }
    else{
        n1->next = head;
        head = n1;
    }

}
void insertAt(int v, int index){
    if(index<=0){
        insertAtFirst(v);
        return;
    }
    Node *n1 = new Node;
    n1->data = v;
    n1->next = NULL;

    int i=0;
    Node *ptr = head;
    while(ptr->next!=NULL){
        if(i==index-1)
            break;
        i++;
        ptr = ptr->next;
    }

    n1->next = ptr->next;
    ptr->next = n1;
}
int deleteFrom(int index){
    int i=1;
    Node *ptr = head;
    while(ptr->next!=NULL){
        if(i==index-1)break;
        i++;
        ptr = ptr->next;
    }
    Node *tmp = ptr->next;
    ptr->next = tmp->next;
    int item = tmp->data;
    delete tmp;
    return item;
}
void insertAtLast(int v){
    Node *n1 = new Node;
    n1->data = v;
    n1->next = NULL;
    if(head==NULL){
        head = n1;
        return;
    }
    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = n1;
}
int main(){
    //insertAtFirst(7);
    //insertAtFirst(10);
    //insertAtFirst(5);
    //insertAtFirst(17);
    //print();
    insertAtLast(13);
    insertAtLast(7);
    insertAtLast(10);
    insertAtFirst(11);
    insertAtFirst(15);
    insertAt(23,3);
    insertAt(27,0);
    insertAt(9,10);
    print();
    cout<<deleteFrom(4)<<endl;
    print();
    return 0;
}

