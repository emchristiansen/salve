#ifndef COMPARABLE_HPP_
#define COMPARABLE_HPP_

#include <typeinfo>

#include <boost/optional.hpp>

#include "macros.hpp"

//////////////////////////////////

namespace salve {

using namespace std;
using boost::optional;

TYPECLASS(Comparable, (A)) {
  virtual bool equals(const A& left, const A& right) = 0;
};

//////////////////////////////////////

EXPOSE(Comparable, (A), equals, (A)(A))

///////////////////////////////////////

template<>
INSTANCE(Comparable, (int)) {
  bool equals(const int& left, const int& right) override {
    return left == right;
  }
};

//////////////////////////////////////

template<typename ElementT>
INSTANCE(Comparable, (vector<ElementT>)) {
  typedef Comparable<ElementT> ComparableT;

  bool equals(const vector<ElementT>& left, const vector<ElementT>& right)
      override {
    if (left.size() != right.size())
      return false;

    auto leftElement = left.begin();
    auto rightElement = right.begin();
    for (; leftElement != left.end(); ++leftElement, ++rightElement) {
      if (!ComparableT().equals(*leftElement, *rightElement))
        return false;
    }
    return true;
  }
};

//////////////////////////////////

template<typename ElementT>
INSTANCE(Comparable, (optional<ElementT>)) {
  typedef Comparable<ElementT> ComparableT;

  bool equals(const optional<ElementT>& left,
                     const optional<ElementT>& right) override {
    // They must have the same initialization status.
    if (left.is_initialized() != right.is_initialized())
      return false;
    // If they're both empty, they're equal.
    else if (!left.is_initialized())
      return true;
    // They're both initialized, so compare their elements.
    else
      return ComparableT().equals(left.get(), right.get());
  }
};

}  // namespace salve

#endif /* COMPARABLE_HPP_ */
