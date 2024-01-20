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

bool delAndRevLoop(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while (fast != NULL && fast != slow)
    {
        fast = fast->next;
        if (fast)
            fast = fast->next;
        else
            break;
        slow = slow->next;
    }
    if (fast == NULL)
    {
        return false;
    }
    else
    {
        slow = head;
        while (fast->next != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
      
        return true;
    }
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
    cout << "ENTER THE VALUE OF K FOR LOOP : ";
    cin >> k;
    k %= n;
    int p = k;
    node *t = NULL;
    while (k--)
    {
        if (t == NULL)
            t = head;
        else
            t = t->next;
    }
    node *e = head;
    if (p != 0)
    {
        while (e->next != NULL)
            e = e->next;
        e->next = t;
    }
    cout<<boolalpha;
    cout << "THE LOOP IS PRESENT : "<<delAndRevLoop(head);
    head->print(head);
}
