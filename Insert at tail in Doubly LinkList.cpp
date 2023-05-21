
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
void insertattail(Node*&tail,Node*&head,int d)
{
    if(tail==NULL)
    {
        Node*temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}
void insertathead(Node*&head,Node*&tail,int d)
{
    if(head==NULL)
    {
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
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
void insertatposition(Node*&head,Node*&tail,int p,int d)
{
    if(p==1)
    {
        insertathead(head,tail,d);
        return;
    }
    int cnt=1;
    Node*temp=head;
    while(cnt<p-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertattail(tail,head,d);
        return;
    }
    Node*nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    nodetoinsert->prev=temp;
    temp->next=nodetoinsert;
}
int main()
{

    Node*head=NULL;
    Node*tail=NULL;
    //print(head);
    insertathead(head,tail,22);
    insertathead(head,tail,25);
    insertathead(head,tail,92);
    insertattail(tail,head,72);
    print(head);
    insertatposition(head,tail,5,32);
    print(head);
    return 0;
}
