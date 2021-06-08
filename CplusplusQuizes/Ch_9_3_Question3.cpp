//Question 3
//Modify the following program so that instead of having maxScore hold the largest score directly,
//a variable named maxIndex holds the index of the largest score.

//#include <iostream>
//#include <iterator> // for std::size
//
//int main()
//{
//    constexpr int scores[]{ 84, 92, 76, 81, 56 };
//
//    int maxScore{ 0 }; // keep track of our largest score
//
//    // now look for a larger score
//    for (int student{ 0 }; student < std::size(scores); ++student)
//    {
//        if (scores[student] > maxScore)
//        {
//            maxScore = scores[student];
//        }
//    }
//
//    std::cout << "The best score was " << maxScore << '\n';
//
//    return 0;
//}

#include <iostream>
#include <iterator>

int Ch_9_3_Question3() {

	constexpr int scores[]{ 84,92,76,81,56 };

	int maxScoreIndex{ 0 };
	for (int student{ 0 }; student < std::size(scores); ++student) {
		if (scores[student] > scores[maxScoreIndex]) {
			maxScoreIndex = student;
		}
	}

	std::cout << "The best score was at " << maxScoreIndex << " index \n";

	return 0;
}