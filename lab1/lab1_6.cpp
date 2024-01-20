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
    node *es = NULL;
    node *os = NULL;
    node *ee = NULL;
    node *oe = NULL;
    temp = head;
    while (temp)
    {
        if (temp->data % 2)
        {
            if (os == NULL)
            {
                os = temp;
                oe = os;
            }
            else
            {
                oe->next = temp;
                oe = oe->next;
            }
        }
        else
        {
            if (es == NULL)
            {
                es = temp;
                ee = es;
            }
            else
            {
                ee->next = temp;
                ee = ee->next;
            }
        }
        temp = temp->next;
    }
    if (ee != NULL)
    {
        ee->next = os;
        head = es;
    }
    else
    {
        head = os;
    }
    head->print(head);
}