class Solution {
public:

     double fun(double x, long long n) {

        // Base case
        if (n == 0) return 1;

        double ans = fun(x, n / 2);

        // Even
        if (n % 2 == 0)
            return ans * ans;

        // Odd
        return ans * ans * x;
    }

    double myPow(double x, long long n) {

        if(n<0){
           x = 1 / x;
           n = -n;
        }

       return fun(x,n);
    }
};