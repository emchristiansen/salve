#pragma once

#include "macros.hpp"

namespace salve {

using namespace std;

///////////////////////////////////

/**
 * Needed for operations on generic collections. Modeled on Scala's
 * CanBuildFrom:
 * http://www.scala-lang.org/api/current/index.html#scala.collection.generic.CanBuildFrom
 */
TYPECLASS(CanBuildFrom, (FromT)(ElementT)) {
  // TODO: Find a way to enforce this constraint. See:
  // http://stackoverflow.com/questions/15209663/c-pure-virtual-type
//  virtual typedef ToT;
};

/////////////////////////////

/**
 * Says can make a vector<ToElementT> from a vector<FromElementT>.
 */
template<typename FromElementT, typename ToElementT>
INSTANCE(CanBuildFrom, (vector<FromElementT>)(ToElementT)) {
  typedef vector<ToElementT> ToT;
};

} // namespace salve

