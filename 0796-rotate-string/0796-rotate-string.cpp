class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal){return true;}
        int n=s.length();
        for(int i=0;i<n-1;i++){
            string t1=s.substr(0,i+1);
            string t2=s.substr(i+1);
            //cout<<t1<<" "<<t2<<endl;
            if(t2+t1==goal){return true;}
        }
        return false;
    }
};