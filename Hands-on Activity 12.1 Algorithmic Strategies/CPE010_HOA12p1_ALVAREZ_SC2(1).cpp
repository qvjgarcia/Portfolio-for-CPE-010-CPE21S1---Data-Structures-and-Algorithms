//Alvarez and Garcia
#include <iostream>
#include <vector>

int countPaths(
    const std::vector<std::vector<int> >& matrix,
    int row, int col, int cost,
    int m, int n){
    if (row >= m || col >= n){
        return 0;
    }

    int remainingCost = cost - matrix[row][col];
    if (remainingCost < 0){
        return 0;
    }

    if (row == m - 1 && col == n - 1)
    {
        return (remainingCost == 0) ? 1 : 0;
    }

    int rightPaths = countPaths(
        matrix, row, col + 1, remainingCost, m, n);

    int downPaths = countPaths(
        matrix, row + 1, col, remainingCost, m, n);

    return rightPaths + downPaths;
}
int main(){
    std::vector<std::vector<int> > matrix = {
        {4, 7, 1, 6},{6, 7, 3, 9},
        {3, 8, 1, 2},{7, 1, 7, 3}
    };

    int m = 4;
    int n = 4;
    int cost = 25;

    int result = countPaths(matrix, 0, 0, cost, m, n);
    std::cout << "Target Cost: " << cost << '\n';
    std::cout << "Number of Paths: " << result << '\n';

    return 0;
}
