#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *below;
    Node(int value)
    {
        data = value;
        next = nullptr;
        below = nullptr;
    }
    Node()
    {
    }
};

class LinkedList
{
public:
    Node *head = nullptr;

    void matrixtolinkedlist(int arr[][3])
    {

        Node *heads[3];
        Node *nexttemp, ptr;
        

        for (int i = 0; i < 3; i++)
        {
            heads[i] = NULL;
            for (int j = 0; j < 3; j++)
            {
                Node *ptr = new Node(arr[i][j]);
                if (heads[i] == NULL)
                {

                    heads[i] = ptr;
                }
                else
                {
                    nexttemp->next = ptr;
                }
                nexttemp = ptr;
            }
        }

        

        for (int i = 0; i < 2; i++)
        {
            Node *temp1 = heads[i];
        Node *temp2 = heads[i+1];
            while (temp1 && temp2)
            {
                temp1->below = temp2;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        head = heads[0];
    }
    void display(){
        Node* right;
        Node* down;
        down=head;
         
        while(down){
            
            right=down;
            while(right){
                cout<<right->data<<"->";
                right=right->next;

            }
            
            cout<<endl;
            for(int i=0 ; i<3 ; i++){
                cout<<"|  ";
            }
            cout<<endl;
            down=down->below;

            
        }

    }
};

int main()
{

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    LinkedList l;
    l.matrixtolinkedlist(arr);
    l.display();
   
}