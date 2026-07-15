class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num2) {
        stack<int>st;
        for(int i=num2.size()-1;i>=0;i--){
            while(!st.empty() && num2[i]>=st.top()){
                st.pop();
            }
            st.push(num2[i]);
        }
        for(int i=num2.size()-1;i>=0;i--){
            int z=num2[i];
            if(!st.empty() && num2[i]>=st.top()){
                 while(!st.empty() && num2[i]>=st.top()){
                    st.pop();
                }
                if(st.empty()){
                    num2[i]=-1;
                }
                else{
                    num2[i]=st.top();
                }
            }
            else{
                num2[i]=st.top();
            }
            st.push(z);
        }
    return num2;
    }
};