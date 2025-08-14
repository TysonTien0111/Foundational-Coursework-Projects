
#include "Record.h"

Record::Record(Person _p1, Person _p2, Person _p3, Thing _t1, Thing _t2, Thing _t3, GPS_DD _g, JvTime _jt)
{
  this->who1 = _p1;
  this->who2 = _p2;
  this->who3 = _p3;
  this->what1 = _t1;
  this->what2 = _t2;
  this->what3 = _t3;
  this->where = _g;
  this->when = _jt;
}

Json::Value
Record::dump2JSON()
{
  Json::Value result;
  Json::Value persons;
  Json::Value things;

  if(!(this->who1).getName().empty())
  	persons.append((this->who1).dump2JSON());
  if(!(this->who2).getName().empty())
  	persons.append((this->who2).dump2JSON());
  if(!(this->who3).getName().empty())
  	persons.append((this->who3).dump2JSON());

  result["who"] = persons;

  if((this->what1).getModel() != "" || this->what1.getDescription() != "")
  	things.append((this->what1).dump2JSON());
  if((this->what2).getModel() != "" || this->what2.getDescription() != "")
  	things.append((this->what2).dump2JSON());
  if((this->what3).getModel() != "" || this->what3.getDescription() != "")
  	things.append((this->what3).dump2JSON());

  result["what"] = things;

  if((this->where).getName() != "")
  	result["where"] = (this->where).dump2JSON();

  result["when"] = (this->when).dump2JSON();

  return result;
}
