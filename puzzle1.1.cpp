#include <iostream>
#include <vector>

int main(){

    std::vector<int> numbers;
    char c;
    int result = 0;

    while ((c = getchar()) != EOF){

       std::vector<int> numbers;

        // Read characters until the end of the line
        while (c != '\n' && c != EOF) {
            if (isdigit(c)) {
                numbers.push_back(c - '0');
            }
            c = getchar();
        }

        // Process the digits if there are any
        if (!numbers.empty()) {
            int first = numbers[0];
            int last = numbers[numbers.size() - 1];
            int lineNumber = first * 10 + last;
            result += lineNumber;
        }
    }
    std::cout << result << std::endl;
    return 0;
}