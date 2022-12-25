class Solution {
public:
    bool check(vector<int>&v,vector<int>&v1,int k){
        int a=v[0]+v1[0],b=v[1]+v1[1],c=v[2]+v1[2];
        if(a<k || b<k || c<k){
            return false;
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        unordered_map<int,vector<int>>ml,mr;
        int n=s.length();
        if(k==0){
            return 0;
        }
        int ans=n;
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }else if(s[i]=='b'){
                b++;
            }else{
                c++;
            }
            if(a>=k && b>=k && c>=k){
                ans=min(ans,i+1);
            }
            ml[i]={a,b,c};
        }
        if(a<k || b<k || c<k){
            return -1;
        }
        a=0,b=0,c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                a++;
            }else if(s[i]=='b'){
                b++;
            }else{
                c++;
            }
            if(a>=k && b>=k && c>=k){
                ans=min(ans,n-i);
            }
            mr[i]={a,b,c};
        }
        int j=0;
        for(int i=0;i<n;i++){
            int f=0;
            while(j<n && check(ml[i],mr[j],k)){
                j++;
                f=1;
            }
            if(f){
                j--;
            }
            ans=min(ans,n-(j-i-1));
        }
        return ans;
    }
};