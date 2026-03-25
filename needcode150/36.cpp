// hash-set, set per row/col/box, T: O(1), S: O(1)

#include <vector>
#include <unordered_set>
#include <string>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        constexpr int SIZE = 9;
        std::unordered_set<std::string> seen;

        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (board[r][c] == '.') { continue; }
                char d = board[r][c];
                int box = (r / 3 ) * 3 + (c / 3);

                if (!seen.insert("r" + std::to_string(r) + d).second) { return false; }
                if (!seen.insert("c" + std::to_string(c) + d).second) { return false; }
                if (!seen.insert("b" + std::to_string(box) + d).second) { return false; }
            }
        }
        return true;
    }
};

// flat-array, encode seen digits as bitmasks, T: O(1), S: O(1) stack-allocated

#include <vector>
#include <cstring>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        constexpr int SIZE = 9;
        constexpr int BOXES = 9;

        int rows[SIZE];
        int cols[SIZE];
        int boxes[SIZE];
        std::memset(rows, 0, sizeof(rows));
        std::memset(cols, 0, sizeof(cols));
        std::memset(boxes, 0, sizeof(boxes));

        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (board[r][c] == '.') { continue; }

                int digits = board[r][c] - '1'; // 0-indexed
                int mask = 1 << digits;
                int box = (r / 3) * 3 + (c / 3);

                if (rows[r] & mask) { return false; }
                if (cols[c] & mask) { return false; }
                if (boxes[box] & mask) { return false; }

                rows[r] |= mask;
                cols[c] |= mask;
                boxes[box] |= mask;
            }
        }
        return true;
    }
};

/*
   - cache behavior
   - bistmask operations
   ? why digits = board[r][c] - '1'
   ? validate and solve sudoku
*/
