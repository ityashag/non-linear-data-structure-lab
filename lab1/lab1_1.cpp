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
};

void solve(node *head)
{
    node *prev = head;
    node *curr = head->next;
    while (curr != NULL)
    {
        prev->val = prev->val ^ curr->val;
        curr->val = prev->val ^ curr->val;
        prev->val = curr->val ^ prev->val;
        if (curr->next)
            curr = curr->next->next;
        else
            break;
        prev = prev->next->next;
    }

    head->print(head);
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
    head->print(head);
    solve(head);
}
