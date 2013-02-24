#ifndef TYPECLASSES_HPP_
#define TYPECLASSES_HPP_

/////////////////

/**
 * Anything which can be displayed as a string.
 */
template <typename A>
struct Showable {
  static string show(const A& a);
};

/**
 * Convenience function for Showable.
 */
template <typename A, typename S = Showable<A>>
string show(const A& a) {
  return S::show(a);
}

template<>
struct Showable<string> {
  static string show(const string& a) {
    return a;
  }
};

template<>
struct Showable<int> {
  static string show(const int& a) {
    stringstream buffer;
    buffer << a;
    return buffer.str();
  }
};

// TODO: Add a way to control precision in the output.
template<>
struct Showable<double> {
  static string show(const double& a) {
    stringstream buffer;
    buffer << a;
    return buffer.str();
  }
};

// "default template arguments may not be used in partial specializations"
template <typename E>
struct Showable<vector<E>> {
  typedef Showable<E> S;

  static string show(const vector<E>& a) {
    stringstream buffer;
    buffer << "[";
    // TODO: Replace with Range.
    for (int index = 0; index < a.size() - 1; ++index) {
      buffer << S::show(a.at(index)) << ", ";
    }
    // TODO: Replace with last.
    buffer << S::show(a.at(a.size() - 1));
    buffer << "]";

    return buffer.str();
  }
};

#endif /* TYPECLASSES_HPP_ */
