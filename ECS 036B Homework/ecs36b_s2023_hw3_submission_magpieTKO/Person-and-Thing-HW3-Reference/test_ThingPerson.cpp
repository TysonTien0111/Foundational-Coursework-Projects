
// test_GPS.cpp

#include "Person.h"
#include "Thing.h"
#include "Record.h"

int
main(int argc, char *argv[])
{
  Person nobody {};
  Thing nothing {};
  GPS_DD nowhere {};

  Person Instructor {"Felix Wu", "Professor"};
  Person Tiffany {"Tiffany", "Bus Driver, Pschology Student"};
  Person John {"John", "Student"};

  Thing Android {"Mobile Phone", "Android"};
  Thing Computer {"Laptop Computer", "Macbook"};
  Thing Bus {"Double-Decker Bus", "L-Line"};

  GPS_DD Everson {"Everson Hall 176", 38.538786510228626, -121.75014085056156};
  GPS_DD Silo {"Silo Bus Station", 38.5393093381557, -121.75311259202586};
  GPS_DD Stop1 {"8th and J Street Bus Stop", 38.55209894849183, -121.7388025582152};
  GPS_DD Stop2 {"Moore and Pollock Bus Stop", 38.564551195039904, -121.71911435937336};

  JvTime time1 {"3923-05-12T18:00:00+0000"};
  JvTime time2 {"3923-05-12T18:10:00+0000"};
  JvTime time3 {"3923-05-12T18:20:00+0000"};
  JvTime time4 {"3923-05-12T18:32:00+0000"};

  Record record1 {Instructor, John, nobody, Android, Computer, nothing, Everson, time1}; 
  Record record2 {Instructor, Tiffany, John, Android, Computer, Bus, Silo, time2};
  Record record3 {Instructor, Tiffany, nobody, Android, Bus, nothing, Stop1, time3};
  Record record4 {Instructor, nobody, nobody, Android, nothing, nothing, Stop2, time4};

  std::cout << record1.dump2JSON().toStyledString() << std::endl;
  std::cout << record2.dump2JSON().toStyledString() << std::endl;
  std::cout << record3.dump2JSON().toStyledString() << std::endl;
  std::cout << record4.dump2JSON().toStyledString() << std::endl;
  
  return 0;
}
