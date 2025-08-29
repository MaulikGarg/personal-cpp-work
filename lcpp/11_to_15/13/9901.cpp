#include <iostream>
#include <String>
using namespace std;

struct Monster
{
    enum Type
    {
        ogre,
        dragon,
        orc,
        giantSpider,
        slime
    };
    Type monsterType {};
    string name{"monster"};
    int maxHP{10}; 
};

string_view getMonsterString(const Monster::Type& type){
    switch (type)
    {
    case Monster::ogre :
        return "Ogre";
    case Monster::dragon :
        return "Dragon";
    case Monster::orc :
        return "Orc";
    case Monster::giantSpider :
        return "Giant Spider";
    case Monster::slime :
        return "Slime";
    default:
        return "Inalid";
    }
}

void printMonster(const Monster& monster){
    cout << "This " << getMonsterString(monster.monsterType) 
    << " is named " << monster.name 
    << " has health " << monster.maxHP <<'\n';
}

int main()
{
    Monster ogre{ Monster::ogre, "Torg", 145 };
	Monster slime{ Monster::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);
    return 0;
}
