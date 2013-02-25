#ifndef COMPARABLE_HPP_
#define COMPARABLE_HPP_

#include <typeinfo>

//////////////////////////////////

namespace salve {

using namespace std;

template<typename A>
struct Comparable;

template<typename A>
struct ComparableDefinition {
  static bool equals(const A& left, const A& right);

  static void verify() {
    typedef decltype(Comparable<A>::equals) EqualsT;
    const bool verifyEquals = is_same<decltype(equals), EqualsT>::value;
    static_assert(verifyEquals, "Comparable not properly implemented");
  }
};

//////////////////////////////////////

template<typename A, typename ComparableT = Comparable<A>>
bool equals(const A& left, const A& right) {
  return ComparableT::equals(left, right);
}

///////////////////////////////////////

template<>
struct Comparable<int> {
  static bool equals(const int& left, const int& right) {
    return left == right;
  }
};

template<typename ElementT>
struct Comparable<vector<ElementT>> {
  typedef Comparable<ElementT> ComparableT;

  static bool equals(const vector<ElementT>& left,
                     const vector<ElementT>& right) {
    if (left.size() != right.size()) return false;

    auto leftElement = left.begin();
    auto rightElement = right.begin();
    for (; leftElement != left.end(); ++leftElement, ++rightElement) {
      if (!ComparableT::equals(*leftElement, *rightElement)) return false;
    }
    return true;
  }
};

} // namespace salve

#endif /* COMPARABLE_HPP_ */
