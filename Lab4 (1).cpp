#include<bits/stdc++.h>
using namespace std;
#define st struct

struct node{
    int data;
    st node *previous;
    st node *next;
};

st node *head = NULL,*tail = NULL;

void display(){
    st node *temp;
    temp = head;
    cout << "Display the Linked List: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void create()
{
    int n,value;
    st node *curr;
    cout << "How many node want to print : ";
    cin >> n;
    for(int i=1;i<=n;i++){
    curr = new st node;
    cout <<"Enter value " <<i  << " : " ;
    cin >> value;
    curr->data = value;
    curr->previous = NULL;
    curr->next = NULL;
    if(head == NULL){
       head = curr;
       tail = curr;
    }
    else{
        tail->next = curr;
        curr->previous = tail;
        tail = curr;
    }
  }
  display();
  cout << endl;
}

void ins_beg(){
    st node *newnode;
    newnode = new st node;
    int value;
    cout << "Enter new node data: ";
    cin >> value;
    newnode->data = value;
    newnode->previous = NULL;
    newnode -> next = NULL;

    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->next = head;
        head->previous = newnode;
        head = newnode;
    }
    display();
    cout << endl;
}
void ins_at_between(){

    st node *temp,*temp1,*newnode;
    newnode = new st node;
    int i,pos;
    cout << "Enter the position number: ";
    cin >> pos;
    cout << "Enter the new node value: ";
    cin >> newnode->data;
    newnode->previous = NULL;
    newnode->next = NULL;
    if(head == NULL){
        head = tail = newnode;
    }
    if(pos == 1){
        newnode->next = head;
        newnode->previous = NULL;
        head = newnode;
    }
    else {
        temp = head;
        for(i=1;i<=pos-1;i++){
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = newnode;
        newnode->previous = temp1;
        newnode->next = temp;
    }
    display();
    cout << endl;

}

void ins_end(){
    st node *temp,*newnode;
    newnode = new st node;
    cout << "Enter the  Last node value: ";
    cin >> newnode->data;
    newnode->previous = NULL;
    newnode->next = NULL;
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->previous = temp;
        tail = newnode;
    }
    display();
    cout << endl;
}

void del_first(){

    st node *temp;
    temp = head;
    head = head->next;
    free(temp);
    display();
    cout << endl;
}

void del_any_pos(){

    st node *temp,*temp1;
    int pos,i;
    cout << "Enter the deleting position: ";
    cin >> pos;
    if(pos == 1){
    del_first();
    }
    else if(head != NULL ){
        temp = head;
        for(i=1;i<=pos-1;i++){
            temp1 = temp;
            temp = temp->next;
            (temp->next)->previous = temp1;
        }
        temp1->next =  temp->next;
        free(temp);
    }
    display();
    cout << endl;

}
void del_last(){
    st node *temp;
    temp = tail;
    tail = tail->previous;
    if(tail != NULL){
        tail->next = NULL;
    }
    else{
        head = NULL;
    }
    free(temp);

    display();
    cout << endl;
}

void reverse_list(){

    st node *temp = tail;
    cout << "Display reverse doubly linked list: ";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->previous;
    }
    cout << endl;
}

void remove_dupli(){
    if (head == NULL)
        cout << "The Linked List is empty." << endl;
    else
        {
        st node *current = head;
        while (current != NULL)
            {
            st node *temp = current;
            while (temp->next != NULL)
                {
                if (temp->next->data == current->data)
                    {
                    st node *duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete duplicate;
                    }
                else
                    temp = temp->next;
                }
            current = current->next;
            }
        cout << "Duplicate data removed from the Linked List." << endl;
    }
        display();
        cout << endl;
}

void rem_neg(){

    st node *temp1, *temp = head;
    while(temp != NULL){
        if(temp->data < 0){
            temp1 = temp;
            free(temp);
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;

        }
        temp = temp->next;
    }
    display();
    cout << endl;
}
void menu(){

    while(1){
    cout << "1. Create a New Doubly Linked List: " << endl;
    cout << "2. Insert a New node at first: " << endl;
    cout << "3. Insert a New node in any position: " << endl;
    cout << "4. Insert a New node at last position: " << endl;
    cout << "5. Delete the node from first position: " << endl;
    cout << "6. Delete a value from any position: " << endl;
    cout << "7. Delete the from last position:  " << endl;
    cout << "8. Reverse Linked List: " << endl;
    cout << "9. Remove Duplicate value: " << endl;
    cout << "10. Remove negative value: " << endl;
    int choose;
    cout << "Choose an option: ";
    cin >> choose;
    switch(choose){
    case 1: create();
                break;
    case 2: ins_beg();
                break;
    case 3: ins_at_between();
                break;
    case 4: ins_end();
                break;
    case 5: del_first();
                break;
    case 6: del_any_pos();
                break;
    case 7: del_last();
                break;
    case 8: reverse_list();
                break;
    case 9: remove_dupli();
                break;
    case 10: rem_neg();
                break;
        }
    }

}

int main()
{
    menu();
}

