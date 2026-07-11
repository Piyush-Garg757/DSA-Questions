/*Angle Between Hands of a Clock

Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
Answers within 10-5 of the actual value will be accepted as correct.

Example 1:
Input: hour = 12, minutes = 30
Output: 165

Example 2:
Input: hour = 3, minutes = 30
Output: 75

Example 3:
Input: hour = 3, minutes = 15
Output: 7.5*/

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double a1 = (hour % 12) * 30 + minutes / 2.0;
        double a2 = 6 * minutes;
        double angle = max(a1, a2) - min(a1, a2);
        return min(angle, 360 - angle);
    }
};
// TC - O(1)  SC - O(1)