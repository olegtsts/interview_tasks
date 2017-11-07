#include <vector>
#include <iostream>
#include <deque>

class PrintVisitor {
public:
    void Visit(const size_t vertex) {
        std::cout << vertex << "\n";
    }
};

class Tree {
private:
    std::vector<std::vector<size_t>> neighours_;
public:
    void AddEdge(const size_t first_vertex, const size_t second_vertex) {
        neighours_[first_vertex].push_back(second_vertex);
        neighours_[second_vertex].push_back(first_vertex);
    }
    friend std::istream& operator>>(std::istream& in, Tree& tree) {
        size_t vertices_count;
        in >> vertices_count;
        tree.neighours_.resize(vertices_count);
        size_t edges_count;
        in >> edges_count;
        for (size_t i = 0; i < edges_count; ++i) {
            size_t first_vertex, second_vertex;
            in >> first_vertex >> second_vertex;
            tree.AddEdge(first_vertex, second_vertex);
        }
        return in;
    }
    template <typename Visitor>
    void DoDFS(Visitor& visitor) {
        std::vector<bool> is_visited(neighours_.size(), false);
        DoRecursiveDFS(visitor, 0, is_visited);
    }
    template <typename Visitor>
    void DoRecursiveDFS(Visitor& visitor,
                        const size_t current_vertex,
                        std::vector<bool>& is_visited) {
        if (!is_visited[current_vertex]) {
            visitor.Visit(current_vertex);
            is_visited[current_vertex] = true;
            for (auto& another_vertex: neighours_[current_vertex]) {
                DoRecursiveDFS(visitor, another_vertex, is_visited);
            }
        }
    }
    template <typename Visitor>
    void DoBFS(Visitor& visitor) {
        std::deque<int> index_queue;
        std::vector<bool> is_visited(neighours_.size(), false);
        index_queue.push_back(0);
        is_visited[0] = true;
        while (index_queue.size() > 0) {
            size_t next_vertex = index_queue.front();
            index_queue.pop_front();
            visitor.Visit(next_vertex);
            for (auto& new_vertex: neighours_[next_vertex]) {
                if (!is_visited[new_vertex]) {
                    is_visited[new_vertex] = true;
                    index_queue.push_back(new_vertex);
                }
            }
        }
    }
};


int main() {
    Tree tree;
    std::cin >> tree;
    PrintVisitor print_visitor;
    tree.DoDFS(print_visitor);
    tree.DoBFS(print_visitor);
    return 0;
}
