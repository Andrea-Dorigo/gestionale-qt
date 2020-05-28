#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "nlohmann/json.hpp"
#include "serialize.h"

// read a JSON file and return a json element
nlohmann::json Serialize::read(const std::string& nome_file) {
  nlohmann::json j;
  try {
    std::ifstream i(nome_file);
    i >> j;
  } //se non esiste il file allora crealo vuoto
  catch(const nlohmann::detail::parse_error e) {
    std::ofstream o(nome_file);
  }
  return j;
}

// write prettified JSON to file
void Serialize::write(const std::string& nome_file, const nlohmann::json& j) {
  std::ofstream o(nome_file);
  o << std::setw(4) << j << std::endl;
}

int main() {
  Serialize s;
  std::string nome_file = "magazzino.json";
  nlohmann::json documento;

  /* scrive il contenuto di documento nel file .json
  documento["nome"] = "Mario";
  documento["cognome"] = "Rossi";
  s.write(nome_file, documento);
  */

  /* legge il file .json e lo salva in un elemento js
  documento = s.read(nome_file);
  std::cout << std::setw(4) << documento << std::endl;
  */

  return 0;
}
