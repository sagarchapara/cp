#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    map<int, int> next;
    bool isEndOfTheWord;
    bool count;

    TrieNode(): count(0), isEndOfTheWord(false){};
};

class Trie
{
public:
    vector<TrieNode> tree;

    Trie()
    {
        tree.emplace_back();
    }

    void insert(string& word)
    {
        int curr = 0;
        tree[curr].count++;
        for(char c: word){
            if(tree[curr].next.find(c) == tree[curr].next.end())
            {
                //create a new node
                tree[curr].next[c] = tree.size();
                tree.emplace_back();
            }
            curr = tree[curr].next[c];
            tree[curr].count++;
        }

        tree[curr].isEndOfTheWord = true;
    }

    bool search(string& s)
    {
        int curr = 0;

        for(char c: s){
            if(tree[curr].next.find(c) == tree[curr].next.end()){
                return false;
            }
            curr = tree[curr].next[c];
        }

        return tree[curr].isEndOfTheWord;
    }

};
