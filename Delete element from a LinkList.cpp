
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
    ~Node()
    {
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
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
    Node*nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

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
void deleteNode(Node*&head,int p)
{
    if(p==1)
    {
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node*curr=head;
        Node*prev=NULL;

        int cnt=1;
        while(cnt<p)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* node1=new Node(108);
    Node*tail=node1;
    Node* head=node1;
    insertathead(head,55);
    insertathead(head,9);

    print(head);
    cout<<endl;
    insertatposition(tail,head,5,20);
    print(head);
    cout<<endl;
    deleteNode(head,5);
    print(head);

    return 0;
}

