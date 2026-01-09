

int smallestIndex(const int arr[], int size)
{
    if (size == 0) return -1; // return -1 if the array is empty

    int min_index = 0; // keep track of the index of the smallest element
    int min_value = arr[0]; // keep track of the smallest element

    // loop through the array, starting from the second element
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min_value)
        {
            // update the minimum value and index if a smaller element is found
            min_value = arr[i];
            min_index = i;
        }
    }

    return min_index; // return the index of the smallest element
}
