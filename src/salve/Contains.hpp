#ifndef CONTAINS_HPP_
#define CONTAINS_HPP_

#include <type_traits>

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
  static void verify() {
    typedef typename Contains<CollectionT>::ElementType Trash;
  }
};

/**
 * This says vector<E> contains type E.
 * TODO: There is redundancy here.
 */
template<typename ElementT>
struct Contains<vector<ElementT>> {
  // TODO: Rename
  typedef ElementT ElementType;
};

} // namespace salve

#endif /* CONTAINS_HPP_ */
