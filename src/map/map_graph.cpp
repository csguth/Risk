#include "map_graph.h"

namespace risk {
namespace map {


bool map_graph_edge::compare::operator()(const map_graph_edge e1, const map_graph_edge e2) const
{
	return (e1.u+e1.v)<(e2.u+e2.v) && !(e1.u == e2.v && e1.v == e2.u);
}

map_graph::map_graph()
{

}

bool map_graph::node(std::string name) const
{
	return nodes_.find(name) != nodes_.end();
}

bool map_graph::add_node(std::string name)
{
	return nodes_.insert(name).second;
}

bool map_graph::remove_node(std::string name)
{
	return nodes_.erase(name) == 1;
}

bool map_graph::edge(std::string u, std::string v) const
{
	return edges_.find(map_graph_edge{u, v}) != edges_.end();
}

bool map_graph::add_edge(std::string u, std::string v)
{
	if(!node(u) || !node(v))
		return false;
	return edges_.insert(map_graph_edge{u, v}).second;
}

bool map_graph::remove_edge(std::string u, std::string v)
{
	return edges_.erase(map_graph_edge{u,v}) == 1;
}

	
}
}