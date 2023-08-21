// leetcode 208, implementing trie


class TrieNode{
public:
    TrieNode(){
        is_word_complete = false;
        for(int i=0;i<26;i++){
            children.push_back(nullptr);
        }
    }
    friend class Trie;
private:
    bool is_word_complete;
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode;    
    }
    
    void insert(string word) {
        TrieNode* node;
        node = root;
        int size = word.length();
        char c;
        for(int i=0;i<size;i++){
            c = word[i];
            if(node->children[c-'a']==NULL){
                node->children[c-'a'] = new TrieNode;
            }
            node = node->children[c-'a'];
        }
        node->is_word_complete = true;
    }
    
    bool search(string word) {
        TrieNode* node;
        node = root;
        int size = word.length();
        char c;
        for(int i=0;i<size;i++){
            c = word[i];
            node = node->children[c-'a'];
            if(node==NULL){
                return false;
            }
        }
        if(node->is_word_complete){
            return true;
        }else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* node;
        node = root;
        int size = prefix.length();
        char c;
        for(int i=0;i<size;i++){
            c = prefix[i];
            node = node->children[c-'a'];
            if(node==NULL){
                return false;
            }
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
