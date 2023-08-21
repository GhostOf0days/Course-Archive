class TrieNode {
public:
    TrieNode(){
        count = 0;
        is_word_complete = false;
        for(int i=0;i<26;i++){
            // initialize all 26 pointers to NULL
            // we can't do children[i] = NULL; here, because subscripting doesn't make sense until we add elements into the vector.
            children.push_back(nullptr);
        }
    }
    // so that we can use TrieNode's private members in Trie.
    friend class Trie;
// private:
    // count how many words are using this letter.
    int count;
    bool is_word_complete;
    // each node has 26 children, storing letters from 'a' to 'z'
    vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        // root is just a pointer
        root = new TrieNode;
    }
    void insert(string word) {
        char c;
        int size = word.length();
        TrieNode* node = root;
        for(int i=0;i<size;i++){
            c = word[i];
            if(node->children[c-'a']==NULL){
                node->children[c-'a'] = new TrieNode;
            }
            // no matter node->children[c-'a'] is NULL or not.
            node->children[c-'a']->count++;
            node = node->children[c-'a'];
        }
        node->is_word_complete = true;
    }
    
// private:
    // we do not store characters in root.
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        Trie trie;
        TrieNode* node = trie.root;
        int size = strs.size();
        for(int i=0;i<size;i++){
            // insert every word in strs into this trie.
            trie.insert(strs[i]);
        }
        int size1 = strs[0].size();
        //cout<<"size1 is "<<size1<<endl;
        string s = strs[0];
        //cout<<"s is "<<s<<endl;
        for(int i=0;i<size1;i++){
            //cout<<"count is "<<node->children[s[i]-'a']->count<<endl;
            // the subscripting here has to be an integer from 0 to 25
            if(node->children[s[i]-'a']!=NULL && node->children[s[i]-'a']->count==size){
                res.push_back(s[i]);
                node = node->children[s[i]-'a'];
            }else{
                break;
            }
        }
        return res;
    }
};
