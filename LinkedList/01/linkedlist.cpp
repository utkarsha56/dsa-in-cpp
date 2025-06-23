#include <iostream>
#include<string>
using namespace std;



class node{
    public:
    int data;
    node *next;
    
    node(int val){
        data=val;
        next = NULL;
    }
};

node* createLinkedList(int arr[],int i,int size){
    if(i == size)
    return NULL;

    node *temp =new node(arr[i]);
    temp->next = createLinkedList(arr, i+1, size);
    return temp;
}

node* createAtFront(int arr[], int i, int size, node *temp){
    if(i == size)
    return temp;

    node *some = new node(arr[i]);
    some->next = temp ;
    return createAtFront(arr, i+1, size, some);
}

node* insertInMiddle(node *head, int val, int pos){
    if(!head){
        node *temp = new node(val);
        return temp;
    }
    else if(!pos){
        node *temp = new node(val);
        temp->next = head->next;
        return temp;
    }

    head->next = insertInMiddle(head->next, val, --pos);
    return head;

}

void printLinkedList(string note , node* head){
    cout<<note<<endl;
    while(head)
    {
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<endl;
}

int main() {

    int arr[]={3, 4,5,6,7};

    node *head1 = createLinkedList(arr, 0, 5);
    printLinkedList("created by recursion method", head1);
    node *head2 = createAtFront(arr, 0, 5, NULL);

    head1 = insertInMiddle(head1, 30, 3);
    
    printLinkedList("adding at front", head2);
    printLinkedList("inserting in a position", head1);



    return 0;
}
