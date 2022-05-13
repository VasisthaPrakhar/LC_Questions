class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int n=c.size();
        unordered_map<int,int>m;
        int i=0,j=0,ans=1e6+1;
        while(j<n){
            m[c[j]]++;
            while(i<=j && m[c[j]]>1){
                if(m[c[j]]==2){
                    ans=min(ans,j-i+1);
                }
                m[c[i]]--;
                i++;
            }
            j++;
        }
        return ans==1e6+1?-1:ans;
    }
};