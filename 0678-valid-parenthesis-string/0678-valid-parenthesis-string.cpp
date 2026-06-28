class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size(),i=0;
        stack<char>st;
        while(i<n){
            if(s[i]!=')'){
                st.push(s[i]);
                i++;
                continue;
            }


            if(st.empty()) return false;
            int star=0;
            bool flag=false;
            while(!st.empty()){
                char ch=st.top();
                st.pop();
                if(ch=='*') star++;
                if(ch=='('){
                    flag=true;
                    break;
                }
            }

            if(!flag) star--;
            while(star>0){
                st.push('*');
                star--;
            }

            i++;
        }
        int star=0;
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            if(ch=='(' ){
                if(star==0) return false;
                star--;
            }
            else star++;
        }
        return true;
    }
};