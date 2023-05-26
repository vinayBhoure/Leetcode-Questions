class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
      stack<int> s;
        vector<int> ans(prices.size());
        for(int i=prices.size()-1;i>=0;i--){
           
            while(!s.empty()&& s.top()>prices[i])
            s.pop();
            if(s.empty()){
            ans[i]=prices[i];
            s.push(prices[i]);
            }
            else
            {
            ans[i]=prices[i]-s.top();
            s.push(prices[i]);
            
            }
            
        }
        return ans;
    }
};