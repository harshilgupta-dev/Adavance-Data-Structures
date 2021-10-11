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

        int length(){
            return size;
        }

        void insertAtFirst(int element){
            ListNode *p=new ListNode;
            p->data=element;
            p->next=head;
            head=p;
            size++;
        }
        void insertAtLast(int element){
            ListNode *p=head;
            ListNode *t=new ListNode;
            t->data=element;
            t->next=NULL;
            if(head==NULL){
                head=t;
                size++;
                return;
            }
            while(p->next!=NULL){
                p=p->next;
            }
            p->next=t;
            size++;
        }
        int deleteFirst(){
            if(head==NULL)
                return -1;
            ListNode *t=head;
            head=head->next;
            int prevData=t->data;
            delete t;
            size--;
            return prevData;
        }

        int deleteLast(){
            if(head==NULL || head->next==NULL)
                return head->data;
            
            ListNode *cur=head,*prev=NULL;
            while(cur->next!=NULL){
                prev=cur;
                cur=cur->next;
            }
            int prevData=cur->data;
            delete cur;
            prev->next=NULL;
            size--;
            return prevData;
        }

        void insert(int pos,int element){
            if(pos>size){
                cout<<"Position Not found"<<endl;
                return;
            }
            ListNode *newNode=new ListNode;
            newNode->data=element;
            if(pos==1){
                newNode->next=head;
                head=newNode;
                size++;
                return;
            }
            ListNode *prev=head;
            int posCount=1;
            while(posCount<pos-1){
                prev=prev->next;
                posCount++;
            }
            ListNode *cur=prev->next;
            newNode->next=cur;
            prev->next=newNode;
            size++;
        }

        int Delete(int pos){
            if(pos>size){
                cout<<"Position Not found"<<endl;
                return -1;
            }
            int prevData;
            if(pos==1){
                ListNode *temp=head;
                prevData=temp->data;
                head=head->next;
                size--;
                delete temp;
                return prevData;
            }
            ListNode *prev=head;
            int posCount=1;
            while(posCount<pos-1){
                prev=prev->next;
                posCount++;
            }
            ListNode *cur=prev->next;
            prev->next=cur->next;
            prevData=cur->data;
            size--;
            return prevData;
        }

        int middleNode(){
            if(head==NULL && head->next==NULL){
                return head->data;
            }
            ListNode *slowPtr=head;
            ListNode *fastPtr=head;

            while(fastPtr!=NULL && fastPtr->next!=NULL){
                slowPtr=slowPtr->next;
                fastPtr=fastPtr->next->next;
            }
            return slowPtr->data;
        }
};

int main(){

    int arr[]={10,60,70,30,80,100};
    
    SinglyLinkedList l(arr,6);
    l.insertAtFirst(1);
    l.insertAtLast(62);
    l.display();
    cout<<l.deleteFirst()<<endl;
    
    cout<<l.length()<<endl;
    l.insert(1,26);
    l.display();
    l.Delete(2);
    l.display();
    cout<<l.length()<<endl;


    return 0;
}