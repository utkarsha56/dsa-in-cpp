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

node* createLL(int arr[], int i, int n){
    if(i==n) return NULL;

    node *temp = new node(arr[i]);
    temp->next = createLL(arr, ++i, n);
    return temp;

}

node* DeleteNthNode(node *curr, int pos){
    if(!curr){
        return NULL;
    }
    else if(!pos){
        node *temp = curr->next;
        delete curr;
        return temp;
    }

    curr->next = DeleteNthNode(curr->next, --pos);
    return curr;
}


void printLL(node *curr){
    if(!curr) return ;
    cout<<curr->data<<"  ";
    printLL(curr->next);
}


int main(){
    int arr[] = {2, 3, 5, 6};
    node *head = createLL(arr, 0, 4);
    cout<<"given linked list"<<endl;
    printLL(head);
    cout<<endl;

    head = DeleteNthNode(head, 3);
    printLL(head);



    return 0;
}
