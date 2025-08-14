
#ifndef _THING_H_
#define _THING_H_

// Thing.h
#include <json/json.h>
#include "Person.h"
#include "GPS.h"
#include "JvTime.h"

class Thing
{
 private:
 protected:
 public:
  
  std::string model;
  std::string description;

  Thing(void);
  Thing(std::string, std::string);
  std::string getModel();
  std::string getDescription();

  virtual void dump(); // print the content of the object
  Json::Value dump2JSON();
};

#endif /* _THING_H_ */
