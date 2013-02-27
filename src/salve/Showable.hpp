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
template<typename A>
struct Showable;

template<typename A>
struct ShowableDefinition {
  static string show(const A& a);

  static bool verify() {
    verifyMethod(Showable, show, A)
    return true;
  }
};

////////////////////////////

/**
 * Convenience function for Showable.
 */
template<typename A, typename ShowableT = Showable<A>>
string show(const A& a) {
  return ShowableT::show(a);
}

/////////////////////////////

/**
 * Says a string is Showable.
 */
template<>
struct Showable<string> {
  static string show(const string& a) {
    return a;
  }
};

verifyImplementation(Showable, string)

////////////////////////////////////

/**
 * Says an int is Showable.
 */
template<>
struct Showable<int> {
  static string show(const int& a) {
    stringstream buffer;
    buffer << a;
    return buffer.str();
  }
};

verifyImplementation(Showable, int)

////////////////////////////////////

/**
 * Says a double is Showable.
 */
// TODO: Add a way to control precision in the output.
template<>
struct Showable<double> {
  static string show(const double& a) {
    stringstream buffer;
    buffer << a;
    return buffer.str();
  }
};

verifyImplementation(Showable, double)

////////////////////////////////////////

/**
 * Says a vector of Showables is Showable.
 */
// "default template arguments may not be used in partial specializations"
template<typename ElementT>
struct Showable<vector<ElementT>> {
  typedef Showable<ElementT> ShowableT;

  static string show(const vector<ElementT>& a) {
    stringstream buffer;
    buffer << "[";
    for (int index : range<int>(0, a.size() - 1)) {
      buffer << ShowableT::show(a.at(index)) << ", ";
    }
    // TODO: Replace with last.
    if (a.size() > 0)
      buffer << ShowableT::show(a.at(a.size() - 1));
//    buffer << ShowableT::show(last(a));
    buffer << "]";

    return buffer.str();
  }
};

verifyImplementation(Showable, vector<int>)

}  // namespace salve

#endif /* TYPECLASSES_HPP_ */
