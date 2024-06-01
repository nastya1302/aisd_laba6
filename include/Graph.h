#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace nestea {
    template<typename V, typename D = double>
    struct Edge {
        V id_to;
        D weight;

        Edge(V _id_to, D _weight) : id_to(_id_to), weight(_weight) {}
    };

    template<typename V, typename D = double>
    struct Vertex {
        V id_from;
        vector<Edge<V, D>> edges;
    };

    template<typename V, typename D = double>
    class Graph {
    private:
        vector<Vertex<V, D>> graph;
    public:
        //проверка-добавление-удаление вершин
        bool has_vertex(const V& id_vertex) const {
            for (const auto& vertex : graph)
                if (vertex.id_from == id_vertex) 
                    return true;
            return false;
        }
        void add_vertex(const V& id) {
            if (has_vertex(id) == true) 
                throw std::invalid_argument("Graph::A vertex with this id already exists.");
            Vertex<V, D> vertex(id);
            graph.push_back(vertex);
        }
        bool remove_vertex(const V& id) {
            if(!has_vertex(id))
                throw std::invalid_argument("Graph::The vertex is missing.");
            for (const auto& vertex : graph) {
                remove_edge(id, vertex.id_from);
                remove_edge(vertex.id_from, id);
            }
            for (int i = 0; i < graph.size(); i++) {
                if (graph[i].id_from == id) {
                    graph.erase(graph.begin() + i);
                    return true;
                }
            }
            return false;
        }
        vector<V> vertices() const {
            vector<V> vertexs;
            for (const auto& vertex : graph)
                vertexs.push_back(vertex.id_from);
            return vertexs;
        }

        //проверка-добавление-удаление ребер
        void add_edge(const V& _id_from, const V& _id_to, const D& _weight) {
            if(!has_vertex(_id_from) || !has_vertex(_id_to))
                throw std::invalid_argument("Graph::It is not possible to insert an edge to a non-existent vertex.");
            Edge<V, D> edge(_id_to, _weight);
            for (auto i = graph.begin(); i != graph.end(); i++)
                if(i->id_from == _id_from)
                    i->edges.push_back(edge);
        }
        bool remove_edge(const V& _id_from, const V& _id_to) {
            if (!has_vertex(_id_from) || !has_vertex(_id_to))
                throw std::invalid_argument("Graph::You cannot delete a non-existent edge.");
            for (auto j = graph.begin(); j != graph.end(); j++)
                if (j->id_from == _id_from) {
                    for (auto i = j->edges.begin(); i != j->edges.end(); i++) {
                        if (i->id_to == _id_to) {
                            j->edges.erase(i);
                            return true;
                        }
                    }
                }
            return false;
        }
        bool remove_edge(const V& _id_from, const V& _id_to, const D& _weight) {
            if (!has_vertex(_id_from) || !has_vertex(_id_to))
                throw std::invalid_argument("Graph::You cannot delete a non-existent edge.");
            for (auto j = graph.begin(); j != graph.end(); j++)
                if (j->id_from == _id_from) {
                    for (auto i = j->edges.begin(); i != j->edges.end(); i++) {
                        if (i->id_to == _id_to && i->weight == _weight) {
                            j->edges.erase(i);
                            return true;
                        }
                    }
                }
            return false;
        }
        bool has_edge(const V& _id_from, const V& _id_to) const {
            if (!has_vertex(_id_from) || !has_vertex(_id_to))
                throw std::invalid_argument("Graph::There is no such vertex.");
            for (auto j = graph.begin(); j != graph.end(); j++)
                if (j->id_from == _id_from) {
                    for (auto i = j->edges.begin(); i != j->edges.end(); i++) {
                        if (i->id_to == _id_to) {
                            return true;
                        }
                    }
                }
            return false;
        }
        bool has_edge(const V& _id_from, const V& _id_to, const D& _weight) const { //c учетом расстояния в Edge
            if (!has_vertex(_id_from) || !has_vertex(_id_to))
                throw std::invalid_argument("Graph::You cannot delete a non-existent edge.");
            for (auto j = graph.begin(); j != graph.end(); j++)
                if (j->id_from == _id_from) {
                    for (auto i = j->edges.begin(); i != j->edges.end(); i++) {
                        if (i->id_to == _id_to && i->weight == _weight) {
                            return true;
                        }
                    }
                }
            return false;
        }
        //получение всех ребер, выходящих из вершины
        vector<Edge<V, D>> edges(const V& _id_from) {
            if (!has_vertex(_id_from))
                throw std::invalid_argument("Graph::There is no such vertex.");
            for (const auto& vertex : graph)
                if (vertex.id_from == _id_from)
                    return vertex.edges;
        }

        size_t order() const { //порядок 
            return graph.size();
        }
        size_t degree(const V& _id_from) const { //степень вершины
            if (!has_vertex(_id_from))
                throw std::invalid_argument("Graph::There is no such vertex.");
            for (const auto& vertex : graph)
                if (vertex.id_from == _id_from)
                    return vertex.edges.size();
        }

        //поиск кратчайшего пути
        std::vector<Edge<V, D>> BellmanFord(const V& from, const V& to) const {

        }
        //обход
        std::vector<V> bfs(const V& start_vertex)const {
            
        }

        void print() {
            for (auto i = graph.begin(); i != graph.end(); i++) {
                cout << i->id_from << ": ";
                for (auto j = i->edges.begin(); j != i->edges.end(); j++)
                {
                    cout << j->id_to << "(" << j->weight << ") ";
                }
                cout << endl;
            }
        }
    };
}