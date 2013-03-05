#include "gtest/gtest.h"

#include "salve/CanBuildFrom.hpp"

//#include <boost/utility.hpp>

#include <type_traits>
#include <stdexcept>

//using namespace boost;

///////////////////////////

using namespace salve;
using namespace std;


//template <>
//struct CanBeCastToImplementation<int> : CanBeCastToInterface<int> {
//  typedef double B;
//};
//
//template <>
//struct CanBeCastTo<char*> {
//  typedef string B;
//};

//CanBeCastTo<int>::B -> double

//template<typename FromT, typename ElementT>
//struct CanBuildFromImplementation;
//
////template<typename FromT, typename ElementT, typename _ToT>
////struct CanBuildFromImplementation;
//
//template<typename FromT,
//typename ElementT>
////template<
////typename ImplementationT>
//struct CanBuildFromInterface {
//  template<V>
//  typedef _ToT ToT;
//};
//
//template<typename FromT, typename ElementT,
//typename ImplementationT = typename enable_if<
//    is_base_of<CanBuildFromInterface<CanBuildFromImplementation<FromT, ElementT>, FromT, ElementT>,
//    CanBuildFromImplementation<FromT, ElementT>>::value,
//    CanBuildFromImplementation<FromT, ElementT>>::type>
//struct CBF : public ImplementationT {
//};
//
////template<>
////struct CanBuildFromImplementation<vector<int>, double> :
////  CanBuildFromInterface<vector<int>, double> {
////  typedef vector<double> ToT;
////};
//
//template<>
//struct CanBuildFromImplementation<vector<int>, double> :
//  CanBuildFromInterface<
//  CanBuildFromImplementation<vector<int>, double>, vector<int>, double> {
//  typedef vector<double> ToT;
//};

template<typename V>
using Foo = vector<V>;

TEST(TestCanBuildFrom, VectorIntToString) {
//  Stringy<int>().stringy(1);

  static_assert(is_same<CanBuildFrom<vector<int>, double>::ToT, vector<double>>::value, "");
}
