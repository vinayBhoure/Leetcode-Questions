class Solution {
public:
    bool isPalindrome(int left, int right, string &s)
    {
        while(left < right)
        {
            if(s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
     
        int start = 0;
        int maxlen = 0;
        
        for(int i =0; i<s.size();i++)
        {
            for(int j =i; j<s.size(); j++)
            {
                if(isPalindrome(i,j,s))
                {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};