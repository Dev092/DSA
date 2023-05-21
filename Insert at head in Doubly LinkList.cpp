#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*prev;
    Node*next;

    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
void print(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertathead(Node*&head,int d)
{
    Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
int main()
{
    Node*node1=new Node(55);
    Node*head=node1;
    print(head);
    insertathead(head,69);
    print(head);
    return 0;
}
