#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left, *right;
};

Node *newNode()
{
    return new Node{-1, nullptr, nullptr};
}

void add_node(Node *root, int value, string &step, bool &complete)
{
    Node *ptr = root;
    for (int i = 0; i < step.size(); i++)
    {
        if (step[i] == 'L')
        {
            if (ptr->left == nullptr)
                ptr->left = newNode();
            ptr = ptr->left;
        }
        else if (step[i] == 'R')
        {
            if (ptr->right == nullptr)
                ptr->right = newNode();
            ptr = ptr->right;
        }
    }
    if (ptr->value != -1)
        complete = false;
    ptr->value = value;
}

void free_tree(Node *root)
{
    if (root == nullptr)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

bool check_complete(Node *root)
{
    if (root == nullptr)
        return true;
    if (root->value == -1)
        return false;
    return check_complete(root->left) && check_complete(root->right);
}

void traverse(Node *root, int depth, vector<vector<int>> &layer)
{
    if (root == nullptr)
        return;
    while (layer.size() <= depth)
        layer.push_back({});
    layer[depth].push_back(root->value);
    traverse(root->left, depth + 1, layer);
    traverse(root->right, depth + 1, layer);
}

int main(int argc, char const *argv[])
{
    string str;
    Node *root = newNode();
    vector<vector<int>> layer;
    bool complete = true;
    while (cin >> str)
    {
        if (str == "()")
        {
            if (!complete || !check_complete(root))
                printf("not complete\n");
            else
            {
                traverse(root, 0, layer);
                for (int i = 0; i < layer.size(); i++)
                    for (int j = 0; j < layer[i].size(); j++)
                    {
                        if (i == layer.size() - 1 && j == layer[i].size() - 1)
                            printf("%d\n", layer[i][j]);
                        else
                            printf("%d ", layer[i][j]);
                    }
            }
            // printf("end\n");
            free_tree(root);
            root = newNode();
            layer.clear();
            complete = true;
        }
        else
        {
            if (!complete)
                continue;
            int i = 1;
            for (; i < str.size(); i++)
                if (str[i] == ',')
                    break;
            str[i] = '\0';
            int value = atoi(str.data() + 1);
            str = str.substr(i + 1, str.size() - i - 2);
            // printf("%d %s\n", value, str.data());
            add_node(root, value, str, complete);
        }
    }

    return 0;
}
