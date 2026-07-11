/*Sort an Array*/

class Solution
{
public:
    int partition(vector<int> &a, int low, int high)
    {
        int pivot_idx = low + rand() % (high - low + 1);
        swap(a[low], a[pivot_idx]);
        int pivot = a[low];
        int i = low + 1, j = high;
        while (true)
        {
            while (i <= high && a[i] <= pivot)
                i++;
            while (j >= low && a[j] > pivot)
                j--;
            if (i >= j)
                break;
            swap(a[i], a[j]);
        }
        swap(a[low], a[j]);
        return j;
    }
    void quicksort(vector<int> &a, int low, int high)
    {
        if (low >= high)
            return;
        int idx = partition(a, low, high);
        quicksort(a, low, idx - 1);
        quicksort(a, idx + 1, high);
    }
    vector<int> sortArray(vector<int> &a)
    {
        int n = a.size();
        quicksort(a, 0, n - 1);
        return a;
    }
};
// TC - O(nlogn)  SC - O(1)