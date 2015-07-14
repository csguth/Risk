#include "earth.h"

namespace risk {
namespace map {

const std::unique_ptr<map> earth::instance_{new earth};
	
earth::earth() :
	map("Earth")
{
	add_continent(continent{"North America"});
	add_continent(continent{"South America"});
	add_continent(continent{"Europe"});
	add_continent(continent{"Africa"});
	add_continent(continent{"Asia"});
	add_continent(continent{"Oceania"});
}
earth::~earth()
{

}

}
}