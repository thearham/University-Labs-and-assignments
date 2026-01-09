#include <fstream>
#include <iostream>

const int RANGE_COUNT = 8; // number of score ranges
const int RANGES[RANGE_COUNT] = {0, 25, 50, 75, 100, 125, 150, 175}; // score ranges

int main()
{
    // create an input file stream and open the file
    std::ifstream infile("scores.txt");

    // check if the file was opened successfully
    if (!infile)
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // array to keep track of the number of students in each score range
    int counts[RANGE_COUNT] = {0};

    // read the scores from the file and update the counts
    int score;
    while (infile >> score)
    {
        // find the score range the score belongs to
        int i;
        for (i = 0; i < RANGE_COUNT - 1; i++)
        {
            if (score <= RANGES[i + 1]) break;
        }

        // increment the count for the score range
        counts[i]++;
    }

    // print the score ranges and the number of students in each range
    for (int i = 0; i < RANGE_COUNT; i++)
    {
        // print the score range
        std::cout << RANGES[i] << "-" << RANGES[i + 1] << ": ";

        // print the number of students in the score range
        std::cout << counts[i] << std::endl;
    }

    return 0;
}
