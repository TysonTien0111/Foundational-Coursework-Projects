#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"
#include "GraphNode.hpp"
#include <queue>

template<typename T>
Graph<T>::Graph(const std::vector<std::pair<T, T>> &edges) 
{
    for (const auto &the_single_edge : edges) 
    {
        addVertex(the_single_edge.first);
        addVertex(the_single_edge.second);

        addEdge(the_single_edge.first, the_single_edge.second);
    }
}

template<typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList)
{
    for (const auto &the_vertex_entry: adjList) 
    {
        addVertex(the_vertex_entry.first);

        for (const auto &the_neighbor_vertex : the_vertex_entry.second) 
        {
            addVertex(the_neighbor_vertex);

            addEdge(the_vertex_entry.first, the_neighbor_vertex);
        }
    }
}

template<typename T>
int Graph<T>::size() const  
{
    return _vertices.size();
}

template<typename T>
void Graph<T>::addVertex(T vertex) 
{
    if (_vertices.find(vertex) == _vertices.end()) 
    {
        _vertices[vertex] = GraphNode<T>(vertex);

        _adjList[vertex] = std::set<T>();
    }
}

template<typename T>
void Graph<T>::addEdge(T from, T to) 
{
    addVertex(from);
    addVertex(to);

    _adjList[from].insert(to);
}

template<typename T>
bool Graph<T>::hasEdge(T from, T to) const 
{
    auto iterate_from = _vertices.find(from);
    auto iterate_to = _vertices.find(to);

    if ((iterate_from != _vertices.end()) && (iterate_to != _vertices.end())) 
    {
        if (_adjList.find(from) != _adjList.end()) 
        {
            return _adjList.at(from).find(to) != _adjList.at(from).end();
        } 
        else 
        {
            return false;
        }
    }

    return false;
}

template<typename T>
std::optional<std::set<T>> Graph<T>::getNeighbors(T vertex) const
{
    auto the_vertex_iterator = _adjList.find(vertex);

    if (the_vertex_iterator != _adjList.end()) 
    {
        return the_vertex_iterator->second;
    }

    return std::nullopt;
}

template<typename T>
std::vector<T> Graph<T>::BFS(T start) 
{
    for (auto &the_vertex : _vertices) 
    {
        the_vertex.second.color = White;
        the_vertex.second.distance = -1;
        the_vertex.second.predecessor = std::nullopt;
    }

    std::queue<T> the_bfs_queue;

    std::vector<T> the_result;

    _vertices[start].color = Gray;
    _vertices[start].distance = 0;

    the_bfs_queue.push(start);

    while (!the_bfs_queue.empty()) 
    {
        T the_current_vertex = the_bfs_queue.front();

        the_bfs_queue.pop();
        
        the_result.push_back(the_current_vertex);

        for (const auto &the_neighbor_vertex : _adjList[the_current_vertex]) 
        {
            if (_vertices[the_neighbor_vertex].color == White) 
            {
                _vertices[the_neighbor_vertex].color = Gray;
                _vertices[the_neighbor_vertex].distance = _vertices[the_current_vertex].distance + 1;
                _vertices[the_neighbor_vertex].predecessor = the_current_vertex;

                the_bfs_queue.push(the_neighbor_vertex);
            }
        }

        _vertices[the_current_vertex].color = Black;
    }

    return the_result;
}

template<typename T>
int Graph<T>::shortestPath(T start, T end) 
{
    for (auto &the_vertex : _vertices) 
    {
        the_vertex.second.color = White;
        the_vertex.second.distance = -1;
        the_vertex.second.predecessor = std::nullopt;
    }

    BFS(start);

    if (_vertices[end].color != Black) 
    {
        return -1;
    }

    return _vertices[end].distance;
}

template<typename T>
std::list<T> Graph<T>::DFS() 
{
    std::list<T> the_result;  

    for (auto &the_vertex : _vertices) 
    {
        the_vertex.second.color = White;
    }

    int the_time = 0;

    for (const auto &the_vertex : _vertices) 
    {
        if (the_vertex.second.color == White) 
        {
            DFS_visit(the_vertex.first, the_time, the_result);
        }
    }

    return the_result;
}

template<typename T>
void Graph<T>::DFS_visit(const T &u, int &time, std::list<T> &record) 
{
    time++;
    
    _vertices[u].discovery_time = time;
    _vertices[u].color = Gray;

    for (const auto &the_neighbor_vertex : _adjList[u]) 
    {
        if (_vertices[the_neighbor_vertex].color == White) 
        {
            _vertices[the_neighbor_vertex].predecessor = u;
            DFS_visit(the_neighbor_vertex, time, record);
        }
    }

    time++;

    _vertices[u].finish_time = time;
    _vertices[u].color = Black;

    record.push_front(u);
}

#endif // GRAPH_CPP
