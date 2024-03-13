#include <iostream>
#include <vector>
#include <random>
#include <chrono>

std::vector<std::vector<char>> generatePirateMatrix() {
    std::vector<std::vector<char>> pirateMatrix = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '-', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', '|', 'o', '_', 'o', '|', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', '|', ':', '_', '/', ' ', '|', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', '(', '/', ' ', ' ', ' ', '\\', ' ', '\\', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ')', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '/', '\'', '\\', '_', ' ', ' ', '_', '/', '`', '\\', ' ', ' ', ' '},
    {' ', ' ', ' ', '\\', '_', '_', '_', ')', '=', '(', '_', '_', '/', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '_', '.', '-', '.', '\'', '_', '`', '.', '-', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' '},
    {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '\\', '.', '-', '\'', '_', '/', '`', '\\', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', '\'', '`', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '-', ' ', ' ', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '-', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' ', ' ', ' ', ' ', ' ', ' '},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' '},
    {'\\', '.', '-', '\'', '\\', '_', '/', '`', '-', '.', '/', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '\'', '.', '_', '_', '_', '.', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'~', '~', '~', '_', '|', '_', '|', '_', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'~', '~', '~', ' ', ' ', ' ', ' ', ' ', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'~', '~', '(', '_', '_', '_', '_', '_', ')', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
    {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
};


    return pirateMatrix;
}

int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);

    std::vector<std::vector<char>> pirateArt = generatePirateMatrix();

    // Generate a random pirate image by randomly flipping characters and adding ovals
    std::uniform_int_distribution<int> ovalCountDist(1, 5);  // Random number of ovals between 1 and 5
    int ovalCount = ovalCountDist(rng);

    for (int i = 0; i < ovalCount; ++i) {
        std::uniform_int_distribution<int> rowDist(0, pirateArt.size() / 2 - 1);
        std::uniform_int_distribution<int> colDist(0, pirateArt[0].size() - 1);
        int ovalRow = rowDist(rng);
        int ovalCol = colDist(rng);

        pirateArt[ovalRow][ovalCol] = '\\';  // Replace with '\' for the oval
        pirateArt[ovalRow][ovalCol + 1] = ' ';  // Create space for the oval
        pirateArt[ovalRow][ovalCol + 2] = '/';  // Replace with '/' for the oval
    }

    // Add horizon line through the back of the head
    int horizonRow = pirateArt.size() / 2;
    for (int col = 0; col < pirateArt[horizonRow].size(); ++col) {
        if (pirateArt[horizonRow][col] != ' ') {
            pirateArt[horizonRow][col] = '_';
        }
    }

    // Print the generated art
    for (const auto& row : pirateArt) {
        for (const auto& character : row) {
            std::cout << character;
        }
        std::cout << std::endl;
    }

    return 0;
}


