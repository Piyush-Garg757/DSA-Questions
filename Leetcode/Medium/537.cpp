/*Complex Number Multiplication
A complex number can be represented as a string on the form "real+imaginaryi" where:
real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

Example 1:
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"

Example 2:
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
*/

// My first approach
class Solution
{
public:
    string complexNumberMultiply(string s1, string s2)
    {
        int a = 0, b = 0, c = 0, d = 0, p = -1;
        int ane = 0, bne = 0, cne = 0, dne = 0;
        for (int i = 0; i < s1.length() - 1; i++)
        {
            if (s1[i] == '+')
            {
                p = 0;
            }
            else if (s1[i] == '-')
            {

                if (i == 0)
                    ane = 1;
                else
                    bne = 1;
            }
            else if (p == -1)
            {
                a *= 10;
                a += s1[i] - '0';
            }
            else
            {
                b *= 10;
                b += s1[i] - '0';
            }
        }
        p = -1;
        for (int i = 0; i < s2.length() - 1; i++)
        {
            if (s2[i] == '+')
            {
                p = 0;
            }
            else if (s2[i] == '-')
            {
                if (i == 0)
                    cne = 1;
                else
                    dne = 1;
            }
            else if (p == -1)
            {
                c *= 10;
                c += s2[i] - '0';
            }
            else
            {
                d *= 10;
                d += s2[i] - '0';
            }
        }
        if (ane)
            a = -a;
        if (bne)
            b = -b;
        if (cne)
            c = -c;
        if (dne)
            d = -d;
        int r = a * c - b * d;
        int img = a * d + b * c;
        string s = "";
        s += to_string(r);
        s += '+';
        s += to_string(img);
        s += 'i';
        return s;
    }
};
// TC - O(n+m)  SC - O(1)
// But it is not easy to understand and we could have made function for parsing and inproved variable names for understanding easily

// SLightly better sol
class Solution
{
public:
    pair<int, int> parseComplex(string s)
    {
        int real = 0, imag = 0;
        bool realNegative = false, imagNegative = false;
        bool imaginaryPart = false;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '+')
            {
                imaginaryPart = true;
            }
            else if (s[i] == '-')
            {
                if (!imaginaryPart)
                    realNegative = true;
                else
                    imagNegative = true;
            }
            else if (!imaginaryPart)
            {
                real *= 10;
                real += s[i] - '0';
            }
            else
            {
                imag *= 10;
                imag += s[i] - '0';
            }
        }
        if (realNegative)
            real = -real;
        if (imagNegative)
            imag = -imag;
        return {real, imag};
    }
    string complexNumberMultiply(string s1, string s2)
    {
        pair<int, int> p1 = parseComplex(s1);
        pair<int, int> p2 = parseComplex(s2);
        int a = p1.first;
        int b = p1.second;
        int c = p2.first;
        int d = p2.second;
        int realPart = a * c - b * d;
        int imaginaryPart = a * d + b * c;
        return to_string(realPart) + "+" + to_string(imaginaryPart) + "i";
    }
};
// /TC - O(n+m)  SC - O(1)