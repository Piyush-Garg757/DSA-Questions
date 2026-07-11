/*Construct the Rectangle
A web developer needs to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
The area of the rectangular web page you designed must equal to the given target area.
The width W should not be larger than the length L, which means L >= W.
The difference between length L and width W should be as small as possible.
Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.

Example 1:
Input: area = 4
Output: [2,2]

Example 2:
Input: area = 37
Output: [37,1]

Example 3:
Input: area = 122122
Output: [427,286]*/

// My first approach  - optimal but not clean
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int i = 2, l = area, w = 1;
        while (i * i < area)
        {
            i++;
        }
        if (i * i == area)
            return {i, i};
        else if (i * i > area && i > 1)
        {
            while (area % i != 0)
                i--;
        }
        l = max(i, area / i);
        w = min(i, area / i);
        return {l, w};
    }
};
// TC - O(n^1/2)  SC - O(1)

// Slightly clean version
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int w = sqrt(area);
        while (area % w != 0)
            w--;
        int l = area / w;
        return {l, w};
    }
};
// TC - O(n^.5)  SC - O(1)