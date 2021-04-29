#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_beg(int val) {
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    cout<<"The new data "<< val <<" at begining of node is added"<<endl;
}

void insert_end(int val) {
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    cout<<"The new data "<< val <<" at end of node is added"<<endl;
}

void insert_mid(int val, int position) {
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;

    struct Node* temp = head;
    for(int i=2; i<position; i++){
        if(temp->next != NULL){
        temp = temp->next;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
    cout<<"The new data "<< val <<" at "<< position <<" of node is added"<<endl;
}

void del_beg() {
    struct Node* temp = head;

    if (temp != NULL) {
        head = temp->next;
        free(temp);
        cout<<"The data at begining of node is deleted"<<endl;
    }

}

void del_end() {
    struct Node* temp = head;
    struct Node* prev = head;

    if (temp != NULL) {
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        cout<<"The data at end of node is deleted"<<endl;
    }
}

void del_key(int key) {
    struct Node* temp = head;
    struct Node* prev = head;

    
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    cout<<"The data "<< key <<" is deleted"<<endl;
}

void display() {
    struct Node* ptr = head;
    //ptr = head;
    cout<<"The data in LinkedList are: "<<endl;
    while (ptr != NULL) {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
    cout<<"\n"<<endl;
}

int main() {
   int ch, val, ins_ch, del_ch, position;
   do {
        cout<<"1) Insert data"<<endl;
        cout<<"2) Delete data"<<endl;
        cout<<"3) Display"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
         case 1: {
            cout<<"1) Insert at beginning"<<endl;
            cout<<"2) Insert at end"<<endl;
            cout<<"3) Insert at middle"<<endl;
            cout<<"4) Exit"<<endl;
            cout<<"Enter choice: "<<endl;
            cin>>ins_ch;
            switch (ins_ch) {
                case 1: {
                    cout<<"Enter value to be pushed:"<<endl;
                    cin>>val;
                    insert_beg(val);
                    break;
                }
                case 2: {
                    cout<<"Enter value to be pushed:"<<endl;
                    cin>>val;
                    insert_end(val);
                    break;
                }
                case 3: {
                    cout<<"Enter value to be pushed:"<<endl;
                    cin>>val;
                    cout<<"Enter position:"<<endl;
                    cin>>position;
                    insert_mid(val, position);
                    break;
                }
                case 4: {
                    cout<<"Exit"<<endl;
                    break;
                }
                default: {
                    cout<<"Invalid Choice"<<endl;
                }
            }
            break;
         }
         case 2: {
            cout<<"1) Delete from beginning"<<endl;
            cout<<"2) Delete from end"<<endl;
            cout<<"3) Delete from middle"<<endl;
            cout<<"4) Exit"<<endl;
            cout<<"Enter choice: "<<endl;
            cin>>del_ch;
            switch (del_ch) {
                case 1: {
                    del_beg();
                    break;
                }
                case 2: {

                    del_end();
                    break;
                }
                case 3: {
                    cout<<"Enter value to be deleted:"<<endl;
                    cin>>val;
                    del_key(val);
                    break;
                }
                case 4: {
                    cout<<"Exit"<<endl;
                    break;
                }
                default: {
                    cout<<"Invalid Choice"<<endl;
                }
            }
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}