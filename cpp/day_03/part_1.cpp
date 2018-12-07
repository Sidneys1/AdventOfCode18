#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>

using Claim = struct { int id, x, y, w, h; };

std::istream &operator>>(std::istream &stream, Claim &st) {
    // #1 @ 1,3: 4x4
    stream.ignore(1);
    stream >> st.id;
    stream.ignore(2);
    stream >> st.x;
    stream.ignore(1);
    stream >> st.y;
    stream.ignore(2);
    stream >> st.w;
    stream.ignore(1);
    return stream >> st.h;
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
                // std::clog << "Writing 1 to " << x << ',' << y << std::endl;
                map2[off + x] = map1[off + x];
                map1[off + x] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 1'000'000; i++) {
        if (map2[i]) {
            count++;
        }
    }
    std::cout << "There are " << count << " square inches claimed by at least two elfs." << std::endl;
    return 0;
}