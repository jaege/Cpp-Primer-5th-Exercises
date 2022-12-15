#include <string>
#include <map>
#include <vector>
#include <utility>
#include <iostream>

typedef std::map<std::string,
                 std::vector<std::pair<std::string, std::string>>> family_type;

void addFamily(family_type &families, const std::string &name) {
  auto ret = families.insert({name,
      std::vector<std::pair<std::string, std::string>>()});
  if (!ret.second)
    std::cerr << "Error: Already has family <" << name << ">" << std::endl;
}

void addChild(family_type &families, const std::string &family_name,
    const std::string &child_name, const std::string &birthday) {
  auto it = families.find(family_name);
  if (it != families.end())
    it->second.push_back({child_name, birthday});
  else
    std::cerr << "Error: No family <" << family_name << "> for child <"
              << child_name << "> born on " << birthday << std::endl;
}

int main() {
  family_type families;
  addFamily(families, "Zhang");
  addFamily(families, "Li");
  addFamily(families, "Wang");
  addFamily(families, "Zhang");  // Error

  addChild(families, "Zhang", "San", "1990-1-1");
  addChild(families, "Zhang", "Bao", "1990-1-2");
  addChild(families, "Zhang", "Tian", "1990-1-3");
  addChild(families, "Li", "Si", "1990-1-4");
  addChild(families, "Wang", "Wu", "1990-1-5");
  addChild(families, "Wang", "San", "1990-1-6");
  addChild(families, "Zhao", "Liu", "1990-1-7");  // Error

  for (const auto &family : families)
    for (const auto &child : family.second)
      std::cout << family.first << " " << child.first << " "
                << child.second << std::endl;

  return 0;
}
