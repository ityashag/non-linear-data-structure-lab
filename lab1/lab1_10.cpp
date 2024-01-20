
#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    void print(node *head)
    {
        cout << "\nLINK LIST : ";
        node *temp = head;
        while (temp)
        {

            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void merge(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *sorted = NULL;
    node *ns = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (sorted == NULL)
        {
            if (temp1->data < temp2->data)
            {
                sorted = temp1;
                ns = sorted;
                temp1 = temp1->next;
            }
            else
            {
                sorted = temp2;
                ns = sorted;
                temp2 = temp2->next;
            }
        }
        else
        {
            if (temp1->data < temp2->data)
            {
                ns->next = temp1;
                ns = ns->next;
                temp1 = temp1->next;
            }
            else
            {
                ns->next = temp2;
                ns = ns->next;
                temp2 = temp2->next;
            }
        }
    }
    if (temp1 != NULL)
    {
        ns->next = temp1;
    }
    if (temp2 != NULL)
        ns->next = temp2;
    sorted->print(sorted);
}

int main()
{
    int n1;
    cout << "ENTER NUMBER OF ELEMENT OF FIRST LINK LIST  : ";
    cin >> n1;
    node *head1 = NULL;
    node *temp = NULL;

    for (int i = 0; i < n1; i++)
    {
        cout << "ENTER " << i << "th ELEMENT OF LINK LIST FIRST : ";
        int a;
        cin >> a;
        node *t = new node(a);
        if (head1 == NULL)
        {
            head1 = t;
            temp = head1;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
    }
    head1->print(head1);

    int n2;
    cout << "ENTER NUMBER OF ELEMENT OF SECOND LINK LIST  : ";
    cin >> n2;
    node *head2 = NULL;
    temp = NULL;

    for (int i = 0; i < n2; i++)
    {
        cout << "ENTER " << i << "th ELEMENT OF LINK LIST SECOND : ";
        int a;
        cin >> a;
        node *t = new node(a);
        if (head2 == NULL)
        {
            head2 = t;
            temp = head2;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
    }
    head2->print(head2);
    merge(head1, head2);
}