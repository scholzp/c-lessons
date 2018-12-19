#include <stdlib.h>
#include <stdio.h>

enum gender {m, w};

struct reindeer {
  enum gender gender;
  int age;
  int pullForce; //in kg
};

struct present {
  int weight; //in kg
  int price;
};

struct sledge {
  struct reindeer deers[8];
  struct present presents[20];
  int maxTransportWeight;
};


int main(void) {
  // init reindeers
  struct reindeer rudolph = {m, 7, 63};
  // init presents
  struct present computer = {7, 800};
  struct present bookshelf = {50, 509};
  struct present fridge = {150, 750};
  // init sledge
  struct sledge santasSledge;

  // init weight of all deers with 0
  for (size_t i = 0; i < (sizeof(santasSledge.deers)/sizeof(struct reindeer)); i++) {
    santasSledge.deers[i].pullForce = 0;
  }
  // init weight of all presents with 0
  for (size_t i = 0; i < (sizeof(santasSledge.presents)/sizeof(struct present)); i++) {
    santasSledge.presents[i].weight = 0;
    santasSledge.presents[i].price = 0;
  }


  // set santasSledge variables
  santasSledge.maxTransportWeight = 500;
  santasSledge.presents[0] = computer;
  santasSledge.presents[1] = bookshelf;
  santasSledge.presents[2] = fridge;
  santasSledge.deers[0] = rudolph;

  // resultvariables for calculation
  int pullForceSum = 0;
  int presentWeightSum = 0;
  float presentPriceSum = 0;

  // iterate through all reindeers and get the pullforce of each reindeer
  for (size_t i = 0; i < (sizeof(santasSledge.deers)/sizeof(struct reindeer)); i++) {
    pullForceSum += santasSledge.deers[i].pullForce;
  }

  //iterate through all presents and get the weight and the price of all presents
  for (size_t i = 0; i < (sizeof(santasSledge.presents)/sizeof(struct present)); i++) {
    presentWeightSum += santasSledge.presents[i].weight;
    presentPriceSum += santasSledge.presents[i].price;
  }

  // check if the deers have enough force to pull the sledge
  if (presentWeightSum <= pullForceSum) printf("The reindeers have enough force to pull the sledge\n");
  else printf("The reindeers dont have enough force to pull the sledge\nYou should add more reindeers!\n\n");

  printf("pullForce: %i Kg\n", pullForceSum);
  printf("presentWeightSum: %i Kg\n", presentWeightSum);
  printf("force that is still needed: %i Kg\n", presentWeightSum-pullForceSum);

  //print the total price and calculate the insurance cost
  printf("\nTotal carried money worth: %f\n", presentPriceSum);
  printf("The price for the insurance of the cargo are (2%% of the money worth): %f\n", presentPriceSum*0.03);

  return 0;
}
