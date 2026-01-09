#include "stack.h"

int main()
{
    const char* input = "This is DSA exam";
    char* output = reverse_string(input);
    cout << "Input string: " << input << endl;
    cout << "Output string: " << output << endl;
    delete[] output;
    return 0;
}