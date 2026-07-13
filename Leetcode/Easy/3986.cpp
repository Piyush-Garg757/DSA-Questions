/*Number of Elapsed Seconds Between Two Times

You are given two valid times startTime and endTime, each represented as a string in the format "HH:MM:SS".
Return the number of seconds that have elapsed from startTime to endTime.

Example 1:
Input: startTime = "01:00:00", endTime = "01:00:25"
Output: 25
Explanation:
endTime is 25 seconds ahead of startTime.

Example 2:
Input: startTime = "12:34:56", endTime = "13:00:00"
Output: 1504
Explanation:
endTime is 25 minutes and 4 seconds ahead of startTime, which equals 1504 seconds.*/

class Solution
{
public:
    int convert(string s)
    {
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        int sec = stoi(s.substr(6, 2));
        return h * 3600 + m * 60 + sec;
    }
    int secondsBetweenTimes(string a, string b)
    {
        return convert(b) - convert(a);
    }
};
// TC - O(1)  SC - O(1)