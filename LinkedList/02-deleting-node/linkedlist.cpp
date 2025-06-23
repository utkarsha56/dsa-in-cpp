#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* createLinkedList(int arr[], int index, int size){
    if(index==size)
    return NULL;

    node *curr = new node(arr[index]);
    curr->next = createLinkedList(arr, ++index, size);
    return curr;
    
}

node* deleteLL(node* curr, int pos){
    if(!curr){
        return NULL;
    }
    else if(!pos){
        node *temp = curr->next;
        delete curr;
        return temp;
    }

    curr->next = deleteLL(curr->next, --pos);
    return curr;
}


void printLL(node *temp){
    cout<<temp->data<<"  ";
    printLL(temp->next);
}


int main(){
    int arr[] = {2, 4, 6, 8, 10};
    node *head = createLinkedList(arr, 0, 5);
    // printLL(head);

    node *head1 = deleteLL(head, 1);
    printLL(head1);
    return 0;
}