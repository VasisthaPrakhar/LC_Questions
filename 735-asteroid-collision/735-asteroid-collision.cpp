class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        stack<int>s;
        s.push(a[0]);
        for(int i=1;i<n;i++){
            int f=1;
            while(!s.empty() && (a[i]<0 && s.top()>0)){
                if(s.top()>=-a[i]){
                    if(s.top()==-a[i]){
                        f=0;
                        s.pop();
                        break;
                    }
                    f=0;
                    break;
                }
                s.pop();
            }
            if(f){
                s.push(a[i]);
            }
        }
        vector<int>ans(s.size());
        for(int i=s.size()-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};