class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double>a;
        for(int i=0;i<n;i++){
            a.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(a.begin(),a.end());
        int ans=0,k=0,f=1;
        for(auto x:a){
            if(x-k<=0 && f==0){
                break;
            }
            ans++;
            f=0;
            k++;
            //cout<<x<<" ";
        }
        return ans;
    }
};