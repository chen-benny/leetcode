class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();

        for (int i = 0; i < sz && n > 0; i++) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i-1] == 0) && (i == sz-1 || flowerbed[i+1] == 0)) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};

// follow-up: no-modifying
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        
        for (int i = 0; i < sz && n > 0; i++) {
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i-1] == 0) && (i == sz-1 || flowerbed[i+1] == 0)) {
                    n--;
                    i++; // skip == mark planted
                }
            }
        }
        return n == 0;
    }
};
