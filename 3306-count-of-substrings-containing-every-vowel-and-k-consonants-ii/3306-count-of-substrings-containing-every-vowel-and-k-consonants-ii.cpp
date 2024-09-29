class Solution {
public:
    typedef long long int ll;
    bool check(char ch){
        return (ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u');
    }
    long long countOfSubstrings(string &w, int k) {
        int n=w.length();
        ll j=0,i=0,ans=0,p=n;
        vector<int>pos(n);
        for(int i=n-1;i>=0;i--){
            pos[i]=p;
            if(!check(w[i])){
                p=i;
            }
        }
        unordered_map<char,int>mp;
        while(j<n){
            if(check(w[j])){
                mp[w[j]]++;
            }else{
                k--;
            }
            while(i<=j && mp.size()==5 && k<=0){
                if(k==0)
                    ans+=pos[j]-j;
                if(check(w[i])){
                    mp[w[i]]--;
                    if(mp[w[i]]==0){
                        mp.erase(w[i]);
                    }   
                }else{
                    k++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};