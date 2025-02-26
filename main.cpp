#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream questions, answers;
    std::string question, answer, playerAnswer;
    int playerPoints = 0, tvViewerPoints = 0, position = 0;
    std::vector <int> playedPos (13);

    questions.open("..\\questions.txt");
    answers.open("..\\answers.txt");

    if (!questions.is_open() || !answers.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    else
    {
        std::cout << "Welcome to the intellectual game 'What? Where? When?'." << std::endl;
        int counter = 1;

        while (playerPoints < 6 && tvViewerPoints < 6)
        {
            std::cout << std::endl;
            std::cout << "Please enter question number: ";
            std::cin >> position;
            if (position > 13 || position < 1 ) position = 1;
            while (std::find(playedPos.begin(), playedPos.end(), position) != playedPos.end())
            {
                ++position;
                if (position > 13 ) position = 1;
            }
            playedPos.push_back(position);

            while (counter != position)
            {
                ++counter;
                std::getline(questions, question);
                answers >> answer;
            }

            std::getline(questions, question);
            answers >> answer;
            std::cout << question << std::endl;
            std::cout << "Please enter your answer: ";
            std::cin >> playerAnswer;

            if (answer == playerAnswer)
            {
                std::cout << "Great, that's the correct answer." << std::endl;
                ++playerPoints;
                std::cout << "Score: players " << playerPoints << " , TV viewers " << tvViewerPoints
                                      << std::endl;
                question = "";
                answer = "";
            }
            else if (answer != playerAnswer)
            {
                std::cout << "Wrong answer, here is the correct one: " << answer << std::endl;
                ++tvViewerPoints;
                std::cout << "Score: players " << playerPoints << " , TV viewers " << tvViewerPoints
                                      << std::endl;
                question = "";
                answer = "";
            }
            questions.seekg(0);
            answers.seekg(0);
            counter = 1;

        }
    }

    std::cout << std::endl;
    std::cout << "Winner: ";
    (playerPoints == 6) ? std::cout << " players" : std::cout << "TV viwers";

    questions.close();
    answers.close();

    return 0;
}
