#include <iostream>
#include <string>
#include "../libraries/random.h"
using namespace std;

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };
    // constructor type
    Monster(Type itype, string_view iName, string_view iRoar, int hp)
        : m_type{itype}, m_name{iName}, m_roar{iRoar}, m_hitpoints{hp}
    {
    }

    constexpr string_view getTypeString() const
    {
        switch (m_type)
        {
        case dragon:
            return "dragon";
        case goblin:
            return "goblin";
        case ogre:
            return "ogre";
        case orc:
            return "orc";
        case skeleton:
            return "skeleton";
        case troll:
            return "troll";
        case vampire:
            return "vampire";
        case zombie:
            return "zombie";
        default:
            return "???";
        }
    }

    void print() const
    {
        cout << m_name << " the " << getTypeString();
        if (m_hitpoints > 0)
        {
            cout << " has " << m_hitpoints << " and says " << m_roar << '\n';
        }
        else
        {
            cout << " is dead." << '\n';
        }
    }

private:
    Type m_type{};
    string m_name{"???"};
    string m_roar{"???"};
    int m_hitpoints{10};
};

namespace MonsterGenerator
{
    std::string_view getName(int n)
    {
        switch (n)
        {
        case 0:
            return "Blarg";
        case 1:
            return "Moog";
        case 2:
            return "Pksh";
        case 3:
            return "Tyrn";
        case 4:
            return "Mort";
        case 5:
            return "Hans";
        default:
            return "???";
        }
    }

    std::string_view getRoar(int n)
    {
        switch (n)
        {
        case 0:
            return "*ROAR*";
        case 1:
            return "*peep*";
        case 2:
            return "*squeal*";
        case 3:
            return "*whine*";
        case 4:
            return "*growl*";
        case 5:
            return "*burp*";
        default:
            return "???";
        }
    }

    Monster generate()
    {
        return Monster{static_cast<Monster::Type>(Random::get(0, 5)), getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), Random::get(1, 100)};
    }
}

int main()
{
    Monster m{MonsterGenerator::generate()};
    m.print();

    return 0;
}
