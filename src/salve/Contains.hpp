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
// TODO: Can I remove this "void"?
template<typename CollectionT>
struct Contains;

template<typename CollectionT>
struct ContainsDefinition {
  static bool verify() {
    typedef typename Contains<CollectionT>::ElementType Trash;
    return true;
  }
};

////////////////////////////////

/**
 * This says vector<E> contains type E.
 * TODO: There is redundancy here.
 */
template<typename ElementT>
struct Contains<vector<ElementT>> {
  // TODO: Rename
  typedef ElementT ElementType;
};

verifyImplementation(Contains, vector<int>)

} // namespace salve

#endif /* CONTAINS_HPP_ */
