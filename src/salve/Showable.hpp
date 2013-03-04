#ifndef TYPECLASSES_HPP_
#define TYPECLASSES_HPP_

#include "collections.hpp"
#include "macros.hpp"

namespace salve {

using namespace std;

/////////////////////////////////

/**
 * Anything which can be displayed as a string.
 */
TYPECLASS(Showable, (A)) {
  virtual string show(const A& a) = 0;
};

////////////////////////////

/**
 * Convenience function for Showable.
 */
template<typename A, typename ShowableT = Showable<A>>
string show(const A& a) {
  return ShowableT().show(a);
}

/////////////////////////////

/**
 * Says a string is Showable.
 */
template<>
INSTANCE(Showable, (string)) {
  string show(const string& a) override {
    return a;
  }
};

////////////////////////////////////

/**
 * Says an int is Showable.
 */
template<>
INSTANCE(Showable, (int)) {
  string show(const int& a) override {
    stringstream buffer;
    buffer << a;
    return buffer.str();
  }
};

////////////////////////////////////

/**
 * Says a double is Showable.
 */
// TODO: Add a way to control precision in the output.
template<>
INSTANCE(Showable, (double)) {
  string show(const double& a) override {
    stringstream buffer;
    buffer << a;
    return buffer.str();
  }
};

////////////////////////////////////////

/**
 * Says a vector of Showables is Showable.
 */
// "default template arguments may not be used in partial specializations"
template<typename ElementT>
INSTANCE(Showable, (vector<ElementT>)) {
  typedef Showable<ElementT> ShowableT;

  string show(const vector<ElementT>& a) override {
    stringstream buffer;
    buffer << "[";
    for (int index : range<int>(0, a.size() - 1)) {
      buffer << ShowableT().show(a.at(index)) << ", ";
    }
    // TODO: Replace with last.
    if (a.size() > 0)
      buffer << ShowableT().show(a.at(a.size() - 1));
//    buffer << ShowableT::show(last(a));
    buffer << "]";

    return buffer.str();
  }
};

}  // namespace salve

#endif /* TYPECLASSES_HPP_ */
