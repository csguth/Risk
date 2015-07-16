#ifndef MAP_MAP_GRAPH_H
#define MAP_MAP_GRAPH_H

#include <string>
#include <set>
#include <utility>

namespace risk {
namespace map {

struct map_graph_edge {
	std::string u;
	std::string v;
	struct compare {
		bool operator()(const map_graph_edge e1, const map_graph_edge e2) const;
	};
};

class map_graph {
	std::set<std::string> nodes_;
	std::set<map_graph_edge, map_graph_edge::compare> edges_;
public:
	map_graph();

	inline int num_nodes() const { return nodes_.size(); }
	inline int num_edges() const { return edges_.size(); }

	bool node(std::string name) const;
	bool add_node(std::string name);
	bool remove_node(std::string name);

	bool edge(std::string u, std::string v) const;
	bool add_edge(std::string u, std::string v);
	bool remove_edge(std::string u, std::string v);

};
	
}
}


#endif /* MAP_MAP_GRAPH_H */