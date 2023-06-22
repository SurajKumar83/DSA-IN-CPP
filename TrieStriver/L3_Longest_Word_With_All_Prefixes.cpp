// A string is called a complete string if
// every prefix of this string is also
// present in the array 'A'.
// We have to find longest complete string in the array 'A'.
// if there are multiple strings with the same length, return lexicographically smallest one else return "None".
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool flag;
    TrieNode *child[26];
    TrieNode()
    {
        flag = false;
        memset(child, 0, sizeof(child));
    }
    void setNode(char ch)
    {
        child[ch - 'a'] = new TrieNode();
    }
    TrieNode *getNode(char ch) // give reference trie of ch
    {
        return child[ch - 'a'];
    }
    bool isContained(char ch)
    {
        return child[ch - 'a'] != NULL;
    }
    void setflag()
    {
        flag = true;
    }
    bool isflag()
    {
        return flag;
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
    void insert(string str)
    {
        TrieNode *node = root;
        for (char ch : str)
        {
            if (!node->isContained(ch))
            {
                node->setNode(ch);
            }
            node = node->getNode(ch); // move to reference trie;
        }
        node->setflag();
    }
    bool checkIfPrefixExits(string str)
    {

        TrieNode *node = root;
        for (char ch : str)
        {
            if (!node->isContained(ch))
            {
                return false;
            }

            node = node->getNode(ch);
            if (node->isflag() == false)
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (auto &it : a)
    {
        trie.insert(it);
    }
    string longest = "";
    for (auto &it : a)
    {
        if (trie.checkIfPrefixExits(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    return longest.length() ? longest : "None";
}
