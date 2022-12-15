#include <string>
#include <map>
#include <vector>
#include <iostream>

typedef std::multimap<std::string, std::vector<std::string>> family_type;

void addFamily(family_type &families, const std::string &name) {
  families.insert({name, std::vector<std::string>()});  // always insert value
  //auto ret = families.insert({name, std::vector<std::string>()});
  //if (!ret.second)
  //  std::cerr << "Error: Already has family <" << name << ">" << std::endl;
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

  addChild(families, "Zhang", "San");
  addChild(families, "Zhang", "Bao");
  addChild(families, "Zhang", "Tian");
  addChild(families, "Li", "Si");
  addChild(families, "Wang", "Wu");
  addChild(families, "Wang", "San");
  addChild(families, "Zhao", "Liu");  // Error

  addFamily(families, "Zhang");
  // OK, but the following two statement will add to the first "Zhang" key,
  // because we use `find()` to find the first present key.
  addChild(families, "Zhang", "Mei");
  addChild(families, "Zhang", "Lu");

  for (const auto &family : families) {
    std::cout << family.first << "'s family:" << std::endl;
    for (const auto &name : family.second)
      std::cout << family.first << " " << name << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
