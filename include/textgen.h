#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <deque>
#include <map>
#include <random>
#include <ctime>

using prefix = std::deque<std::string>;

class generator {
 private:
    std::map<prefix, std::vector<std::string> > map;
 public:
    void train(std::istream &source, int prefix_size);
    std::string generate_text(int length);
    void set_map(std::map<prefix, std::vector<std::string> > _map);
    std::map<prefix, std::vector<std::string> > get_map();
};