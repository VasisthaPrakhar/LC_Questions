class Solution {
public:
    vector<int>ans;
    void fun(int n,int k){
        if(k>n){
            return;
        }else{
            ans.push_back(k);
            fun(n,k*10);
        }
        if(k%10!=9)
        fun(n,k+1);
    }
    vector<int> lexicalOrder(int n) {
        fun(n,1);
        return ans;
    }
};