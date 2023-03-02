//https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = (int) chars.size(); // get the size of chars
        int pointer = 0; // to keep track of the index you should update

        for (int i = 0; i < n; ++i) {
            int j = i + 1;

            // get the first index that differ from chars[i]
            while(j < n and chars[j] == chars[i]) j++;

            // convert it to string to store the length as consecutive characters
            string str = to_string((int) j - i);

            // if there's just one character just put it and move the pointer
            if(str == "1") chars[pointer++] = chars[i];

            else { // if it has length more than one put the character then add the length
                chars[pointer++] = chars[i];
                for(auto & it : str) chars[pointer++] = it;
            }
            i = j - 1; // update the index to the last index that differ from chars[i]
        }

        return pointer; // return the pointer which is the size of the compressed string
    }
};