#include <gsl/gsl>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main(int /* unused */, char ** /* unsued */) {
    std::vector<std::string> inputs;
    while (true) {
        std::string input;
        std::cin >> input;
        if (!std::cin) {
            break;
        }
        std::clog << "Read " << std::quoted(input) << " from input" << std::endl;
        inputs.push_back(input);
    }

    for (auto input = inputs.begin(); input <= inputs.end(); input++) {
        for (auto compare = std::vector<std::string>::iterator(input + 1); compare <= inputs.end(); compare++) {
            size_t dpos = std::string::npos;
            std::clog << "Comparing " << std::quoted(*input) << " with " << std::quoted(*compare) << std::endl;
            for (size_t i = 0; i < compare->size(); i++) {
                if (gsl::at(*input, i) != gsl::at(*compare, i)) {
                    std::clog << "Found difference at " << i << " (" << gsl::at(*input, i) << ')' << std::endl;
                    if (dpos != std::string::npos) {
                        dpos = std::string::npos;
                        break;
                    }
                    dpos = i;
                }
            }
            if (dpos != std::string::npos) {
                std::cout << std::quoted(*input) << std::endl
                          << std::quoted(*compare) << std::endl
                          << std::string(dpos + 1, ' ') << '^' << std::endl;
                std::cout << std::quoted(input->erase(dpos, 1)) << std::endl;
                return 0;
            }
        }
    }
}
