
#ifndef _GPS_H_
#define _GPS_H_

// GPS.h

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>

#include "ecs36b_Common.h"

using namespace std;

class GPS_DD
{
 private:
	std::string name;
  double latitude;
  double longitude;
 public:
  explicit GPS_DD();
  explicit GPS_DD(std::string, double, double);
  std::string getName();
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  Json::Value dump2JSON();
};

#endif /* _GPS_H_ */
