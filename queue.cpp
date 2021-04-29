#include <iostream>
using namespace std;
int queue[100], n = 100, head = - 1, tail = - 1;
void Enqueue() {
   int val;
   if (tail == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (head == - 1)
      head = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      tail++;
      queue[tail] = val;
   }
}
void Dequeue() {
   if (head == - 1 || head > tail) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[head] <<endl;
      head++;;
   }
}
void Peek() {
   if (head == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = head; i <= tail; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: Enqueue();
         break;
         case 2: Dequeue();
         break;
         case 3: Peek();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}

