class Solution {
public:
    typedef long long int ll;
    int minOperations(vector<int>& nums, int t) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        ll sum=0;
        map<int,int>m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            m[nums[i]]++;
            if(sum==t){
                return 0;
            }
        }
        if(sum<t){
            return -1;
        }
        int i=0,ans=0;
        while(t){
            int k=t&1;
            int f=0;
            if(k){
                int num=pow(2,i);
                //cout<<num;
                if(m.count(num)){
                    m[num]--;
                    if(m[num]==0){
                        m.erase(num);
                    }
                    i++;
                    t=t>>1;
                    continue;
                }
                ll s=0;
                auto it=m.begin();
                for(;it->first<=num && it!=m.end();it++){
                    s+=(it->first * it->second);
                }
                //cout<<s<<" ";
                if(s>=num){
                    it--;
                    int no=num;
                    vector<int>a;
                    while(no!=0){
                        if(it->first>no){
                            it--;
                        }
                        no=no-it->first;
                        it->second--;
                        if(it->second==0){
                            a.push_back(it->first);
                            it--;
                        }
                    }
                    for(auto x:a){
                        m.erase(x);
                    }
                }else{
                    int z=it->first;
                    //free(it);
                    f=1;
                    m[z]--;
                    if(m[z]==0){
                        m.erase(z);
                    }
                    //cout<<i<<" "<<z<<endl;
                    ans++;
                    m[z/2]+=2;
                }
            }
            if(f==0){
                i++;
                t=t>>1;
            }
        }
        return ans;
    }
};