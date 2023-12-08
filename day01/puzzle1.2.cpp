#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <variant>

int main(){

    char c;
    int result = 0;
    std::vector<std::string> wrDigits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string line;
    std::vector<std::pair<int,int>> numbers;
    std::vector<std::pair<int, char>> wrNumbers;


    while(std::getline(std::cin, line)){

        numbers.clear();   // Clear the vector for the next line
        wrNumbers.clear(); // Clear the vector for the next line

        
        for (int i = 0; i < wrDigits.size(); ++i) {
            size_t found = line.find(wrDigits[i]);
            while (found != std::string::npos) {                    
                wrNumbers.push_back(std::make_pair(found, i + 1));
                found = line.find(wrDigits[i], found + 1);
            }
        }

        for (int i = 0; i < line.size(); ++i) {
            if (isdigit(line[i])) {
                numbers.push_back(std::make_pair(i, line[i] - '0'));
            }
        }

        // Combine the vectors of word and digit indices
        std::vector<std::pair<int, std::variant<int, std::string>>> allIndices;

        for (const auto& pair : wrNumbers) {
            allIndices.emplace_back(pair.first, pair.second);
        }

        for (const auto& pair : numbers) {
            allIndices.emplace_back(pair.first, pair.second);
        }

        // Sort the combined vector
        std::sort(allIndices.begin(), allIndices.end());

        // Find the smallest and largest indices
        int smallestIndex = allIndices[0].first;
        int largestIndex = allIndices[allIndices.size() - 1].first;

        // Find the corresponding numbers for the smallest and largest indices
        int smallestNumber = 0, largestNumber = 0;

        for (const auto& pair : allIndices) {
            if (pair.first == smallestIndex) {
                if (std::holds_alternative<int>(pair.second)) {
                    smallestNumber = std::get<int>(pair.second);
                }
            }
            if (pair.first == largestIndex) {
                if (std::holds_alternative<int>(pair.second)) {
                    largestNumber = std::get<int>(pair.second);
                }
            }
        }

        result += smallestNumber * 10 + largestNumber;
     
    }

    std::cout << result << std::endl;
    return 0;
}