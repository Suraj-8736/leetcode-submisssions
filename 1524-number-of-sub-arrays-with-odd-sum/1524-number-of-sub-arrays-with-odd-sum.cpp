#define ll long long
const ll M = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int   sm = 0, os = 0, es = 0;
        ll ans = 0;
        for(int i = 0; i < a.size(); i++){
            sm += a[i];
            if(sm%2){
                ans += es+1;
                os++;
            }
            else{
                ans += os;
                es++;
            }
            ans %= M;
        }
        return ans;
    }
};