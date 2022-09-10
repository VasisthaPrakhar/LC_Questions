class Solution {
public:
    void fun(int idx,long long int &ans,vector<int>&a,vector<int>&suf,int n,int &next){
        int index=next,k=suf[idx];
        //cout<<index<<" "<<idx<<endl;
        for(int i=index-1;i>=idx;i--){
            int temp;
            if((a[i]%k)!=0){
                temp=(a[i]/k);
                
            }else{
                temp=(a[i]/k)-1;
            }
            ans+=temp;
            k=a[i]/(temp+1);
        }
        for(int i=0;i<idx;i++){
            if(suf[i]>k){
                suf[i]=k;
            }
        }
    }
    long long minimumReplacement(vector<int>& a) {
        int n=a.size();
        set<int>s;
        vector<int>suf(n,-1);
        for(int i=n-1;i>=0;i--){
            s.insert(a[i]);
            suf[i]=*s.begin();
        }
        int idx=-1,next;
        long long int ans=0;
        for(int i=n-1;i>=0;i--){
            if(suf[i]!=a[i]){
                next=i+1;
                while(i>=0 && suf[i]!=a[i]){
                    i--;
                }
                i++;
                idx=i;
                fun(idx,ans,a,suf,n,next);
            }
            
        }
        
        return ans;
    }
};