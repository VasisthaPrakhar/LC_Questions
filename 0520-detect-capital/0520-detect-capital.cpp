class Solution {
public:
    bool detectCapitalUse(string word) {
        int cu=0,cl=0;
        for(auto x:word){
            if(x==toupper(x)){
                cu++;
            }else{
                cl++;
            }
        }
        if(cu==0){
            return true;
        }else if(cl==0){
            return true;
        }else if(cu==1){
            if(word[0]==toupper(word[0])){
                return true;
            }
        }        
        return false;
    }
};