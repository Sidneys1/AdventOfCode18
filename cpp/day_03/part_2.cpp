#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>

using Claim = struct { int id, x, y, w, h; };

std::istream &operator>>(std::istream &stream, Claim &st) {
    // #1 @ 2,3: 4x5
    stream.ignore(1); // #
    stream >> st.id;  // 1
    stream.ignore(2); // @
    stream >> st.x;   // 2
    stream.ignore(1); // ,
    stream >> st.y;   // 3
    stream.ignore(2); // :
    stream >> st.w;   // 4
    stream.ignore(1); // x
    stream >> st.h;   // 5
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Claim &st) {
    return stream << '#' << st.id << " @ " << st.x << ',' << st.y << ": " << st.w << 'x' << st.h;
}

int main(int /* unused */, char ** /* unused */) {
    std::bitset<1'000'000> map1, map2;
    std::vector<Claim> claims;

    while (true) {
        std::string line;
        if (!std::getline(std::cin, line) || line.empty()) {
            break;
        }
        std::stringstream ss(line);
        Claim x{};
        ss >> x;
        std::clog << "Read: " << x << std::endl;
        claims.push_back(x);
    }

    for (const Claim &claim : claims) {
        std::clog << "Mapping " << claim << std::endl;
        for (int y = claim.y; y < claim.y + claim.h; y++) {
            int off = y * 1000;
            for (int x = claim.x; x < claim.x + claim.w; x++) {
                map2[off + x] = map1[off + x];
                map1[off + x] = true;
            }
        }
    }

    for (const Claim &claim : claims) {
        bool overlap = false;
        std::clog << "Checking " << claim << std::endl;
        for (int y = claim.y; y < claim.y + claim.h; y++) {
            int off = y * 1000;
            for (int x = claim.x; x < claim.x + claim.w; x++) {
                if (map2[off + x]) {
                    overlap = true;
                    break;
                }
            }
            if (overlap) {
                break;
            }
        }
        if (!overlap) {
            std::cout << "The only non-overlapping claim is " << claim.id << std::endl;
            return 0;
        }
    }
    return 0;
}