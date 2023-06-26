class Solution {
public:
    typedef long long int ll;
    long long totalCost(vector<int>& a, int z, int c) {
        int n=a.size();
        int i=0,j=n-1;
        //cout<<n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>l,r;
        ll ans=0,v=0;
        while(i<=j && v<z){
            if(l.size()==c && r.size()==c){
                auto k=r.top();
                auto x=l.top();
                if(x.first==k.first){
                    if(x.second<k.second){
                        ans+=x.first;
                        l.pop();
                    }else{
                        ans+=k.first;
                        r.pop();
                    }
                }else if(k.first>x.first){
                    ans+=x.first;
                    l.pop();
                }else{
                    ans+=k.first;
                    r.pop();
                }
                v++;
            }else if(l.size()==c){
                r.push({a[j],j});
                j--;
            }else if(r.size()==c){
                l.push({a[i],i});
                i++;
            }else{
                l.push({a[i],i});
                if(i!=j)
                    r.push({a[j],j});
                i++,j--;
            }
            cout<<ans<<" ";
        }
        while(v<z){
            if(l.size()>0 && r.size()>0){
                auto k=r.top();
                auto x=l.top();
                if(x.first==k.first){
                    if(x.second<k.second){
                        ans+=x.first;
                        l.pop();
                    }else{
                        ans+=k.first;
                        r.pop();
                    }
                }else if(k.first>x.first){
                    ans+=x.first;
                    l.pop();
                }else{
                    ans+=k.first;
                    r.pop();
                }
            }else if(l.size()>0){
                ans+=l.top().first;
                l.pop();
            }else{
                ans+=r.top().first;
                r.pop();
            }
            //cout<<ans<<" ";
            v++;
        }
        return ans;
    }
};