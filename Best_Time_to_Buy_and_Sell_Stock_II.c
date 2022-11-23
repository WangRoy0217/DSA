int maxProfit(int* prices, int pricesSize){
    int i,profit=0;
    if(pricesSize == 0)
        return 0;
    for(i=1;i<pricesSize;i++)
    {
        if(prices[i-1] < prices[i])
        {
            profit+=(prices[i]-prices[i-1]);
        }
    }
    return profit;

}
