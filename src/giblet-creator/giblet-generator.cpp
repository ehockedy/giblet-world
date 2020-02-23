#include "giblet-generator.h"

#include "giblet-accessory.h"
#include "reader.h"

#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>

GibletGenerator::GibletGenerator() {
  srand(time(0)); 
}

GibletGenerator::~GibletGenerator() {

}

int GibletGenerator::GenerateUniqueAccessories(const unsigned int num_accessories) {
  JsonReader jr;
  if (!jr.OpenFile("src/json-reader/giblet-parts.json")) return 1;
  if (!jr.Validate("src/json-reader/giblet_accessories_schema.json", true)) return 1;

  unsigned int total_num_accessories = jr.GetJsonFileRef()["entries"].Size();
  if (total_num_accessories < num_accessories) {
    std::cout << "requested too many accessories" << std::endl;
    return 1;
  }

  std::vector<int> accessories;
  while (accessories.size() < num_accessories) {
    unsigned int unique_accessory_idx = rand() % total_num_accessories;
    if (std::find(accessories.begin(), accessories.end(),
                  unique_accessory_idx) == accessories.end()) {
      std::cout << "Accessory " << accessories.size() << ":" << std::endl
                << "Name: " 
                << jr.GetJsonFileRef()["entries"][unique_accessory_idx]["name"].GetString() 
                << std::endl
                << "Cost: "
                << jr.GetJsonFileRef()["entries"][unique_accessory_idx]["cost"].GetInt()
                << std::endl << std::endl;
      accessories.push_back(unique_accessory_idx);
    }
  }

  int accessory_idx;
  std::cout << "Pick an accessory: ";
  std::cin >> accessory_idx;
  // TODO error checking 
  
  accessory.SetName(jr.GetJsonFileRef()["entries"][accessories[accessory_idx]]["name"].GetString());

  std::cout << "Name set for chosen accessory " << accessory.GetName() << std::endl;

  return 0;
}
