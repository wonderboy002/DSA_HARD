#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int arrayIndex;
    int colIndex;

    node(int data, int arrayIndex, int colIndex)
    {
        this->data = data;
        this->arrayIndex = arrayIndex;
        this->colIndex = colIndex;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        // min heap creation
        return a->data > b->data;
    }
};

void mergeK(vector<vector<int>> nums, int k, int cols, vector<int> &ans)
{
    priority_queue<node *, vector<node *>, compare> pq;
    // process first elements of k-arrays
    for (int i = 0; i < k; i++)
    {
        pq.push(new node(nums[i][0], i, 0));
    }

    node *temp = pq.top();
    pq.pop();

    ans.push_back(temp->data);
    pq.push(new node(nums[temp->arrayIndex][temp->colIndex + 1], temp->arrayIndex, temp->colIndex + 1));

    while (!pq.empty())
    {
        node *temp = pq.top();
        pq.pop();

        ans.push_back(temp->data);
        if (temp->colIndex+1 < cols)
        {
            pq.push(new node(nums[temp->arrayIndex][temp->colIndex + 1], temp->arrayIndex, temp->colIndex + 1));
        }
    }
}

int main()
{

    // k sorted arrays
    vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};

    vector<int> ans;
    mergeK(nums, 3, 3, ans);
    for (auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}