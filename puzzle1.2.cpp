#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>

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


        for(int i = 0; i < wrDigits.size(); i++){
            if(line.find(wrDigits[i]) != std::string::npos){
                wrNumbers.push_back(std::make_pair(line.find(wrDigits[i]), i + 1));
            }
        }

        for(char c : line){
            if(isdigit(c)){
                numbers.push_back(std::make_pair(line.find(c), c - '0'));
            }
        }

        // Sort the vector
        std::sort(wrNumbers.begin(), wrNumbers.end());
        std::sort(numbers.begin(), numbers.end());


        // gets the smallest and largest indexes of both vectors
        int smallestIndex = std::min(wrNumbers[0].first, numbers[0].first);
        int largestIndex = std::max(wrNumbers[wrNumbers.size() - 1].first, numbers[numbers.size() - 1].first);

        int smallestNumber, largestNumber;

        for (const auto& pair : wrNumbers) {
            if (pair.first == smallestIndex) {
                smallestNumber = pair.second;
            }
            if (pair.first == largestIndex) {
                printf("Entrou:\n");
                largestNumber = pair.second;
                printf("Entrou: %d\n", largestNumber);
            }
        }

        // Iterate over numbers to find the corresponding number for smallestIndex and largestIndex
        for (const auto& pair : numbers) {
            if (pair.first == smallestIndex) {
                smallestNumber = pair.second;
            }
            if (pair.first == largestIndex) {
                largestNumber = pair.second;
            }
        }

            //printf("Smallest number: %d\n", smallestNumber);
            //printf("Largest number: %d\n", largestNumber);

            result += smallestNumber * 10 + largestNumber;
            
        }

    std::cout << result << std::endl;
    return 0;
}