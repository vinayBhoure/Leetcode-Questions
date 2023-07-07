class Solution {
    unordered_map<string,int> map;
    vector<vector<string>> ans;
    string str;
public:
    
    void dfs(string word, vector<string>&seq)
    {
        if(word == str)
        {
            reverse(begin(seq), end(seq));
            ans.push_back(seq);
            reverse(begin(seq), end(seq));
            return;
        }
        
        int steps = map[word];
        for(int i=0; i<word.size(); i++)
        {
            char original = word[i];
            for(char ch='a'; ch<='z'; ch++)
            {
                word[i]=ch;
                
                if(map.find(word)!=map.end() && map[word]+1 == steps)
                {
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
        
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push({beginWord});
        st.erase(beginWord);
        map[beginWord] = 1;
        str = beginWord;
        
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            int steps = map[word];
            
            if(word == endWord) break;
            
            for(int i=0; i<word.size(); i++)
            {
                char original = word[i];
                for(char ch='a'; ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        map[word] = steps+1;
                    }
                }
                word[i] = original;
            }
        }
        
        if(map.find(endWord) != map.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};