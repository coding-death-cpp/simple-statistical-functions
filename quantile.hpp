#pragma once

namespace opar
{
    // I used an int Algorithm here, but I suppose that using a named struct may be easier to use
    template<typename InputType, int Algorithm = 7>
    struct quantile_stat{
        quantile_stat(const std::list<float>& probabilities){};
        quantile_stat(std::list<float> probabilities){};
        quantile_stat( std::initializer_list<float> probabilities ){};
    };

    //naive implementstion
    template <class InputType, int Algorithm = 7>
    struct quantile_return_type_impl { using type = InputType; };

    template <>
    struct quantile_return_type_impl<float>{ using type = double; };

    template <>
    struct quantile_return_type_impl<int> { using type = float; };


    template <class InputType>
    struct quantile_return_type { using type = std::list<typename quantile_return_type_impl<InputType>::type>; };

    template< typename InputType, bool IsSorted = false, int Algorithm = 7, typename OutputType = typename quantile_return_type<InputType>::type, typename Iter>
    OutputType quantile(Iter begin, Iter end, std::initializer_list<float> probabilities){ return {}; };

}