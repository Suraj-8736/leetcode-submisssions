class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0, bestBuy=prices[0];
        for(int v:prices){
            if(v>bestBuy){
                maxPro=max(maxPro,v-bestBuy);
            }
            bestBuy=min(bestBuy,v);
        }
        if(maxPro>0)return maxPro;
        return 0;
    }
};