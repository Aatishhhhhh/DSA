class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return INT_MAX;
        if(dividend >= 0 && divisor >= 0) {
            long long count = 0;
            long long total_sum = 0;
            while(total_sum + divisor <= dividend) {
                count += 1;
                total_sum += divisor;
            }
            return count;
        }
        else if(dividend < 0 && divisor < 0) {
            long long tempdividend = -(long long)dividend;
            long long tempdivisor = -(long long)divisor;
            long long count = 0;
            long long total_sum = 0;
            while(total_sum + tempdivisor <= tempdividend) {
                count += 1;
                total_sum += tempdivisor;
            }
            if(count > INT_MAX)
                return INT_MAX;
            return count;
        }
        else if(divisor < 0 && dividend > 0) {
            long long tempdivisor = -(long long)divisor;
            long long count = 0;
            long long total_sum = 0;
            while(total_sum + tempdivisor <= dividend) {
                count += 1;
                total_sum += tempdivisor;
            }
            return -count;
        }
        else {
            long long tempdividend = -(long long)dividend;
            long long count = 0;
            long long total_sum = 0;
            while(total_sum + divisor <= tempdividend) {
                count += 1;
                total_sum += divisor;
            }
            return -count;
        }
    }
};