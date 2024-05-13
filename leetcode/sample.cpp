#include <iostream>
#include <vector>
#include <set>

using namespace std;

class TrieNode{
public:
    int isWord;
    int count;
    int next[26];
    TrieNode(): isWord(false), count(0)
    {
        for(int i=0;i<26;i++)
        {
            next[i] = -1;
        }
    };
};

class Trie{
public: 
    vector<TrieNode> tree;

    Trie()
    {
        tree.emplace_back();
    }

    void insert(string& s)
    {
        int curr = 0;
        for(char c: s){
            int idx = c-'a';
            if(tree[curr].next[idx] == -1)
            {
                tree[curr].next[idx] = tree.size();
                tree.emplace_back();
            }
            curr = tree[curr].next[idx];
        }
        tree[curr].isWord = true;
    }

    bool findword(string& s)
    {
        int curr =0;
        for(char c: s)
        {
            int idx = c-'a';
            if(tree[curr].next[idx] == -1) return false;
            curr = tree[curr].next[idx];
        }

        return tree[curr].isWord;
    }

};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        Trie tree;

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                dfs(i,j,board,visited,"", tree);
            }
        }

        vector<string> ans;

        for(auto word: words){
            if(tree.findword(word)){
                ans.push_back(word);
            }
        }

        return ans;
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, string prev_string, Trie& tree)
    {
        int n = board.size();
        int m = board[0].size();

        if(visited[i][j]) return;

        visited[i][j] = true;

        string curr_string = prev_string + board[i][j];

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        tree.insert(curr_string);

        for(int k=0;k<4;k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

            dfs(nx, ny, board, visited, curr_string, tree);
        }

        visited[i][j] = false;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> grid {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};

    vector<string> words {"oath","pea","eat","rain"};

    vector<string> matches = solution.findWords(grid, words);

    return 0;
}
