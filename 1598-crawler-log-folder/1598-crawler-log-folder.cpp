class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>s;
        s.push(0);
        int idx=1;
        for(auto &x:logs){
            if(x[1]=='/' && x[0]=='.'){continue;}
            if(x[0]=='.' && x[1]=='.'){
                if(s.top()!=0){
                    s.pop();
                    idx--;
                }
            }else{
                s.push(idx++);
            }
        }
        return s.top();
    }
};