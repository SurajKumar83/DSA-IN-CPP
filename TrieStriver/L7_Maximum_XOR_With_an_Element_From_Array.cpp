#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *link[2];

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

// Method 1 Brute Force Method
vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<int> ans;
    for (auto &q : queries)
    {
        int maxi = -1;
        for (auto &it : nums)
        {
            if (it <= q[1])
            {
                maxi = max(maxi, q[0] ^ it);
            }
        }

        ans.push_back(maxi);
    }
    return ans;
}
// Method 2 Using Trie Data Structure
vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &queries)
{
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> vq;
    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
        vq.push_back({queries[i][1], {queries[i][0], i}});
    }
    vector<int> ans(q, -1);
    Trie trie;
    int n = nums.size();
    sort(vq.begin(), vq.end());
    int ind = 0;
    for (int i = 0; i < q; i++)
    {
        int ai = vq[i].first;
        int xi = vq[i].second.first;
        int qind = vq[i].second.second;
        while (ind < n && nums[ind] <= ai)
        {
            trie.insert(nums[ind]);
            ind++;
        }

        if (ind != 0)
            ans[qind] = trie.getMax(xi);
    }
    return ans;
}