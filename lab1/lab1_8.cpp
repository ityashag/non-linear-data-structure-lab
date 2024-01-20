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
    head->print(head);
    temp=head;
    while(temp)
    {
        node* a = temp;
        while(a!=NULL && a->next&& a->next->data==temp->data) a=a->next;
        if(a!=NULL) temp->next=a->next;
        else temp->next=NULL;
        temp=temp->next;
    }
    head->print(head);
}