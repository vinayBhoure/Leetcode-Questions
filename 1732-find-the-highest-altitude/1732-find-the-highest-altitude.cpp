class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0; i<gain.size(); i++)
        {
            sum += gain[i];
            maxi = max(maxi,sum);
        }
        
        if(maxi > 0) return maxi;
        else{
            return 0;
        }
    }
};