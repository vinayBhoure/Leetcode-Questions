class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tm = 0;
       for(int i=0; i<tickets.size(); i++){
           if( i<=k && tickets[i] >= tickets[k]) tm += tickets[k];
           else if(i>k && tickets[i] >= tickets[k]) tm += tickets[k]-1;
           else{
               tm += tickets[i];
           }
       }
        return tm;
    }
};