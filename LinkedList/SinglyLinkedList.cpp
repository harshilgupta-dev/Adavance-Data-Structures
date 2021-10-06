#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

};

class SinglyLinkedList{
    private:
        ListNode *head;
        int size;
    public:
        SinglyLinkedList(){
            head=NULL;
            size=0;
        }
        SinglyLinkedList(int data){
            head=new ListNode;
            head->data=data;
            head->next=NULL;
            size=1;
        }
        SinglyLinkedList(int arr[],int n){
            head=new ListNode;
            head->data=arr[0];
            head->next=NULL;
            size=1;
            ListNode *p=head;

            for(int i=1;i<n;i++){
                ListNode *t=new ListNode;
                t->data=arr[i];
                t->next=NULL;
                p->next=t;
                p=p->next;
                size++;
            }
        }

        void display(){
            ListNode *p=head;

            while(p){
                cout<<p->data<<"-->";
                p=p->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){

    int arr[]={10,60,70,30,80,100};
    
    SinglyLinkedList l(arr,6);

    l.display();

    return 0;
}