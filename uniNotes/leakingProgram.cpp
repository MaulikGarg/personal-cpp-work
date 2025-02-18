// leakingProgram.cpp <- filename
#include <iostream>

void memoryLeak() {
    unsigned long size = 16000000000; // 16 billion bytes
    std::cout << "Allocating 16,000,000,000 bytes of memory...\n";
    char* largeArray = new char[size]('a');  // Leak: Memory allocated but never freed
    std::cout << "Memory allocated and filled with random characters.\n";
    // No delete[] here! The allocated memory is never freed -> Memory Leak!
}

int main() {
    memoryLeak();  
    getchar(); //to pause the program for demonstration
}
