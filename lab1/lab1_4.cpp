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

node *solve(node *head, int n, int k)
{
    k %= n;
    if (k == 0)
        return head;
    node *e1 = head;
    for (int i = 0; i < k - 1; i++)
        e1 = e1->next;
    node *h2 = e1->next;
    node *e2 = h2;
    e1->next = NULL;
    head = head->rev(head);

    h2 = h2->rev(h2);

    e2 = head;
    while (e2->next != NULL)
        e2 = e2->next;
    e2->next = h2;
    head = head->rev(head);
    return head;
}

int main()
{
    int n;
    cout << "ENTER THE VALUE OF N : ";
    cin >> n;
    node *head = NULL;
    node *temp = NULL;

    for (int i = 0; i < n; i++)
    {
        cout << "ENTER " << i << "th ELEMENT OF LINK LIST : ";
        int a;
        cin >> a;
        node *t = new node(a);
        if (head == NULL)
        {
            head = t;
            temp = head;
        }
        else
        {
            temp->next = t;
            temp = temp->next;
        }
    }
    int k;
    cout << "ENTER THE VALUE OF K : ";
    cin >> k;

    head->print(head);
    head = solve(head, n, k);
    head->print(head);
}
