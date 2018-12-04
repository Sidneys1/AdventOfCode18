#include <iostream>
#include <vector>
#include <set>

int main(int, char **) {
    std::vector<long long> inputs;
    while (true) {
        long long input;
        std::cin >> input;
        if (!std::cin)
            break;
        std::clog << "Read " << input << " from input" << std::endl;
        inputs.push_back(input);
    }
    long long sum = 0;

    std::set<long long> frequencies;

    while (true) {
        for (long long input : inputs) {
            if (!frequencies.insert(sum).second) {
                std::cout << "The first repeating frequency is: " << +sum << std::endl;
                return 0;
            }
            sum += input;
        }
    }
}
