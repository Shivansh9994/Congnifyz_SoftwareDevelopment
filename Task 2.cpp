#include <iostream>
#include <vector>

// Function to generate the Bell Triangle
void generateBellTriangle(int n) {
    // Create a 2D vector to store the Bell Triangle
    std::vector<std::vector<int>> bellTriangle(n, std::vector<int>(n, 0));

    // Initialize the first element
    bellTriangle[0][0] = 1;

    // Generate the Bell Triangle
    for (int i = 1; i < n; ++i) {
        // First element of the current row is the last element of the previous row
        bellTriangle[i][0] = bellTriangle[i-1][i-1];

        // Fill the rest of the row
        for (int j = 1; j <= i; ++j) {
            bellTriangle[i][j] = bellTriangle[i-1][j-1] + bellTriangle[i][j-1];
        }
    }

    // Print the Bell Triangle
    std::cout << "Bell Triangle up to row " << n << " is:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << bellTriangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows for the Bell Triangle: ";
    std::cin >> n;

    generateBellTriangle(n);

    return 0;
}
