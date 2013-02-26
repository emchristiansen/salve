#ifndef CANBUILDFROM_HPP_
#define CANBUILDFROM_HPP_

#include "macros.hpp"

namespace salve {

using namespace std;

///////////////////////////////////

/**
 * Needed for operations on generic collections. Modeled on Scala's
 * CanBuildFrom:
 * http://www.scala-lang.org/api/current/index.html#scala.collection.generic.CanBuildFrom
 */
template<typename FromT, typename ElementT>
struct CanBuildFrom;

template<typename FromT, typename ElementT>
struct CanBuildFromDefinition {
  static bool verify() {
    typedef typename CanBuildFrom<FromT, ElementT>::ToT Trash;
    return true;
  }
};

/////////////////////////////

/**
 * Says can make a vector<ToElementT> from a vector<FromElementT>.
 */
template<typename FromElementT, typename ToElementT>
struct CanBuildFrom<vector<FromElementT>, ToElementT> {
  typedef vector<ToElementT> ToT;
};

verifyImplementation(CanBuildFrom, vector<int>, int)

} // namespace salve

#endif /* CANBUILDFROM_HPP_ */
