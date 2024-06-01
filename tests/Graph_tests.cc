#include <gtest/gtest.h>
#include <iostream>
#include <Graph.h>

using namespace std;
using namespace nestea;

TEST(Graph_tests, add_vertex) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.print();
}

TEST(Graph_tests, has_vertex) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.print();
	EXPECT_TRUE(graph.has_vertex(4));
}

TEST(Graph_tests, add_edges) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	graph.print();
}

TEST(Graph_tests, remove_edge) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	graph.remove_edge(3, 4);
	graph.print();
}

TEST(Graph_tests, remove_vertex) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	graph.remove_vertex(3);
	graph.print();
}

TEST(Graph_tests, vertexs) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	vector<int> vertexs = graph.vertices();
	for (const auto& v : vertexs)
		cout << v << " ";
}

TEST(Graph_tests, remove_edge_with_dist) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	EXPECT_FALSE(graph.remove_edge(3, 4, 5));
}

TEST(Graph_tests, has_edge) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	EXPECT_FALSE(graph.has_edge(3, 2));
}

TEST(Graph_tests, has_edge_with_dist) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	EXPECT_TRUE(graph.has_edge(3, 4, 7));
}

TEST(Graph_tests, edges) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(3);
	graph.add_vertex(2);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	vector<Edge<int, int>> edges = graph.edges(2);
	for (const auto& e : edges)
		cout << e.id_to << "(" << e.weight << ") ";
}

TEST(Graph_tests, order) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	size_t order = graph.order();
	cout << order << "\n";
}

TEST(Graph_tests, degree) {
	Graph<int, int> graph;
	graph.add_vertex(0);
	graph.add_vertex(1);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.add_vertex(4);
	graph.add_edge(0, 1, 2);
	graph.add_edge(0, 4, 9);
	graph.add_edge(1, 3, 3);
	graph.add_edge(1, 4, 1);
	graph.add_edge(2, 0, 4);
	graph.add_edge(2, 1, 8);
	graph.add_edge(2, 3, 10);
	graph.add_edge(3, 0, 6);
	graph.add_edge(3, 4, 7);
	graph.add_edge(4, 2, 5);
	size_t degree = graph.degree(2);
	cout << degree << "\n";
}