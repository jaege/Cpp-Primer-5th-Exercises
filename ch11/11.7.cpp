#include <string>
#include <map>
#include <vector>
#include <iostream>

typedef std::map<std::string, std::vector<std::string>> family_type;

void addFamily(family_type &families, const std::string &name) {
  auto ret = families.insert({name, std::vector<std::string>()});
  if (!ret.second)
    std::cerr << "Error: Already has family <" << name << ">" << std::endl;
}

void addChild(family_type &families, const std::string &family_name,
    const std::string &child_name) {
  auto it = families.find(family_name);
  if (it != families.end())
    it->second.push_back(child_name);
  else
    std::cerr << "Error: No family <" << family_name << "> for child <"
              << child_name << ">" << std::endl;
}

int main() {
  family_type families;
  addFamily(families, "Zhang");
  addFamily(families, "Li");
  addFamily(families, "Wang");
  addFamily(families, "Zhang");  // Error

  addChild(families, "Zhang", "San");
  addChild(families, "Zhang", "Bao");
  addChild(families, "Zhang", "Tian");
  addChild(families, "Li", "Si");
  addChild(families, "Wang", "Wu");
  addChild(families, "Wang", "San");
  addChild(families, "Zhao", "Liu");  // Error

  for (const auto &family : families)
    for (const auto &name : family.second)
      std::cout << family.first << " " << name << std::endl;

  return 0;
}
