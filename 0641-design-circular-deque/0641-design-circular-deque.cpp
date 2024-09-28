class MyCircularDeque {
private:
    struct Node{
        int val;
        Node *next;
        Node *prev;
        Node(int c){
            val=c;
            next=NULL;
            prev=NULL;
        }
    };
    Node *front,*rear;
    int n,t;
public:
    MyCircularDeque(int k) {
        n=k;
        t=k;
        front=NULL;
        rear=NULL;
    }
    
    bool insertFront(int value) {
        if(!isFull()){
            Node* temp=new Node(value);
            if(front!=nullptr){
                front->prev=temp;
                temp->next=front;
                front=temp;
            }else{
                front=temp;
                rear=temp;
            }
            n--;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull()){
            Node* temp=new Node(value);
            if(rear!=nullptr){
                rear->next=temp;
                temp->prev=rear;
                rear=temp;
            }else{
                front=temp;
                rear=temp;
            }
            n--;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!isEmpty()){
            Node *temp=front;
            if(rear==front){
                rear=rear->next;
            }
            front=front->next;
            if(front)
                front->prev=NULL;
            temp->next=NULL;
            delete(temp);
            n++;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!isEmpty()){
            Node *temp=rear;
            if(rear==front){
                front=front->prev;
            }
            rear=rear->prev;
            if(rear)
                rear->next=NULL;
            temp->prev=NULL;
            delete(temp);
            n++;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(!isEmpty() && front!=NULL)
            return front->val;
        return -1;
    }
    
    int getRear() {
        if(!isEmpty() && rear!=NULL)
            return rear->val;
        return -1;
    }
    
    bool isEmpty() {
        return n==t;
    }
    
    bool isFull() {
        return n==0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */