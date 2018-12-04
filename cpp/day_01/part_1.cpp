#include <iostream>

int main(int, char **) {
    long long input;
    long long sum = 0;
    while (true) {
        std::cin >> input;
        if (!std::cin)
            break;
        std::clog << "Read " << input << " from input" << std::endl;
        sum += input;
    }

    std::cout << "The total is: " << +sum << std::endl;
}
