#include <iostream>

const int CANDIDATE_COUNT = 5; // number of candidates

int main()
{
    // array to store the names of the candidates
    std::string candidates[CANDIDATE_COUNT];

    // array to store the number of votes received by each candidate
    int votes[CANDIDATE_COUNT] = {0};

    // read the names and votes of the candidates from the user
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        std::cout << "Enter the name of candidate " << i + 1 << ": ";
        std::cin >> candidates[i];

        std::cout << "Enter the number of votes received by candidate " << i + 1 << ": ";
        std::cin >> votes[i];
    }

    // find the total number of votes
    int total_votes = 0;
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        total_votes += votes[i];
    }

    // print the names, votes, and percentages of the candidates
    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        // calculate the percentage of votes received by the candidate
        float percentage = 100.0f * votes[i] / total_votes;

        // print the name, votes, and percentage of the candidate
        std::cout << "\nCandidate " << "\t\tVotes received " << "\t\t% of Total Votes" << std::endl;
		std::cout << candidates[i] << "\t\t\t" << votes[i] << "\t\t\t" << percentage << std::endl;
    }

    // find the winner of the election
    int winner_index = 0;
    for (int i = 1; i < CANDIDATE_COUNT; i++)
    {
        if (votes[i] > votes[winner_index])
        {
            winner_index = i;
        }
    }

    // print the winner of the election
    std::cout << "The winner of the election is candidate " << candidates[winner_index] << "." << std::endl;

    return 0;
}
