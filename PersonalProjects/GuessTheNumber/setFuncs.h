#ifndef SETFUNCS_H
#define SETFUNCS_H

#include <set>

namespace numberGame
{
    auto getNumberSet() -> std::set<char>; // returns the randomized n numbers
    void printSet(std::set<char> funcSetTemporary);
    auto getSet(std::set<char> numbers) -> std::set<char>;
    void closeGame();
}
#endif
