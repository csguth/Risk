#include <catch/catch.hpp>
#include "../src/map/map_parser.h"
#include "../src/map/map_graph.h"


TEST_CASE( "map graph" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	REQUIRE( graph.num_nodes() == 0 );
	REQUIRE( graph.num_edges() == 0 );
}

TEST_CASE( "insert node" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	REQUIRE( graph.add_node("u") );
	REQUIRE( !graph.add_node("u") );
	REQUIRE( graph.num_nodes() == 1 );
	graph.add_node("v");
	REQUIRE( graph.num_nodes() == 2 );
}

TEST_CASE( "check node" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	graph.add_node("u");
	REQUIRE( graph.node("u") );
	REQUIRE( !graph.node("v") );
}

TEST_CASE( "edge" ,"[map][map_graph]")
{
	risk::map::map_graph_edge edge{"u", "v"};
	REQUIRE( edge.u == "u" );
	REQUIRE( edge.v == "v" );
}

TEST_CASE( "remove node" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	graph.add_node("u");
	REQUIRE( graph.remove_node("u") );
	REQUIRE( !graph.remove_node("u") );
	REQUIRE( !graph.node("u") );
	REQUIRE( graph.num_nodes() == 0 );
}

TEST_CASE( "adding edge must have both two nodes" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	REQUIRE( !graph.add_edge("u", "v") );
	graph.add_node("u");
	REQUIRE( !graph.add_edge("u", "v") );
	graph.add_node("v");
	REQUIRE( graph.add_edge("u", "v") );
}

TEST_CASE( "insert edge" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	graph.add_node("u");
	graph.add_node("v");
	CHECK( graph.add_edge("u", "v") );
	CHECK( !graph.add_edge("u", "v") );
	CHECK( !graph.add_edge("v", "u") );
	CHECK( graph.num_edges() == 1 );
}

TEST_CASE( "remove edge" ,"[map][map_graph]")
{
	risk::map::map_graph graph;
	graph.add_node("u");
	graph.add_node("v");
	REQUIRE( graph.add_edge("u", "v") );
	REQUIRE( !graph.add_edge("u", "v") );
	REQUIRE( graph.remove_edge("u", "v") );
	REQUIRE( !graph.remove_edge("u", "v") );

	REQUIRE( graph.num_edges() == 0 );
}

TEST_CASE( "(a, b) < (c, d)" ,"[map][map_graph]")
{
	risk::map::map_graph_edge ab{"a", "b"};
	risk::map::map_graph_edge cd{"c", "d"};
	risk::map::map_graph_edge::compare comp;
	REQUIRE( comp(ab, cd) );
}



