#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

}*head=NULL;

void addlast()
{
    int a;
    cout<<"\nEnter element:";
    cin>>a;
    Node* temp=new Node();
    temp->data=a;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *l=head;
        while(l->next!=NULL)
            l=l->next;
        l->next=temp;
    }
    cout<<"\nInserted successfully!!!\n";
}

void addfirst()
{
    int a;
    cout<<"\nEnter element:";
    cin>>a;
    Node* temp=new Node();
    temp->data=a;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    cout<<"\nInserted successfully\n";
}

void addatpos()
{
    int a;
    cout<<"\nEnter element:";
    cin>>a;
    int i;
    cout<<"\nEnter the position at which you want to enter the element(1 indexing type):";
    cin>>i;
    Node* temp=new Node();
    temp->data=a;
    temp->next=NULL;
    if(i<=0)
        cout<<"\nInvalid position to insert(please follow 1 indexing)\n";
    else if(head==NULL)
    {
        head=temp;
    }
    else
    {
        if(i==1)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            Node* temp1=head;
            while(temp1->next!=NULL && --i>1)
                temp1=temp1->next;
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
    cout<<"\nInserted successfully\n";
}

void removefirst()
{
    if(head==NULL)
        cout<<"\nLinked list is empty!!!\n";
    else
    {
        head=head->next;
        cout<<"\nDeleted:)\n";
    }
}

void removelast()
{
    if(head==NULL)
        cout<<"\nLinked list is empty!!!\n";
    else
    {
        Node *temp=head,*temp1=NULL;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        if(temp1==NULL)
            head=NULL;
        else
            temp1->next=NULL;
        cout<<"\nDeleted:)\n";
    }
}

void removeatpos()
{
    int i;
    cout<<"\nEnter the position at which you want to delete the element(1 indexing type):";
    cin>>i;
    if(i<=0)
        cout<<"\nInvalid position to delete!!!(Please follow 1 indexing)\n";
    else
    {
        if(i==1)
        {
            head=head->next;
        }
        else
        {
            Node* temp1=head;
            while(temp1->next->next!=NULL && --i>1)
                temp1=temp1->next;
            temp1->next=temp1->next->next;
        }
        cout<<"\nDeleted successfully\n";
    }
}

void searchelement()
{
    if(head==NULL)
        cout<<"\nLinked list is empty!!!\n";
    else
    {
        int num;
        cout<<"\nEnter number which you want to search:";
        cin>>num;
        Node* temp=head;
        int j=1,flag=0;
        while(temp!=NULL)
        {
            if(temp->data==num)
            {
                cout<<"\n"<<num<<" found at "<<j<<"th position\n";
                flag=1;
                break;
            }
            j++;
            temp=temp->next;
        }
        if(flag==0)
            cout<<"\nElement not found:(\n";
    }
}

void show()
{
    if(head==NULL)
    {
        cout<<"\nThere is nothing to show\n";
    }
    else
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<"\n"<<temp->data;
            temp=temp->next;
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        cout<<"1)Add new element at the last position\
           \n2)Add new element at the first position\
           \n3)Add new element at the desired position\
           \n4)Delete first node\
           \n5)Delete last node\
           \n6)Delete at the desired position\
           \n7)Show All elements\
           \n8)search an element\
           \n9)Exit\
           \nEnter a valid option(1-8):";
        cin>>choice;
        switch(choice)
        {
        case 1:
            addlast();
            break;
        case 2:
            addfirst();
            break;
        case 3:
            addatpos();
            break;
        case 4:
            removefirst();
            break;
        case 5:
            removelast();
            break;
        case 6:
            removeatpos();
            break;
        case 7:
            show();
            break;
        case 8:
            searchelement();
            break;
        case 9:
            return 0;
        default:
            cout<<"\nInvalid option\nplease try again";
        }
    }
    return 0;
}
