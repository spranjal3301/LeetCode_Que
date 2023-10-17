class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isEnd;
    TrieNode(char data):data(data){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEnd = false;
    }
};




class Trie {
    TrieNode* root;

    void insert(TrieNode *root,string word){
        if(word.size()==0){
            root->isEnd=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;

        //! char present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        insert(child,word.substr(1));
    }

    bool Search(TrieNode* root,string word){
        if(word.size()==0){
            return root->isEnd;
        }

        int index=word[0]-'a';
        TrieNode* child=NULL;

        if (root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return false;
        }
        return Search(child,word.substr(1));   
    }
    bool prefix(TrieNode* root,string word){
        if(word.size()==0){
            return true;
        }

        int index=word[0]-'a';
        TrieNode* child=NULL;

        if (root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            return false;
        }
        return prefix(child,word.substr(1));   
    }
public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insert(string word) {
        insert(root,word);
    }
    
    bool search(string word) {
        return Search(root,word);
        // return true;
    }
    
    bool startsWith(string word) {
        return prefix(root,word);
        // return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */