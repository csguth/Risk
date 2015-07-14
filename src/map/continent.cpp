#include "continent.h"

namespace risk {
namespace map {

continent::continent(std::string name) :
	name_(name)
{

}

continent::~continent(){

}

continent_has_name::continent_has_name(const std::string name):
	name_(name)
{
}

bool continent_has_name::operator()(const continent & c) const
{
	return c.name() == name_;
}

}
}