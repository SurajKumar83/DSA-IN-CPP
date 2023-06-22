#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool ended;
    TrieNode *children[26];

    TrieNode()
    {
        ended = false;                         // when the word is complete (mark that node as true)
        memset(children, 0, sizeof(children)); // for 26 possible Childrens (for next letter)
    }
    bool isContains(char ch)
    {
        return children[ch - 'a'] != NULL;
    }
    void setNode(char ch)
    {
        children[ch - 'a'] = new TrieNode();
    }
    TrieNode *getNode(char ch)
    {
        return children[ch - 'a'];
    }
    void setEnd()
    {
        ended = true;
    }
    bool isEnd()
    {
        return ended;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            if (!node->isContains(ch))
            {
                node->setNode(ch);
            }
            node = node->getNode(ch);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {

            if (!node->isContains(ch))
                return false;
            node = node->getNode(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {

            if (!node->isContains(ch))
                return false;
            node = node->getNode(ch);
        }
        return true;
    }
};
