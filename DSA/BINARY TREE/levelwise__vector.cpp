#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
vector<vector<int>> ans;
void separate(node *root)
{
    queue<node *> q;
    ans.push_back({root->data});
    q.push(root);
    while (!q.empty())
    {
        vector<int> ans1;
        for (int i = q.size(); i > 0; i--)
        {
            node *ind = q.front();
            if (ind->left)
            {
                q.push(ind->left);
                ans1.push_back(ind->left->data);
            }
            if (ind->right)
            {
                q.push(ind->right);
                ans1.push_back(ind->right->data);
            }

            q.pop();
        }
        ans.push_back(ans1);
    }
}

int print(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    print(root->left);
    cout << root->data << " -> ";
    print(root->right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node *root = new node(10);
    root->left = new node(50);
    root->right = new node(60);
    root->right->left = new node(90);
    root->right->right = new node(100);
    root->left->left = new node(70);
    root->left->right = new node(80);
    print(root);
    separate(root);
    for(auto child:ans){
        for(auto it:child){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
