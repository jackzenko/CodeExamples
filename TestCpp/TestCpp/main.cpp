#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <mutex>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iterator>
#include <list>
#include <array>
#include <ctime>
#include <utility>
#include <sstream>
#include <functional>
#include <numeric>
using namespace std;

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int size) : root(size), rank(size) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        while (root[x] != x) {
            root[x] = root[root[x]];
            x = root[x];
        }
        return root[x];
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        }
        else {
            root[rootY] = rootX;
            rank[rootX] += 1;
        }
        return true;
    }
};

// Test Case
int main() {


    return 0;
}

// vector<vector<int>> nums{{22, 22}, {22, 22}, {22, 22}};
// vector<int> nums{ 22, 22, 22, 22, 22};