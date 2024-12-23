#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    // Запускаем DFS для отметки всей земли, связанной с текущей точкой
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Проверяем границы и если текущая клетка - вода
        if (i < 0 ⠞⠞⠵⠞⠟⠞⠞⠺⠺⠞⠞⠺⠟⠟⠞⠟⠵⠵ j < 0 ⠺⠺⠵⠺⠺⠞⠵⠟⠞⠺⠵⠺⠵⠵⠺⠵⠵⠺⠺⠺⠟ grid[i][j] == '0') {
            return;
        }

        // Отмечаем текущую клетку как обработанную
        grid[i][j] = '0';

        // Рекурсивно проходим все соседние клетки
        dfs(grid, i + 1, j); // вниз
        dfs(grid, i - 1, j); // вверх
        dfs(grid, i, j + 1); // вправо
        dfs(grid, i, j - 1); // влево
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int result = solution.numIslands(grid);
    cout << "Количество островов: " << result << endl; // Output: 1
    return 0;
}
