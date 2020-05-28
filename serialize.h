#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <string>
#include "nlohmann/json.hpp"

class Serialize {
public:
  nlohmann::json read(const std::string& nome_file);
  void write(const std::string& nome_file, const nlohmann::json& j);
};

#endif // SERIALIZE_H
