
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
    }

    node *rev(node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *ch = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return ch;
    }
};

void add(node *head1, node *head2)
{

    node *temp1 = head1;
    node *temp2 = head2;
    node *temp = NULL;
    node *ans = NULL;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int a = temp1->val + temp2->val + carry;
        carry = a / 10;
        a = a % 10;
        node *t = new node(a);
        if (ans == NULL)
        {
            ans = t;
            temp = ans;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1)
    {
        int a = temp1->val + carry;
        carry = a / 10;
        a = a % 10;
        node *t = new node(a);
        if (ans == NULL)
        {
            ans = t;
            temp = ans;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
        temp1 = temp1->next;
    }
    while (temp2)
    {

        int a = temp2->val + carry;
        carry = a / 10;
        a = a % 10;
        node *t = new node(a);
        if (ans == NULL)
        {
            ans = t;
            temp = ans;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
        temp2 = temp2->next;
    }
    while (carry)
    {
        int a = carry;
        carry = a / 10;
        a = a % 10;
        node *t = new node(a);
        if (ans == NULL)
        {
            ans = t;
            temp = ans;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
    }
    ans = ans->rev(ans);
    ans->print(ans);
}
int main()
{
    int n1;
    cout << "ENTER NUMBER1 : ";
    cin >> n1;
    node *head1 = NULL;
    node *temp = NULL;
    int n = n1;
    while (n)
    {
        int a = n % 10;
        n /= 10;
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

    int n2;
    cout << "ENTER NUMBER2  : ";
    cin >> n2;
    n = n2;
    node *head2 = NULL;
    temp = NULL;

    while (n)
    {
        int a = n % 10;
        n /= 10;
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
    add(head1, head2);
}
