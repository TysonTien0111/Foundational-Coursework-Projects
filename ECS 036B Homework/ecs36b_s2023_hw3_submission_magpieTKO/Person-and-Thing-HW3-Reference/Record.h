
#ifndef _RECORD_H_
#define _RECORD_H_

// Record.h

#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "JvTime.h"

#include "ecs36b_Common.h"

class Record
{
 private:
  Person who1;
  Person who2;
  Person who3;
  Thing what1;
  Thing what2;
  Thing what3;
  GPS_DD where;
  JvTime when;
  
public:
  Record(Person, Person, Person, Thing, Thing, Thing, GPS_DD, JvTime);
  Json::Value dump2JSON();
};

#endif  /* _RECORD_H_ */
