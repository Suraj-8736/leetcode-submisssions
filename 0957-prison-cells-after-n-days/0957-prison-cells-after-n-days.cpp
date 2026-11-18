class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> mp;

        vector<int> curr = cells;

        while(n > 0) {
            string s = "";
            for(int x : curr) {
                s += to_string(x);
            }

            if(mp.count(s)) {
                int cycle = mp[s] - n;
                n %= cycle;
            }

            mp[s] = n;

            if(n == 0) break;

            vector<int> nnew(8, 0);

            for(int i = 1; i < 7; i++) {
                if(curr[i-1] == curr[i+1]) {
                    nnew[i] = 1;
                }
            }

            curr = nnew;
            n--;
        }

        return curr;
    }
};