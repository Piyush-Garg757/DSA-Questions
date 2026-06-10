/*Traffic Signal Color

You are given an integer timer representing the remaining time (in seconds) on a traffic signal.
The signal follows these rules:
If timer == 0, the signal is "Green"
If timer == 30, the signal is "Orange"
If 30 < timer <= 90, the signal is "Red"
Return the current state of the signal. If none of the above conditions are met, return "Invalid".

Example 1:
Input: timer = 60
Output: "Red"

Example 2:
Input: timer = 5
Output: "Invalid"*/

class Solution
{
public:
    string trafficSignal(int timer)
    {
        if (timer == 0)
            return "Green";
        if (timer == 30)
            return "Orange";
        if (timer > 30 && timer <= 90)
            return "Red";
        return "Invalid";
    }
};
// TC - O(1)  SC - O(1)