#include <json/json.h>
#include "Person.h"

Person::Person(std::string arg_name, std::string arg_occupation)
{
  this->name = arg_name;
  this->occupation = arg_occupation;
}

Person::Person()
{
  this->name = "";
  this->occupation = "";
}

std::string
Person::getName()
{
  return this->name;
}

// function prototype
bool
Person::operator==
(Person& aPerson)
{
  return this->name == aPerson.getName();
}

void Person::dump
(void)
{
  std::cout << "[Person] dump-begin" << std::endl;
  std::cout << "name           = " << this->name << std::endl;
  std::cout << "[Person] dump-end" << std::endl;

  return;
}

Json::Value Person::dump2JSON(void) {
	Json::Value result;

	if(this->name != "")
		result["name"] = this->name;
	if(this->occupation != "")
		result["occupation"] = this->occupation;

	return result;
}
