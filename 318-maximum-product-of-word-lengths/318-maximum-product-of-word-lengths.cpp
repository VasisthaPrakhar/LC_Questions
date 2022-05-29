class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>mask(n);
        int ma=0;
        for(int i=0;i<n;i++){
            for(auto x:words[i]){
                mask[i]=mask[i] | (1 << (x-'a'));
            }
            for(int j=0;j<i;j++){
                if((mask[i] & mask[j])==0){
                    ma=max(ma,(int)words[i].length()*(int)words[j].length());
                }
            }
        }
        return ma;
    }
};