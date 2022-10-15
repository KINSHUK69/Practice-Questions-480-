/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/



class Solution {
public:
    int maxProfit(vector<int>& prices) // T.C. = O(N^2)
    {
        int max_price=INT_MIN,min_price=INT_MIN,profit,m=0;
        int i=0,n=prices.size(),j=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
               if(prices[j]>prices[i]) 
                 m=max(m,prices[j]-prices[i]);
            }
        }
        return (m>0)?m:0;
    }
  
    int maxProfit(vector<int>& prices)   // T.C. = O(N)
    {
        int min_price=INT_MAX,m=INT_MIN;
        int i=0,n=prices.size(),j=0;
        for(i=0;i<n;i++)
        {
            if(prices[i]<min_price)
              min_price=prices[i];
            m=max(m,prices[i]-min_price);
            
        }
        return (m>0)?m:0;
    }
};
