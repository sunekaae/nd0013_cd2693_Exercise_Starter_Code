#include <iostream>
#include <vector>

using std::vector;

// initialize priors assuming vehicle at landmark +/- 1.0 meters position stdev
vector<float> initialize_priors(int map_size, vector<float> landmark_positions,
                                float position_stdev);

int main() {
  // set standard deviation of position
  float position_stdev = 1.0f;

  // set map horizon distance in meters 
  int map_size = 25;

  // initialize landmarks
  vector<float> landmark_positions {5, 10, 20};

  // initialize priors
  vector<float> priors = initialize_priors(map_size, landmark_positions,
                                           position_stdev);

  // print values to stdout 
  for (int p = 0; p < priors.size(); ++p) {
    std::cout << priors[p] << std::endl;
  }

  return 0;
}

// TODO: Complete the initialize_priors function
vector<float> initialize_priors(int map_size, vector<float> landmark_positions,
                                float position_stdev) {

  // initialize priors assuming vehicle at landmark +/- 1.0 meters position stdev
 
    
  // set all priors to 0.0

  vector<float> priors(map_size, 0.0f);
  float std_dev = 1.0f;
      std::cout << "1priors.size(): " << priors.size() << "\n";
    
  // TODO: YOUR CODE HERE
  int positions = 0;
  for (float landmark : landmark_positions) {
    std::cout << "determining number of positions\n";
    positions = ++positions;
    if ((landmark-std_dev)>=0.0f) {
      positions = ++positions;
    }
    if ((landmark+std_dev)<=map_size) {
      positions = ++positions;
    }
  }
  std::cout << "positions: " << positions << "\n";

  float probability = 1.0f/positions;
  for (float landmark : landmark_positions) {
    priors[landmark] = probability;
    if ((landmark-std_dev)>=0.0f) {
      priors[landmark-std_dev] = probability;
    }
    if ((landmark+std_dev)<=map_size) {
      priors[landmark+std_dev] = probability;
    }
  }
 
  std::cout << "priors.size(): " << priors.size() << "\n";
        
  return priors;
}