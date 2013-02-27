#ifndef COMPARABLE_HPP_
#define COMPARABLE_HPP_

#include <boost/optional.hpp>

#include <typeinfo>
#include "macros.hpp"

//////////////////////////////////

namespace salve {

using namespace std;
using boost::optional;

template<typename A>
struct Comparable;

template<typename A>
struct ComparableDefinition {
  static bool equals(const A& left, const A& right);

  static bool verify() {
    verifyMethod(Comparable, equals, A)
    return true;
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

verifyImplementation(Comparable, int)

//////////////////////////////////////

template<typename ElementT>
struct Comparable<vector<ElementT>> {
  typedef Comparable<ElementT> ComparableT;

  static bool equals(const vector<ElementT>& left,
                     const vector<ElementT>& right) {
    if (left.size() != right.size())
      return false;

    auto leftElement = left.begin();
    auto rightElement = right.begin();
    for (; leftElement != left.end(); ++leftElement, ++rightElement) {
      if (!ComparableT::equals(*leftElement, *rightElement))
        return false;
    }
    return true;
  }
};

verifyImplementation(Comparable, vector<int>)

//////////////////////////////////

template<typename ElementT>
struct Comparable<optional<ElementT>> {
  typedef Comparable<ElementT> ComparableT;

  static bool equals(const optional<ElementT>& left,
                     const optional<ElementT>& right) {
    // They must have the same initialization status.
    if (left.is_initialized() != right.is_initialized())
      return false;
    // If they're both empty, they're equal.
    else if (!left.is_initialized())
      return true;
    // They're both initialized, so compare their elements.
    else
      return left.get() == right.get();
  }
};

verifyImplementation(Comparable, optional<int>)

}  // namespace salve

#endif /* COMPARABLE_HPP_ */
