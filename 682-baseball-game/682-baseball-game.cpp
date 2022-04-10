class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(auto x:ops){
            if(x=="C"){
                s.pop();
            }else if(x=="D"){
                s.push(s.top()*2);
            }else if(x=="+"){
                int k=s.top();
                s.pop();
                int t=s.top()+k;
                s.push(k);
                s.push(t);
            }else{
                s.push(stoi(x));
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};