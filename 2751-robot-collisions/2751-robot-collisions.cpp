class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n=pos.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({pos[i],h[i],d[i]-'A'});
        }
        sort(v.begin(),v.end());
        stack<vector<int>>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()[2]=='R'-'A' && v[i][2]=='L'-'A'){
                int x=v[i][0],y=v[i][1],z=v[i][2],f=1;
                while(!st.empty() && st.top()[2]=='R'-'A' && z=='L'-'A'){
                    int y1=st.top()[1],z1=st.top()[2],x1=st.top()[0];
                    st.pop();
                    if(y1==y){
                        y=0,f=0;
                        break;
                    }else if(y1<y){
                        y--;
                    }else{
                        st.push({x1,y1-1,z1});
                        f=0;
                        break;
                    }
                }
                if((st.empty() && y>0) || (f && y>0)){
                    st.push({x,y,z});
                }
            }else{
                st.push({v[i][0],v[i][1],v[i][2]});
            }
        }
        unordered_map<int,int>mp;
        vector<int>ans;
        while(!st.empty()){
            mp[st.top()[0]]=st.top()[1];
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(mp.find(pos[i])!=mp.end()){
                ans.push_back(mp[pos[i]]);
            }
        }
        return ans;
    }
};