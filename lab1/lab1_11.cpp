#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    node *prev;
    int data;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev=NULL;
    }
    void print(node *head)
    {
        cout << "LINK LIST : ";
        node *temp = head;
        while (temp->next)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<temp->data<<" ";
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
            a->prev=temp;
            temp = temp->next;
        }
    }

    head->print(head);

    node* prev = NULL;
    node*curr = head;
    node*next = head->next;

    while(curr)
    {
        prev = curr->prev;
        next = curr->next;
        curr->next= prev;
        curr->prev= next;
        if(next==NULL)
        {
            head=curr;
            break;
        }
        curr = next;
    }
    head->print(head);
}
