#include <iostream>
using namespace std;
///////////////////////////////////////////HERE COMES THE FUNCTION MADE FOR HANDLING LINKED LIST.///////////////////////////////////////
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
