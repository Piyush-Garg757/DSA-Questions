/*Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0*/

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false;
        for (int i = 2; i * i < n; i++)
        {
            if (isprime[i])
            {
                for (int j = i * i; j < n; j += i)
                {
                    isprime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
            if (isprime[i])
                count++;
        return count;
    }
};
/*Intuition - Initially assume every number is prime.
2 3 4 5 6 7 8 9 10 ...
✓ ✓ ✓ ✓ ✓ ✓ ✓ ✓ ✓

Start from 2:
Remove all multiples:
4 6 8 10 12 ...

Then 3:
Remove
6 9 12 15 ...

Then 5:
Remove
10 15 20 ...
Continue till √n.

The numbers still marked true are primes.

Why start from i * i?
For i = 5
5 × 2 = 10
5 × 3 = 15
5 × 4 = 20
These have already been marked when processing 2, 3, and 4.
So the first new multiple is
5 × 5 = 25
Hence
for (int j = i * i; j <= n; j += i)

Complexity
Time: O(n log log n)
Space: O(n)
This is the standard and most efficient algorithm for generating all prime numbers from 1 to n.*/