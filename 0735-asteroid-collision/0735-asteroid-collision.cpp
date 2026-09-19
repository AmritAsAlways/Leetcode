class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        deque<int>st;
        for(int i=0;i<n;i++){
            if(st.empty() || (asteroids[i]>0 && st.back()>0) || (asteroids[i]<0 && st.back()<0) || asteroids[i]>0){
                st.push_back(asteroids[i]);
                continue;
            }
            int x=asteroids[i];
            while(!st.empty()){
                int topmost=st.back();
                if(topmost<0 && x>0) break;
                if(topmost>0 && x>0) break;
                if(topmost<0 && x<0) break;
                st.pop_back();

                cout<<topmost<<" "<<x<<endl;

                if(abs(topmost)>abs(x)) x=topmost;
                else if(abs(topmost)==abs(x)){
                    x=0;
                    break;
                }
            }
            if(x!=0) st.push_back(x);
        }
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.front());
            st.pop_front();
        }
        return v;
    }
};