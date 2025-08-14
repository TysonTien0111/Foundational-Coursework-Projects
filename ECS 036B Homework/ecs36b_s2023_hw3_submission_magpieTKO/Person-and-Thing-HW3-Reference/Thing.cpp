#include "Thing.h"

void
myPrintLog
(std::string content, std::string fname)
{
  if (fname.size() == 0) return;
  
  FILE *log_f = fopen(fname.c_str(), "a");
  if (log_f == NULL) return;
  
  JvTime *jv_ptr = getNowJvTime();
  std::string *str_ptr = jv_ptr->getTimeString();
  fprintf(log_f, "[%s] %s\n", str_ptr->c_str(), content.c_str());
  delete str_ptr;
  delete jv_ptr;
  fflush(log_f);
  fclose(log_f);
  return;
}


Thing::Thing(void) {
	this->model = "";
	this->description = "";
}

Thing::Thing
(std::string arg_description, std::string arg_model)
{
  this->model = arg_description; 
  this->description = arg_model;
}

std::string Thing::getDescription() {
		return this->description;
}

std::string Thing::getModel() {
		return this->model;
}

void Thing::dump
(void)
{
  std::cout << "[Thing] dump-begin" << std::endl;
  std::cout << "model          = " << this->model << std::endl;
  std::cout << "description    = " << this->description << std::endl;
  std::cout << "[Thing] dump-end" << std::endl;
  return;
}

Json::Value Thing::dump2JSON(void) {
	Json::Value record;

	if(this->model != "")
		record["model"] = this->model;
	if(this->description != "") 
		record["name"] = this->description;

	return record;
}
