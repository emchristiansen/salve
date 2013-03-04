#ifndef CONTAINS_HPP_
#define CONTAINS_HPP_

#include <type_traits>

#include "macros.hpp"

/////////////////////

namespace salve {

using namespace std;

/**
 * This says a collection CollectionT contains type ElementT.
 * For example, vector<int> contains type int.
 */
TYPECLASS(Contains, (CollectionT)) {
  // TODO
//  virtual typedef ElementT;
};

////////////////////////////////

/**
 * This says vector<E> contains type E.
 * TODO: There is redundancy here.
 */
template<typename _ElementT>
INSTANCE(Contains, (vector<_ElementT>)) {
  // TODO: Rename
  typedef _ElementT ElementT;
};

} // namespace salve

#endif /* CONTAINS_HPP_ */
