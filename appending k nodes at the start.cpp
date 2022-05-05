#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insert(node *&head1, int x)
{
    node *head = head1;
    node *ptr = new node(x);
    if (head1 == NULL)
    {
        head1 = ptr;
        return;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = ptr;
}

void deleteATtail(node *&head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = NULL;
    delete del;
}

void deleteAThead(node *&head)
{
    node *temp = head;
    head = temp->next;
    delete temp;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *h = NULL;
    int t;
    cin >> t;
    while (t--)
    {
        int y, q = -1;
        while (1 > 0)
        {
            cin >> y;
            if (y == -1)
            {
                break;
            }
            else
            {
                insert(h, y);
            }
            q++;
        }
        int n;
        cin >> n;
        int m = (q - n);
        node *first = h;
        while (m--)
        {
            h = h->next;
        }
        node *temp = h->next;
        h->next = NULL;
        h = temp;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = first;
        print(h);
    }
    return 0;
}