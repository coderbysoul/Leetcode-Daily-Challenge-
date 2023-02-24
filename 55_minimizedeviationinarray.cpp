class Solution {
public:
    int minimumDeviation(vector<int>& v) {
        priority_queue<int> maxpq;
        int m=INT_MAX,diff=INT_MAX;
        for(auto i:v){
            if(i%2!=0) i*=2;
            m=min(m,i);
            maxpq.push(i);
        }
        while(maxpq.top()%2==0){
            int mx=maxpq.top();
            maxpq.pop();
            diff=min(diff,mx-m);
            m=min(m,mx/2);
            maxpq.push(mx/2);
        }

        return min(diff,maxpq.top()-m);
    }
};