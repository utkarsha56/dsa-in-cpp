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


node* createLL(int arr[], int index, int size){
    if(index == size)
    return NULL;

    node* temp = new node(arr[index]);
    temp->next = createLL(arr, ++index, size);
    return temp;
}

void printLL(node *curr){
    if(!curr)
    return ;

    cout<<curr->data<<"  ";
    printLL(curr->next);

}

node* reverseLL(node *curr, node *prev){
    if(!curr)
    return prev;

    node *next = curr->next;
    curr->next = prev;
    return reverseLL(next, curr);


}

int main(){

    int arr[] = {3, 5, 6, 7};

    node *head = createLL(arr, 0, 4);

    printLL(head);

    node* head1 = reverseLL(head, NULL);
    cout<<"after reversion"<< endl;
    printLL(head1);



    return 0;
}