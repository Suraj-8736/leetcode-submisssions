class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0,ps=0;
        stack<int>st;
        for(char c :s){
            if(c=='('){
                st.push(score);
                score=0;       
            }
            else{
                ps=st.top();
                st.pop();
                if(score==0) score =1 ;
                else score=score*2;
                score+=ps;
            }          
        }
        return score;
    }
};