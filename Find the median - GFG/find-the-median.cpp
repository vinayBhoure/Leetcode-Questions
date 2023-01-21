//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		
		{
		sort(v.begin(), v.end());
		    // Code here.
		    int l = v.size();
		    double ans;
		    if(l&1)
		    {
		       ans=  v[l/2];
		    }
		    else{
		        ans= double (v[l/2])/2 + double (v[l/2 - 1])/2; 
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends