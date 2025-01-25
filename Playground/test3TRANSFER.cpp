#include <iostream>
#include <vector>

int main() {
    size_t sizeInGB = 10;
    size_t sizeInBytes = sizeInGB * 1024 * 1024 * 1024;  // Convert GB to bytes

    try {
        std::vector<char> memory(sizeInBytes, 1);  // Allocate and fill with 1

        std::cout << "Allocated " << sizeInGB << "GB of RAM.\n";
        std::cout << "Press any key and hit Enter to exit...\n";
        
        char exitChar;
        std::cin >> exitChar;  // Wait for user input to exit
        
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
