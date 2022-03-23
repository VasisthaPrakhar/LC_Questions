class Solution {
public:
    int dr[4] = {1, 0, -1, 0}; 
    int dc[4] = {0, 1, 0, -1}; 
    bool isRobotBounded(string ins) {
        int dir=0,x=0,y=0;        
        for(int i=0;i<ins.size();i++){
            if(ins[i]=='L'){
                dir=(dir+1)%4;
            }
            else if(ins[i]=='R'){
                dir=(4+dir-1)%4;
            }else{
                x+=dr[dir];
                y+=dc[dir];
            }
        }
        if((x==0 && y==0) || dir!=0){
            return true;
        }
        return false;
    }
};