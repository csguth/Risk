#ifndef MAP_MAP_PARSER_H
#define MAP_MAP_PARSER_H

#include <fstream>
#include "map_graph.h"

namespace risk {
namespace map {

class map_parser {
public:
	map_graph read_file(std::string filename);
};

}
}

#endif /* MAP_MAP_PARSER_H */
