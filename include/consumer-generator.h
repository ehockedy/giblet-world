#ifndef INCLUDE_CONSUMER_GENERATOR_H_
#define INCLUDE_CONSUMER_GENERATOR_H_

#include "reader.h"
#include "consumer.h"
#include "giblet.h"

#include <vector>

class ConsumerGenerator {
 public:
  ConsumerGenerator();
  ~ConsumerGenerator();
  int GenerateUniqueConsumers(const unsigned int num_consumers);
  std::vector<Consumer>& GetConsumers();
  //static bool CalculateUsageRate(int i);
  static bool CalculateUsageRate(std::vector<Consumer>& consumers, Giblet& giblet);
 private:
  std::vector<Consumer> consumers;
//private:
//  GibletAccessory accessory;
};

# endif //INCLUDE_CONSUMER_GENERATOR_H_
