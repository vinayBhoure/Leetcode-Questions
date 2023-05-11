class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
         vector<vector<int>> v(n);
  
  if (n > 2)
  {
    for(int i = 0; i < 2; i++)
    {
      for(int j = 0; j <= i; j++)
      {
        v[i].push_back(1);
      }
    }
    
    for (int i = 2; i < n; i++)
    {
      v[i].push_back(1);
      for (int j = 1; j < i; j++)
      {
        v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]);
      }
      v[i].push_back(1);
    }
  }
  else
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j <= i; j++)
      {
        v[i].push_back(1);
      }
    }
  }
  
  return v;
    }
};