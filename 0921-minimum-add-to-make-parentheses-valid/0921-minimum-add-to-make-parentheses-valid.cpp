class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves=0;
        stack<char>st;
        for(char c :s){
            if(c=='('){
                st.push(c);
                moves+=1;
            }
            else{
                if(!st.empty())
                 {if(st.top()=='('){
                    st.pop();
                    moves-=1;
                }
                else{
                    st.push(c);
                    moves+=1;
                }
                }

                else{
                    st.push(c);
                    moves+=1;
                }
            }
        }
        
        return moves;
    }
};