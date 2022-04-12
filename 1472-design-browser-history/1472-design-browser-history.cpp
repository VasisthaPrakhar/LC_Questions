class BrowserHistory {
    private:
    stack<string>front,bac;
    string curr;
public:
    BrowserHistory(string hp) {
        curr=hp;
        while(!bac.empty()){
            bac.pop();
        }
        while(!front.empty()){
            front.pop();
        }
    }
    
    void visit(string url) {
        bac.push(curr);
        curr=url;
        while(!front.empty()){
            front.pop();
        }
    }
    
    string back(int steps) {
        while(!bac.empty() && steps--){
            front.push(curr);
            curr=bac.top();
            bac.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
         while(!front.empty() && steps--){
            bac.push(curr);
            curr=front.top();
            front.pop();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */