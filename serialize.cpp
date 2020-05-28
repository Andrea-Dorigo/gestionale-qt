#include <iostream>
#include <fstream>
#include <iomanip>
#include "nlohmann/json.hpp"
#include "serialize.h"

// read a JSON file
void Serialize::read() {
  std::ifstream i("file.json");
  nlohmann::json j;
  i >> j;
}

// write prettified JSON to another file
void Serialize::write() {
  std::ofstream o("pretty.json");
  nlohmann::json j;
  o << std::setw(4) << j << std::endl;
}

int main() {
  Serialize s;
  s.write();
  return 0;
}
