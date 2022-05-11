class Solution {
public:
    long long int ans=0;
    void fun(int id,int idx,int n){
        if(idx>=n){
            ans++;
            return;
        }
        for(int i=id;i<5;i++){
            fun(i,idx+1,n);
        }
    }
    int countVowelStrings(int n) {
        fun(0,0,n);
        return ans;        
    }
};