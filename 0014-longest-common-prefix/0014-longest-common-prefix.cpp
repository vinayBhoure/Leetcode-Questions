class TrieNode{
public:
    char ch;
    TrieNode* children[26];
    int countchild;
    bool isterminal;
    
    TrieNode(char ch){
        this->ch = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        countchild = 0;
        isterminal = false;
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(char ch){
        root = new TrieNode(ch);
    }
    
    void insertutil(TrieNode* root, string word)
    {
       //base case
        if(word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        
        TrieNode* child;
        int i = word[0]-'a';
        
        if(root->children[i] != NULL)
        {
            child = root->children[i];
        }
        else{
            child = new TrieNode(word[0]);
            root->countchild++;
            root->children[i] = child;
        }
        
        insertutil(child,word.substr(1));
    }
    
    void insertword(string word)
    {
        insertutil(root,word);
    }
    
    void lcp(string str, string &ans)
    {
       for(int i=0; i<str.length(); i++)
       {
           char ch = str[i];
          if(root->countchild == 1)
          {
              ans = ans + ch;
              
              int i = ch - 'a';
              root = root->children[i];
          }
           else{
               break;
           }
           
           if(root->isterminal)
           {
               break;
           }
       }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     /*
        string ans  = "";
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        */
        /////////////////////////    USING TRIES
        
       
        
        Trie *t = new Trie('\0');
        
        for(int i=0; i< strs.size(); i++)
        {
            if(!strs[i].size()) return "";
            
            t->insertword(strs[i]);
        }
        
        string first = strs[0];
        string ans = "";
        
        t->lcp(first, ans);
        return ans;
    }
};