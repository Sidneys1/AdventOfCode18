#include <iostream>
#include <string>
#include <iomanip>

int main(int, char **) {
    std::string input;

    long long doubles = 0, triples = 0;

    long long twos = 0, threes = 0;
    while (true) {
        std::cin >> input;
        if (!std::cin)
            break;

        std::clog << "Read " << std::quoted(input) << " from input" << std::endl;

        char counts[26] = {};
        for (const auto& c : input) {
            counts[c - 'a'] += 1;
        }

        bool got_two = false, got_three = false;
        for (char i = 0; i < 26; i++) {
            switch(counts[i]) {
                case 2: {
                    if (!got_two) {
                        twos += 1;
                        got_two = true;
                    }
                } break;
                case 3: { 
                    if (!got_three) {
                        threes += 1;
                        got_three = true;
                    }
                } break;
                default: break;
            }
        }
    }

    std::cout << "The hash is: " << twos * threes << std::endl;
}
