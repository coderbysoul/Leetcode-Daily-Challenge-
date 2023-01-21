//https://leetcode.com/problems/restore-ip-addresses/description/

class Solution {
public:
    bool allZeroes(string s){
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]!='0') return false;
        }

        return true;
    }
    bool isValid(string s){
        if(s.size()<=0) return false;
        if(s.size()==1){
            return true;
        }

        if(allZeroes(s) and s.size()>1) return false;

        if(s[0]=='0') return false;
        
        if(stoll(s)>255) return false;


        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        set<string> ans;
        int n = s.size();

        for(int i=0 ; i<n ; i++){
            for(int j=i+1;  j<n ; j++){
                for(int k = j+1 ; k<n ; k++ ){
                        string curr = s.substr(0 , i+1) + "." + s.substr(i+1 , j-i) + "."
                                       + s.substr(j+1 , k-j) + "." + 
                                       s.substr(k+1);
                        if(
                            isValid(s.substr(0 , i+1)) and isValid(s.substr(i+1 , j-i)) 
                        and isValid(s.substr(j+1 , k-j)) and isValid(s.substr(k+1))
                        ){
                            ans.insert(curr);
                        }
                }
            }
        }

        return vector(ans.begin() , ans.end());
    }
};