#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    int endwith;
    int countprefix;
    TrieNode *child[26];
    TrieNode()
    {
        endwith = 0, countprefix = 0;
        memset(child, 0, sizeof(child));
    }
    bool isContain(char ch)
    {
        return child[ch - 'a'] != NULL;
    }
    TrieNode *getNode(char ch)
    {
        return child[ch - 'a'];
    }
    void putNode(char ch)
    {
        child[ch - 'a'] = new TrieNode();
    }
    void setendwith()
    {
        endwith++;
    }
    void setcountprefix()
    {
        countprefix++;
    }
    void resetendwith()
    {
        endwith--;
    }
    void resetcountprefix()
    {
        countprefix--;
    }
    int getendwith()
    {
        return endwith;
    }
    int getcountprefix()
    {
        return countprefix;
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
    void insert(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->isContain(ch))
            {
                node->putNode(ch);
            }
            node = node->getNode(ch);
            node->setcountprefix();
        }
        node->setendwith();
    }
    int countWordsEqualTo(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->isContain(ch))
            {
                return 0;
            }
            node = node->getNode(ch);
        }
        node->getendwith();
    }
    int countWordsStartWith(string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->isContain(ch))
            {
                return 0;
            }
            node = node->getNode(ch);
        }
        node->getcountprefix();
    }
    void erase(string &word)
    {

        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->isContain(ch))
            {
                return;
            }
            node = node->getNode(ch);
            node->resetcountprefix();
        }
        node->resetendwith();
    }
};