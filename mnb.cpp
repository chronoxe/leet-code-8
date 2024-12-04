/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.
*/
#include <iostream>
using namespace std;

int myAtoi(string s) 
{
    long long num = 0;
    int sign = 1;
    bool flag = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (isdigit(ch)) 
        {
            flag = 1;
            if ((sign == 1) && (INT_MAX < num * 10 + ch - '0')) 
            {
                return INT_MAX;
            }
            else if ((sign == -1) && (-1 * num * 10 - ch + '0' < INT_MIN)) 
            {
                return INT_MIN;
            }
            num = num * 10 + ch - '0';
        }
        else if (!flag) 
        {
            if (ch == ' ') continue;
            flag = 1;
            if (ch == '-')
            sign = -1;
            else if (ch == '+')
            continue;
            else if (ch != ' ')
            break;
        }
        else break;
    }
        num = num * sign;
        return int(num);
}

int main()
{
    string s1 = "42";
    string s2 = " - 042";
    string s3 = "1337c0d3";
    string s4 = "0-1";
    string s5 = "words and 987";
    cout << myAtoi(s1) << "\n" << myAtoi(s2) << "\n" << myAtoi(s3) << "\n" << myAtoi(s4) << "\n" << myAtoi(s5);

	return 0;
}