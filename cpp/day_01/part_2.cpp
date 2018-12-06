#include <iostream>
#include <set>
#include <vector>

int main(int /* unused */, char ** /* unused */) {
    std::vector<int64_t> inputs;
    while (true) {
        int64_t input;
        std::cin >> input;
        if (!std::cin) {
            break;
        }
        std::clog << "Read " << input << " from input" << std::endl;
        inputs.push_back(input);
    }
    int64_t sum = 0;

    std::set<int64_t> frequencies;

    while (true) {
        for (int64_t input : inputs) {
            if (!frequencies.insert(sum).second) {
                std::cout << "The first repeating frequency is: " << +sum << std::endl;
                return 0;
            }
            sum += input;
        }
    }
}
