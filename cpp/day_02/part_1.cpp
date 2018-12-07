#include <gsl/gsl>
#include <iomanip>
#include <iostream>
#include <string>

int main(int /* unused */, char ** /* unused */) {
    std::string input;

    int64_t doubles = 0, triples = 0;
    while (true) {
        std::cin >> input;
        if (!std::cin) {
            break;
        }

        std::clog << "Read " << std::quoted(input) << " from input" << std::endl;

        char counts[26] = {};
        for (const auto &c : input) {
            gsl::at(counts, c - 'a') += 1;
        }

        bool got_two = false, got_three = false;
        for (char count : counts) {
            switch (count) {
            case 2: {
                if (!got_two) {
                    doubles += 1;
                    got_two = true;
                }
            } break;
            case 3: {
                if (!got_three) {
                    triples += 1;
                    got_three = true;
                }
            } break;
            default:
                break;
            }
        }
    }

    std::cout << "The hash is: " << doubles * triples << std::endl;
}
