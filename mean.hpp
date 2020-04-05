#pragma once

#include <type_traits>
#include <iterator>
#include <numeric>

namespace opar {

       //naive implementstion
        template <class InputType>
        struct mean_return_type_impl{ using type = InputType; };

        template <>
        struct mean_return_type_impl<float>{ using type = double; };


        template <>
        struct mean_return_type_impl<int> { using type = float; };


        template <class InputType>
        struct mean_return_type { using type = typename mean_return_type_impl<InputType>::type;};

        template<typename InputType, typename ReturnType = typename mean_return_type<InputType>::type>
        struct mean_stat{};


    template <class InputType, class ReturnType = typename mean_return_type<InputType>::type, class InputIt>
    //... requires ...
    constexpr ReturnType mean(InputIt begin, InputIt end)
    {
        //very naive implementation
        auto cast_and_add = [](ReturnType a, InputType b){return std::move(a) + ReturnType(b);};
        ReturnType sum = std::accumulate(begin, end, ReturnType(0), cast_and_add);
        ReturnType n = std::distance(begin, end);
        ReturnType mean = sum/n;
        return mean;
    }

    template <class InputType, class ReturnType = typename mean_return_type<InputType>::type, class InputIt>
    //... requires ...
    constexpr ReturnType mean(InputIt begin, InputIt end, mean_stat<InputType, ReturnType> params)
    {
        //naive implementation
        return mean<InputType,ReturnType,InputIt>(begin, end) ;
    }

}
