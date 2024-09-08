
#include <eigen3/Eigen/Dense>
#include <string>
#include <vector>
using Eigen::ArrayXd;
using std::string;
using std::vector;

class GNB {
 public:
  /**
   * Constructor
   */
  GNB();

  /**
   * Destructor
   */
  virtual ~GNB();

  /**
   * Train classifier
   */
  void train(const vector<vector<double>> &data, const vector<string> &labels);

  /**
   * Predict with trained classifier
   */
  string predict(const vector<double> &sample);

  vector<string> possible_labels = {"left", "keep", "right"};

  ArrayXd left_means;
  ArrayXd left_sds;
  double left_prior;

  ArrayXd keep_means;
  ArrayXd keep_sds;
  double keep_prior;

  ArrayXd right_means;
  ArrayXd right_sds;
  double right_prior;
};