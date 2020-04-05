#pragma once

#include <tuple>
#include <type_traits>
#include <list>

#include "mean.hpp"
#include "quantile.hpp"

namespace opar
{
    template<typename Stat>
    struct stat_result { };

    template<typename T>
    struct stat_result<mean_stat<T>> { using type = typename mean_return_type<T>::type; };

    template< typename T>
    struct stat_result<quantile_stat<T>> { using type = typename quantile_return_type<T>::type; };


    // tuple-like stats type
    // naive version - tuple itself
    template<typename... Stats>
    using stats = std::tuple< typename stat_result<Stats>::type...>;

    template< bool IsSorted = false, class... Stats, class Iter>
    // ... requres ...
    stats<Stats...> calculate(Iter begin, Iter end, Stats... stats){return {};}

}