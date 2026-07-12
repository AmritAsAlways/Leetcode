class Solution {
public:
    string intToRoman(int num) {
        string s=to_string(num);
        string ans="";
        int i=0,n=s.size();
        while(i<n){
            //place in digits
            int place=n-i;
            if(place==4){
                int times=s[i]-'0';
                while(times>0){
                    ans+='M';
                    times--;
                }
            }
            else if(place==3){
                int times=s[i]-'0';
                if(times==4) ans+="CD";
                else if(times==9) ans+="CM";
                else if(times<4){
                    while(times>0){
                        ans+="C";
                        times--;
                    }
                }
                else{
                    ans+="D";
                    while(times>5){
                        ans+="C";
                        times--;
                    }
                }
            }
            else if(place==2){
                int times=s[i]-'0';
                if(times==4) ans+="XL";
                else if(times==9) ans+="XC";
                else if(times<4){
                    while(times>0){
                        ans+="X";
                        times--;
                    }
                }
                else{
                    ans+="L";
                    while(times>5){
                        ans+="X";
                        times--;
                    }
                }
            }
            else if(place==1){
                int times=s[i]-'0';
                if(times==4) ans+="IV";
                else if(times==9) ans+="IX";
                else if(times<4){
                    while(times>0){
                        ans+="I";
                        times--;
                    }
                }
                else{
                    ans+="V";
                    while(times>5){
                        ans+="I";
                        times--;
                    }
                }
            }
            i++;
        }
        return ans;
    }
};