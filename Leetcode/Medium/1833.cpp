/*Maximum Ice Cream Bars

It is a sweltering summer day, and a boy wants to buy some ice cream bars.
At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible.
Note: The boy can buy the ice cream bars in any order.
Return the maximum number of ice cream bars the boy can buy with coins coins.
You must solve the problem by counting sort.

Example 1:
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.

Example 2:
Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.

Example 3:
Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.*/

class Solution
{
public:
    int maxIceCream(vector<int> &a, int coins)
    {
        int n = a.size(), maxi = INT_MIN;
        for (int i = 0; i < n; i++)
            maxi = max(maxi, a[i]);
        vector<int> freq(maxi + 1);
        for (int i = 0; i < n; i++)
        {
            freq[a[i]]++;
        }
        int count = 0;
        for (int i = 0; i < maxi + 1; i++)
        {
            while (freq[i] != 0 && coins - i >= 0)
            {
                count++;
                coins -= i;
                freq[i]--;
            }
        }
        return count;
    }
};
// TC - O(n+m)  SC - O(maxi+1)

/*Max Ice Cream Bars wale question mein jo solution tumne likha tha, woh Counting Sort ki idea par based hai.
Normal Counting Sort mein:
arr = [10,6,8,7,7,8]
freq[6] = 1
freq[7] = 2
freq[8] = 2
freq[10] = 1
Phir sorted array reconstruct karte hain:
[6,7,7,8,8,10]
Max Ice Cream mein kya hua?
Tumne sorted array banaya hi nahi.
Bas frequency count ki:
freq[cost]++;
Aur phir cheapest cost se iterate kiya:
for(int cost = 1; cost <= maxi; cost++)
Yaani effectively tum sorted order mein elements visit kar rahe ho:
6 -> 1 bar
7 -> 2 bar
8 -> 2 bar
10 -> 1 bar
Jo exactly sorted array
[6,7,7,8,8,10]
ko traverse karne ke equivalent hai.
Isliye ise Counting Sort Approach bolte hain
Normal approach:
sort(costs.begin(), costs.end());  // O(n log n)
Counting Sort approach:
freq[cost]++;
and then
for(cost = 1; cost <= maxCost; cost++)
Time:
O(n + maxCost)
instead of
O(n log n)
Ye tab bahut useful hota hai jab values ki range chhoti ho (jaise is problem mein cost <= 10^5).
Interview point: Counting Sort ka matlab hamesha sorted array banana nahi hota. Kai questions mein sirf frequency array use karke sorted order simulate karna hi Counting Sort technique kehlata hai.*/