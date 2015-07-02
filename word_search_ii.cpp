#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class TrieNode{
public:
    TrieNode(){
        count = 0;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }   
    int count;
    TrieNode *children[26];
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insertWord(string w){
        TrieNode *cur = root;
        for (int i = 0 ; i < w.size(); i++){
            int j = w[i]-'a';
            if (cur->children[j] == NULL){
                cur->children[j] = new TrieNode();
            }
            if(i == w.size()-1)
                cur->children[j]->count++;
                
            cur = cur->children[j];
        }
    }
    
    bool searchWord(string w){
        TrieNode *cur = root;
        for (int i = 0 ; i < w.size(); i++){
            int j = w[i]-'a';
            if (cur->children[j] == NULL){
                return false;
            }
            if(i == w.size()-1 && cur->children[j]->count == 0)
                return false;
                
            cur = cur->children[j];
        }
        return true;
    }
    
    bool searchPrefix(string w){
        TrieNode *cur = root;
        for (int i = 0 ; i < w.size(); i++){
            int j = w[i]-'a';
            if (cur->children[j] == NULL){
                return false;
            }
            cur = cur->children[j];
        }
        return true;        
    }
};
    
class Solution {
private:
    //backtracking algorithm
    void search(unordered_set<string> &res, vector<vector<char> >& board, vector<string>& words , Trie *tr, vector<vector<bool> > &used,int i, int j , string cur){
        if( i<0 || j < 0 || i>=board.size() || j>=board[0].size() || used[i][j]) return;

        cur += board[i][j];
        if(tr->searchPrefix(cur) == false) return;
        if(tr->searchWord(cur) == true){
            res.insert(cur);
        }
        
        used[i][j] = true;
        search(res,board,words,tr,used,i-1,j,cur);
        search(res,board,words,tr,used,i+1,j,cur);
        search(res,board,words,tr,used,i,j-1,cur);
        search(res,board,words,tr,used,i,j+1,cur);
        used[i][j] = false;
    }
    
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        unordered_set<string> res;
        vector<string> ret;
        if(words.size() == 0) return ret;
        if(board.size()==0 || board[0].size()==0) return ret;
        
        Trie *tr = new Trie();
        for ( string w : words ){
            tr->insertWord(w);
        }
        
        vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(),false) );
        for(int i = 0; i < board.size() ; i++){
            for(int j = 0; j<board[0].size() ; j++ ){
                string cur = "";
                search(res,board,words,tr,used,i,j,cur);
            }
        }
        
        
        
        return vector<string>(res.begin(),res.end());

    }
};



int main(){
    Solution s;
    vector<vector<char> > board(2,vector<char>(2));
    board[0][0] = 'a';
    board[0][1] = 'b';
    board[1][0] = 'c';
    board[1][1] = 'd';
    vector<string> words(1,"cdba");
    vector<string> res = s.findWords(board,words);
    cout << "results:"<<endl;
    for(string w:res) cout << w<<endl;
    return 0;
}

