#ifndef NETWORK_MUTATIONAL_SPECTRUM_H
#define NETWORK_MUTATIONAL_SPECTRUM_H
#include<vector>
#include <iterator>
#include <algorithm>
#include"network.h"
#include "histogram.h"
namespace spectrum {

using node = std::vector<histogram>;
using layer = std::vector<node>;
using net = std::vector<layer>;

using layer_biases = std::vector<histogram>;
using net_biases = std::vector<layer_biases>;

struct network_spectrum{
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(network_spectrum,
                                   m_outputs_of_mutated_weights,
                                   m_outputs_of_mutated_biases);

    ///The ouput of the netwrok for each mutatation on each weight
    net m_outputs_of_mutated_weights;

    ///The ouput of the netwrok for each mutatation on each bias
    net_biases m_outputs_of_mutated_biases;
};


#include <vector>
#include <utility>
#include <iterator>

///From: https://stackoverflow.com/questions/17294629/merging-flattening-sub-vectors-into-a-single-vector-c-converting-2d-to-1d?noredirect=1&lq=1
template <template<typename...> class R=std::vector,
          typename Top,
          typename Sub = typename Top::value_type>
   R<typename Sub::value_type> flatten(Top const& all)
{
    using std::begin;
    using std::end;

    R<typename Sub::value_type> accum;

    for(auto& sub : all)
        std::copy(begin(sub), end(sub), std::inserter(accum, end(accum)));

    return accum;
}

   std::vector<double> extract_first_outputs_weights(const std::vector<std::vector<std::vector<std::vector<std::vector<double>>>>> &spectrum_weights);

   std::vector<double> extract_first_outputs_biases(const std::vector<std::vector<std::vector<std::vector<double>>>> &spectrum_biases);


}
#endif // NETWORK_MUTATIONAL_SPECTRUM_H
