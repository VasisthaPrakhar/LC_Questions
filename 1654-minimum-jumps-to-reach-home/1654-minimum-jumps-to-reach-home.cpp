class Solution {
public:
    int minimumJumps(vector<int>& fo, int a, int b, int x) {
        unordered_set<int>s(fo.begin(),fo.end());
        int k=2000+a+b;
        set<pair<int,int>>st;
        int ans=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        st.insert({0,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node.first==x){
                    return ans;
                }
                if(!s.count(node.first-b) && node.first-b>=0 && node.second && !st.count({0,node.first-b})){
                    q.push({node.first-b,0});
                    st.insert({0,node.first-b});
                }
                if(!s.count(node.first+a) && node.first+a<=k && !st.count({1,node.first+a})){
                    q.push({node.first+a,1});
                    st.insert({1,node.first+a});
                }
            }
            ans++;
        }
        return -1;
    }
};