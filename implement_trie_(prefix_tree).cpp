
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
        for(int i = 0; i<26; ++i){
            children[i] = NULL;
        }
    }
    int count;
    TrieNode *children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0; i<word.size(); i++){
            int n = word[i]-'a';
            if (cur->children[n] == NULL){
                cur->children[n] = new TrieNode();
            }
            if(i == word.size()-1){
                cur->children[n]->count++;
            }
            cur = cur->children[n];
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for(int i = 0; i<word.size(); i++){
            int n = word[i]-'a';
            if(cur->children[n] == NULL) return false;
            if(cur->children[n]->count == 0 && i == word.size()-1 ) return false;
            cur = cur->children[n];
        }
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i = 0; i<prefix.size(); i++){
            int n = prefix[i]-'a';
            if(cur->children[n] == NULL) return false;
            cur = cur->children[n];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");