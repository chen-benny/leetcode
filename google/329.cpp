// dfs + memo, T: O(mn), S: O(mn)

#include <vector>
#include <algorithm>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
        int best = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                best = std::max(best, dfs(matrix, memo, r, c, m, n));
            }
        }
        return best;
    }

private:
    int dfs(std::vector<std::vector<int>>& matrix,
            std::vector<std::vector<int>>& memo,
            int r, int c, int m, int n) {
        if (memo[r][c]) { return memo[r][c]; }

        constexpr int DR[] = {-1, 1, 0, 0};
        constexpr int DC[] = {0, 0, -1, 1};
        int best = 1;

        for (int d = 0; d < 4; ++d) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) { continue; }
            if (matrix[nr][nc] <= matrix[r][c]) { continue; }
            best = std::max(best, 1 + dfs(matrix, memo, nr, nc, m, n));
        }
        return memo[r][c] = best;
    }
};
