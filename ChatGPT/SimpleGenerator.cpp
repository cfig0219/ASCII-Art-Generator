#include <iostream>
#include <vector>
#include <random>

int main() {
    std::vector<std::vector<char>> art = {
        {'#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', ' ', '@', ' ', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#'}
    };

    // Randomize the art by flipping characters
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1);

    for (auto& row : art) {
        for (auto& character : row) {
            if (dist(rng) == 1) {
                character = '-';
            }
        }
    }

    // Print the generated art
    for (const auto& row : art) {
        for (const auto& character : row) {
            std::cout << character;
        }
        std::cout << '\n';
    }

    return 0;
}
