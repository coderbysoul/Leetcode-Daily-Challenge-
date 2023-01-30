//https://leetcode.com/problems/n-th-tribonacci-number/description/

class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1,sum=0;
        if(n==1)
        return 1;
        if(n==2)
        return 1;
        for(int i=3;i<=n;i++)
        {
            sum=a+b+c;
            a=b;
            b=c;
            c=sum;
        }
        return sum;
    }
};