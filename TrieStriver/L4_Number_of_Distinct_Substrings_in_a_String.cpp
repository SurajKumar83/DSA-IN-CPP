#include <bits/stdc++.h>
using namespace std;
// Brute Force Time->O(N*N*logM) where m is the number of elements in the set,and
// space-> O(N*N*N) for set
// Using Iteration method
int distinctSubstring(string &word)
{
    set<string> st;
    int n = word.length();
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = i; j < n; j++)
        {
            str += word[j];
            if (st.find(str) == st.end())
            {
                st.insert(str);
            }
        }
    }
    return st.size();
}
class TrieNode
{
public:
    TrieNode *child[26];
    TrieNode()
    {
        memset(child, 0, sizeof(child));
    }
    bool isContain(char ch)
    {
        return child[ch - 'a'] != NULL;
    }
    void setNode(char ch)
    {
        child[ch - 'a'] = new TrieNode();
    }
    TrieNode *getNode(char ch)
    {
        return child[ch - 'a'];
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string str,int &ans)
    {
        TrieNode *node = root;
        for (char ch : str)
        {
            if (!node->isContain(ch))
            {
                node->setNode(ch);
                ans++;
            }
            node = node->getNode(ch);
        }
    }
};

int distinctSubstring(string &word)
{
    int ans=0;
    Trie trie;
    for(int i=0;i<word.length();i++){
        trie.insert(word.substr(i),ans);
    }
    return ans;
}