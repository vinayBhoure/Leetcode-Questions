class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            string word = p.first;
            int steps = p.second;
            
            if(word == endWord) return steps;
            
            for(int i=0; i<word.length(); i++)
            {
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++)
                {
                    word[i] = ch;
                    
                    if(st.find(word) != st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};