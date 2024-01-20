#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    int data;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    void circular_print(node *head,int n)
    {
        cout << "CIRCULAR LINK LIST : ";
        node *temp = head;
        while (n--)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void print(node *head)
    {
        cout << "LINK LIST : ";
        node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    node *head = NULL;
    node *temp = NULL;
    int n;
    cout << "ENTER THE SIZE OF LINK LIST : ";
    cin >> n;
    cout<<"ASSUMING THE NODE OF THE LINK LIST ARE ALL DIFFERENT.\n";
    for (int i = 0; i < n; i++)
    {
        int t;
        cout << "ENTER THE " << i << "th ELEMENT : ";
        cin >> t;
        node *a = new node(t);
        if (head == NULL)
        {
            head = a;
            temp = head;
        }
        else
        {
            temp->next = a;
            temp = temp->next;
        }
    }
    temp->next=head;
    head->circular_print(head,n);
    int st,en;
    cout<<"ENTER START AND NODE VALUE OF THE SPLIT LINK LIST : ";
    cin>>st>>en;
    node*head2 = NULL;
    node*tail2 = NULL;
    temp=head;

    int ct = n;
    while(ct--)
    {
        if(temp->data==st) head2=temp;
        if(temp->data==en){
             tail2=temp;
             break;
        }
        temp=temp->next;
    }
    temp=head;

    while(temp->next != head2)temp=temp->next;
    head=tail2->next;
    tail2->next=NULL;
    temp->next=NULL;
    head->print(head);
    head2->print(head2);

}