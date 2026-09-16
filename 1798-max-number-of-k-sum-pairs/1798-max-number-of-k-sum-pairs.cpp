class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<n;i++){
            if(nums[i]>k) continue;
            um[nums[i]]++;
        }
        int answer=0;
        while(!um.empty()){
            auto it=um.begin();
            int num1=it->first,times1=it->second;

            if((double)num1==(double)k/2){
                answer+=times1/2;
                um.erase(num1);
                continue;
            }

            if(um.find(k-num1)==um.end()){
                um.erase(num1);
                continue;
            }

            int times2=um[k-num1];
            answer+=min(times1,times2);
            um.erase(num1);
            um.erase(k-num1);
        }
        return answer;
    }
};