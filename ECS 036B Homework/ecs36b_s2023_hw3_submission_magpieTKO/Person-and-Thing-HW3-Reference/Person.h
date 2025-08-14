
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

#include "GPS.h"
#include "JvTime.h"

class Person
{
 private:
  std::string name;
  std::string occupation;
  
public:
  Person(std::string, std::string);
  Person();

  bool operator==(Person& aPerson);
  std::string getName();
  void dump();
  Json::Value dump2JSON();
};

#endif  /* _PERSON_H_ */
