class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),answer=0,i=0,j=n-1;
        while(i<=j){
            int area=min(height[i],height[j])*(j-i);
            answer=max(answer,area);
            if(height[i]<=height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return answer;
    }
};