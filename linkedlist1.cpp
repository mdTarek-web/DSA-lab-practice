// #include<iostream>
// #include<vector>

// using namespace std;

// struct ListNode{
//     int val;
//     ListNode* next;

//     ListNode(int i){
//         val = x;
//         next = nullptr;
//     }
// };

// ListNode* mergeTwoList(ListNode* l1. ListNode* l2){
//     if(!li) return l2;
//     if(!l2) return l1;

//     ListNode* head = nullptr;
//     ListNode* tail = nullptr;

//     if(l1->val < l2->val){
//         head = tail = l1;
//         l1 = l1->next;
//     }
//     else{
//         head = tail = l2;
//         l2 = l2->next;
//     }

// while(l1 && l2){
//     if(li->val < l2->val){
//         tail->next = l1;
//         l1 = l1-next;
//     }else{
//         tail->next = l2;
//         l2 = l2->next;
//     }
//     tail = tail->next;
// }
// return head;
// }

// void printList(ListNode* head){
//     while(head){
//         cout << head->val << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

// ListNode* creatListS(const vector<int>vals){
//     if(vals.empty()) return nullptr;

//     ListNode* head = new ListNode(vals[0]);
//     ListNode* current = head;

//     for(size_t i = 1; i < vals.size(); i++){
//         current->next = new ListNode(vals[i]);
//         current = current->next;
//     }
//     return 0;
// }

// int main(){
//     ListNode* list1 = creatList({1, 2, 3,4});
//     ListNode* list2 = creatList({3, 2, 1, 5});

//     ListNode* merged = mergeTwoLists(list1, list2);

//     cout << "Merged List : ";
//     return 0;
// }









#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* head = nullptr;
    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    ListNode* current = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1) current->next = list1;
    else current->next = list2;

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ListNode* insert(ListNode* head, int val) {
//     if (!head) return new ListNode(val);
//     ListNode* temp = head;
//     while (temp->next) temp = temp->next;
//     temp->next = new ListNode(val);
//     return head;
// }

ListNode* insert(ListNode* head, int val) {
    if (head == nullptr)
        return new ListNode(val);

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new ListNode(val);

    return head;
}

int main() {

    ListNode* list1 = nullptr;
    list1 = insert(list1, 1);
    list1 = insert(list1, 2);
    list1 = insert(list1, 4);

    ListNode* list2 = nullptr;
    list2 = insert(list2, 1);
    list2 = insert(list2, 3);
    list2 = insert(list2, 4);

    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

