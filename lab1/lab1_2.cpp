
#include <iostream>
using namespace std;

class node
{

public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    void print(node *head)
    {
        cout << "\nLINK LIST : ";
        node *temp = head;
        while (temp)
        {

            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void solve(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1->next != NULL)
    {
        node *next1 = NULL;
        node *next2 = NULL;
        if (temp1 != NULL)
        {
            next1 = temp1->next;
        }
        else
            break;

        if (temp2 != NULL)
        {
            next2 = temp2->next;
        }
        else
            break;

        temp1->next = temp2;
        temp2->next = next1;
        temp1 = next1;
        temp2 = next2;
    }

    if (temp2)
        temp1->next = temp2;

    head1->print(head1);
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

    solve(head1, head2);
}
