class Solution
{
public:
    // You need to insert the given element at the given index.
    // After inserting the elements at index, elements
    // from index onward should be shifted one position ahead
    // You may assume that the array already has sizeOfArray - 1
    // elements.
    void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
    {
        // Your code here
        int prev = arr[index];
        for (int i = index + 1; i < sizeOfArray; i++)
        {
            int tmp = arr[i];
            arr[i] = prev;
            prev = tmp;
        }
        arr[index] = element;
    }
};