#include <bits/stdc++.h>
using namespace std;
#define ll long long
class TrieNode
{
public:
    TrieNode *link[2];
    TrieNode()
    {
        memset(link, 0, sizeof(link));
    }
    bool contains(int bit)
    {
        return link[bit] != NULL;
    }
    TrieNode *getNode(int bit)
    {
        return link[bit];
    }
    void put(int bit)
    {
        link[bit] = new TrieNode();
    }
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->contains(bit))
            {
                node->put(bit);
            }
            node = node->getNode(bit);
        }
    }
    int getMax(int num)
    {
        TrieNode *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->contains(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->getNode(1 - bit);
            }
            else
            {
                node = node->getNode(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for (auto &it : arr1)
    {
        trie.insert(it);
    }
    int maxi = 0;
    for (auto &it : arr2)
    {
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}
int main()
{

    return 0;
}