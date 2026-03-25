// escaped delimiter, T: O(nk), S: O(nk)

#include <vector>
#include <string>

class Codec {
    static constexpr char DELIM = '/';
    static constexpr char ESC = '\\';

public:
    std::string encode(std::vector<std::string>& strs) {
        std::string res;
        for (auto& s : strs) {
            for (char c : s) {
                if (c == ESC) { 
                    res += ESC;
                    res += ESC;
                } else if (c == DELIM) {
                    res += ESC;
                    res += DELIM;
                } else {
                    res += c;
                }
            }
            res += DELIM;
        }
        return res;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> res;
        std::string cur;
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (s[i] == ESC) {
                cur += s[++i]; // skip to next char
            } else if (s[i] == DELIM) {
                res.push_back(cur);
                cur.clear();
            } else {
                cur += s[i];
            }
        }
        return res;
    }
};

// length-prefix, prefix each string with its lengths and separator, T: O(nk), S: O(nk)

#include <vector>
#include <string>

class Codec {
    static constexpr char SEP = '#';

public:
    std::string encode(std::vector<std::string>& strs) {
        std::string res;
        for (auto& s : strs) {
            res += std::to_string(s.size());
            res += SEP;
            res += s;
        }
        return res;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> res;
        int i = 0;
        int n = static_cast<int>(s.size());
        while (i < n) {
            int j = i;
            while (s[j] != SEP) { ++j; }
            int len = std::stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};


// fixed-width binary with explicit big-endian encoding

#include <vector>
#include <string>
#include <string_view>
#include <cstdint>
#include <cstring>

class Codec {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string res;
        size_t total = 0;
        for (auto& s : strs) { total += 4 + s.size(); } // 4 bytes headers + content per string
        res.reserve(total);

        for (auto& s : strs) {
            uint32_t len = static_cast<uint32_t>(s.size()); // explicit big-endian
            res += static_cast<char>((len >> 24) & 0xFF);
            res += static_cast<char>((len >> 16) & 0xFF);
            res += static_cast<char>((len >> 8) & 0xFF);
            res += static_cast<char>((len >> 0) & 0xFF);
            res.append(s);
        }
        return res;
    }

    // string_view into buffer -zero heap allocation on decode
    std::vector<std::string_view> decodeView(std::string_view buf) {
        std::vector<std::string_view> res;
        size_t i = 0;
        while (i < buf.size()) {
            uint32_t len = (static_cast<uint8_t>(buf[i]) << 24)
                        | (static_cast<uint8_t>(buf[i + 1]) << 16)
                        | (static_cast<uint8_t>(buf[i + 2]) << 8)
                        | (static_cast<uint8_t>(buf[i + 3]) << 0);
            i += 4;
            res.push_back(buf.substr(i, len));
            i += len;
        }
        return res;
    }

    std::vector<std::string> decode(std::string s) {
        auto views = decodeView(s);
        return std::vector<std::string>(views.begin(), views.end());
    }
};

/*
   - cache behavior
   ? encoded buf recv in fragments over the network
   ? uint32_t over uint16_t
   ? string_view lifetime hazard
   ? vs protobuf
*/
