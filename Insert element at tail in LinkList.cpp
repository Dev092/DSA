#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertattail(Node*&tail,int d)
{
    Node*temp=new Node(d);
    tail->next=temp;
    temp=tail;
}
void print(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node*node1=new Node(11);

    Node*tail=node1;
    insertattail(tail,10);
    print(tail);
    return 0;
}

