#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int v){
        data=v;
        next=nullptr;
    }

};

class LinkedList{
    public:
    Node* head=nullptr;
   
    void InsertAtStart(int v){

        if(head==nullptr){
             head=new Node(v);

        }
        
        else if(head!=nullptr){
            Node* temp=new Node(v);
            temp->next=head;
            head=temp;
        }
        


    }
    void forwardPrint(){
        if(head==nullptr){
            cout<<"Empty List!"<<endl;
        }
        else {
            Node* temp=head;
            while(temp!=nullptr){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"Null\n";

        }
    }

    void deleteMiddle(){
        
        int count=0;
        Node* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        if(count<3){
            cout<<"Cant delete from middle"<<endl;
            return;
        }
        int index=count/2;
        deleteFromIndex(index);
    }

    void deleteFromIndex(int index){
        if(index==0){
            Node* toDelete=head;
            head=head->next;
            delete toDelete;
        }
        else{
            Node* current=head;
            Node* previous=head;
            for(int i=0 ; i < index ; i++){
                previous=current;
                current=current->next;
                if(current==nullptr){
                    cout<<"Out of range"<<endl;
                }

            }
            previous->next=current->next;
            delete current;
        }
    }
    
};



int main(){

    LinkedList l;
    l.InsertAtStart(4);
    l.InsertAtStart(7);
    l.InsertAtStart(9);
    l.InsertAtStart(11);
    l.InsertAtStart(14);
    l.forwardPrint();
    l.deleteMiddle();
    l.forwardPrint();

}