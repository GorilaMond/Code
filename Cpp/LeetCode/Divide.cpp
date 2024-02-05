#include <limits.h>
namespace tmp
{
    unsigned dividend;
    unsigned res;
}
class Solution
{
protected:
    void divid(unsigned divisor, unsigned time)
    {
        if (divisor && tmp::dividend >= divisor)
        {
            tmp::dividend -= divisor;
            tmp::res += time;
            divid(divisor << 1, time << 1);
            if (tmp::dividend >= divisor)
            {
                tmp::dividend -= divisor;
                tmp::res += time;
            }
        }
    }

public:
    int divide(int dividend, int divisor)
    {
        bool s = (dividend < 0 ? true : false) ^ (divisor < 0 ? true : false);
        tmp::dividend = dividend < 0 ? -dividend : dividend;
        tmp::res = 0;
        divid(divisor < 0 ? -divisor : divisor, 1);
        if (tmp::res > INT_MAX)
            return s ? INT_MIN : INT_MAX;
        else
            return s ? -tmp::res : tmp::res;
    }
};

int main(void)
{
    Solution a;
    a.divide(-2147483648, -2147483648);
}