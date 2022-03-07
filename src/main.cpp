#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "rand.hpp"

# define X0            0.192837465
# define N_TERMS       100

static std::vector<double> terms(double x0,
                                 unsigned int n)
{
  double x = x0;
  std::vector<double> out;
  for (std::size_t ii = 0; ii < n; ++ii)
    {
      x = PNE_Rand(x);
      out.push_back(x);
    }
  return out;
}

static void write(std::ostream& out,
                  const std::vector<std::vector<double>>& v)
{
  if (v.empty())
     return;

  const std::size_t s = v[0].size();
  for (std::size_t ii = 0; ii < s; ii++) {
    for (std::size_t jj = 0; jj < v.size(); jj++) {
      out << v[jj][ii] << '\t';
    }
    out << '\n';
  }
}

int main(int argc, char** argv) {
  auto t1 = terms(X0, N_TERMS);
  auto t2 = terms(X0 + 1e-12, N_TERMS);
  std::ofstream outfile(argv[1]);
  outfile << std::setprecision(12);
  write(outfile, {t1, t2});
}
