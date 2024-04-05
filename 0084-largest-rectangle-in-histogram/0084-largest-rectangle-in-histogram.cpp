class Solution {
public:
    int solve(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            int area = (right[i]-left[i]+1)*heights[i];
            maxi = max(maxi, area);
        }
        return maxi;
    }
    
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        int maxi = 0;
        stack<int> st;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int h = heights[st.top()];
                st.pop();
                int w = 0;
                if(st.empty()) w = i;
                else w = i-st.top()-1;
                maxi = max(maxi, w*h);
            }
            st.push(i);
        }
        return maxi;
    }
};