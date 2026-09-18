// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int firstversion=1,lastversion=n;
        //to know if the version is bad or not call isBadVersion(version) if true then that version is bad
        int answer=-1;
        while(firstversion<=lastversion){
            int version=firstversion+(lastversion-firstversion)/2;

            if(isBadVersion(version)){
                answer=version;
                lastversion=version-1;
            }
            else{
                firstversion=version+1;
            }
        }
        return answer;
    }
};