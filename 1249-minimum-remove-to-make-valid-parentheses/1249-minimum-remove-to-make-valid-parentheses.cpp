class Solution {
public:
    string solution1(string s){
        int n = s.length();
        
        unordered_set<int> toRemove;
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') //store index of '('
                st.push(i);
            else  if(s[i] == ')') {
                if(st.empty()) { //invalid ')'
                    toRemove.insert(i);
                } else {
                    st.pop(); //balancing with open '('
                }
            }
        }
        
        //suppose the input is  "(("
        //Then, we won't be adding them in the toRemove set to remove later
        //So, adding here
        while(!st.empty()) {
            toRemove.insert(st.top());
            st.pop();
        }
        
        string result = "";
        
        for(int i = 0; i<n; i++) {
            if(toRemove.find(i) == toRemove.end())
                result.push_back(s[i]);
        }
        
        return result;
    }
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int openCnt = 0;
        int closeCnt = 0;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] == ')' && openCnt == 0) continue;
            if(s[i] == ')' && openCnt > 0) openCnt--;
            if(s[i] == '(') openCnt++;
            ans.push_back(s[i]);
        }
        string res = "";
        if(ans.size() > 0){
             for(int i=ans.size()-1; i>=0; i--){
                if(ans[i] == '(' && closeCnt == 0) continue;
                if(ans[i] == '(' && closeCnt > 0) closeCnt--;
                if(ans[i] == ')') closeCnt++;
                res.push_back(ans[i]);
             }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};