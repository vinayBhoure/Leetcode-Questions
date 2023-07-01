class TrieNode{
public:
    char ch;
    TrieNode* children[26];
    bool isterminal;
    
    TrieNode(char ch)
    {
        this->ch = ch;
        for(int i =0; i<26; i++)
            children[i] = NULL;
        isterminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        
        int i = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[i] != NULL)
        {
            child = root -> children[i];
        }
        
        else{
            child = new TrieNode(word[0]);
            root -> children[i] = child;
        }
        
        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root, string word)
    {
      if(word.length() == 0)
      {
          return root->isterminal;
      }
        
        int i = word[0] - 'a';
       TrieNode* child;
        
        if(root->children[i] != NULL)
        {
            child = root->children[i];
        }
        else{
            return false;
        }
        
        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
    
     bool prefixUtil(TrieNode* root, string word)
    {
      if(word.length() == 0)
      {
          return true;
      }
        
        int i = word[0] - 'a';
       TrieNode* child;
        
        if(root->children[i] != NULL)
        {
            child = root->children[i];
        }
        else{
            return false;
        }
        
        return prefixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
          return prefixUtil(root,prefix)  ;  
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */