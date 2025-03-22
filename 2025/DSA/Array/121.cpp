class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = prices[0], max_profit = 0;

        for (const auto &price : prices)
        {
            if (price < min_price)
                min_price = price;

            int current_profit = price - min_price;

            if (current_profit > max_profit)
                max_profit = current_profit;
        }
        return max_profit;
    }
};