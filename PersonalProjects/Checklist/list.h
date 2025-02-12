#ifndef LIST_H
#define LIST_H

#include <string>
#include <vector>

class List{
   private:
      std::string name {};
      std::vector<std::string> elements {};
   public:
      //adds an element to the list, returns 1 if add successful and 0 if failure
      bool addElement();
      //removes an element to the list, returns 1 if add successful and 0 if failure
      bool removeElement();

};

#endif
