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

void insertathead(Node*&head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertattail(Node*&tail,int d)
{
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatposition(Node*&tail,Node*&head,int p,int d)
{
    if(p==1)
    {
      insertathead(head,d);
      return;
    }
    Node*temp=head;
    int cnt=1;
    while(cnt<p-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(tail,d);
        return;
    }
    Node*node_to_insert=new Node(d);
    node_to_insert->next=temp->next;
    temp->next=node_to_insert;
}
void print(Node*&head)
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
    Node* node1=new Node(108);
    Node*tail=node1;
    Node* head=node1;
    insertathead(head,55);
    insertathead(head,9);
    insertathead(head,108);


    print(head);
    cout<<endl;
    insertatposition(tail,head,2,20);
    print(head);
    return 0;
}
