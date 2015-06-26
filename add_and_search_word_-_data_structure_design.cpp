class TrieNode{
public:
    //constructor
    int count;
    TrieNode *children[26];
    TrieNode(){
        count = 0;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
    }
};

class WordDictionary {
private:
    TrieNode *root;
public:
    //constructor
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++){
            int k = word[i] - 'a';
            if(node->children[k] == NULL){
                node->children[k] = new TrieNode();
            }
            if(i == word.size()-1){
                node->children[k]->count++;
            }
            node = node->children[k];
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode *node = root;
        if(!word.size() ) return false;
        return dfsSearch(0,root,word);
    }
    
    bool dfsSearch(int index, TrieNode *node, string &s){
        if(node == NULL) return false;

        if(s[index] != '.'){
            int k = s[index]-'a';
            if (node->children[k] == NULL) return false;
            if (index == s.size()-1 ){
                if(node->children[k]->count == 0) return false;
                else return true;
            }
            return dfsSearch(index+1, node->children[k], s);
        }
        if(s[index] == '.'){
            if(index == s.size()-1){
                for(int i = 0; i < 26 ; i++){
                    if (node->children[i] == NULL) continue;
                    if ( node->children[i]->count > 0 ) return true;
                }
                return false;
            }
            else{
                for(int i = 0; i < 26 ; i++){
                    if ( dfsSearch(index+1,node->children[i],s) ) return true;
                }
                return false;
            }
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");