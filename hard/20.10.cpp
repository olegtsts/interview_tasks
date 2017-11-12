#include <unordered_set>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

const std::unordered_set<std::string> DICT{"damp", "lamp", "limp", "lime", "like"};

void dfs(
  std::unordered_set<std::string>& visited_strings,
  std::unordered_map<std::string, std::string>& previous_string,
  const std::string& parent_string,
  const std::string& current_string,
  const std::string& target_string
) {
  if (visited_strings.count(current_string) == 0) {
    visited_strings.insert(current_string);
    if (parent_string != "") {
      previous_string[current_string] = parent_string;
    }
    if (current_string == target_string) {
      return;
    }
    for (size_t index = 0; index < current_string.size(); ++index) {
      std::string new_string = current_string;
      for (size_t symbol = 'a'; symbol <= 'z'; ++symbol) {
        new_string[index] = symbol;
        if (DICT.count(new_string) > 0) {
           dfs(visited_strings, previous_string, current_string, new_string, target_string);
        }
      }
    }
  }
}

std::vector<std::string> GetTransformationPath(const std::string& initial_string, 
    const std::string& target_string) {
  std::unordered_set<std::string> visited_strings;
  std::unordered_map<std::string, std::string> previous_string;
  dfs(visited_strings, previous_string, "", initial_string, target_string);
  std::vector<std::string> transformation_path(1, target_string);
  if (visited_strings.count(target_string) > 0) {
    std::string current_string = target_string;
    while (previous_string.count(current_string) > 0) {
      current_string = previous_string[current_string];
      transformation_path.push_back(current_string);
    }
  }
  std::reverse(transformation_path.begin(), transformation_path.end());
  return transformation_path;
}

int main() {
  std::string initial_string("damp");
  std::string target_string("like");
  std::vector<std::string> transformation_path = GetTransformationPath(initial_string, target_string);
  for (auto& element: transformation_path) {
    std::cout << element << ' '; 
  }
  return 0;
}