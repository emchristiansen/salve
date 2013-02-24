#ifndef FMap_HPP
#define FMap_HPP

#include <functional>

using namespace std;

// http://www.boost.org/doc/libs/1_53_0/libs/concept_check/concept_check.htm

template <typename A>
struct Equality {
  bool equals(const A& left, const A& right);
};

bool equals(const int left, const int right) {
  return left == right;
}



template <typename A>
bool equals(const vector<A>& left, const vector<A>& right) {
  if (left.size() == right.size()) {
    auto leftA = left.begin();
    auto rightA = right.begin();
    for (; leftA != left.end(); ++leftA, ++rightA) {
      if (!equals(*leftA, *rightA)) return false;
    }
    return true;
  }

  return false;
}

template <typename A, typename B>
vector<B> fmap(const vector<A>& input, function<B(A)> f) {
  vector<B> output;
  for (const A& a : input) {
    const B b = f(a);
    output.push_back(b);
  }
  return output;
}

#endif // FMap_HPP
