class Solution {
public:
    bool isPalindrome(int x) {
        int dupl=x;
        long revx=0;
        while(x>0){
            revx=(revx*10)+(x%10);
            x=x/10;
        }
        if(revx==dupl) return "true";
        else return false;
    }
};