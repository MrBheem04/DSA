class MinStack {
    private Stack<Long> st = new Stack<>();
    private Long mini; 

    public MinStack() {
        
    }
    
    public void push(int value) {
        if(st.isEmpty()){
            mini = (long)value;

            st.push((long)value);
            return;
        }
        if(value > mini){
            st.push((long)value);
        }
        else{
            st.push(2L * value - mini);
            mini = (long)value;
        }
    }
    
    public void pop() {
        if(st.isEmpty())return;

        Long x = st.peek();
        st.pop();

        if(x < mini){
            mini = 2L * mini-x;
        }
    }
    
    public int top() {
        if(st.isEmpty())return -1;

        long x = st.peek();

        if(mini < x){
            return (int)x;
        }
        return mini.intValue();
    }
    
    public int getMin() {
        return mini.intValue();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */