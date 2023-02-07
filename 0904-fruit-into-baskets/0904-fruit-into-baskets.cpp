class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n=a.size();
        if(n<=2){
            return n;
        }
        int j=0,i=0,ans=2;
        unordered_map<int,int>m;
        while(j<n){
            m[a[j]]++;
            while(i<j && m.size()>2){
                m[a[i]]--;
                if(m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};