#include "mean.hpp"
#include "stats.hpp"

#include <vector>
#include <list>
#include <set>

class MyNumeric
{
public:
    MyNumeric() : i(0){};
    MyNumeric(int num) : i(num){};

    MyNumeric operator+(const MyNumeric &other) const {
    MyNumeric result = *this;     
    result.i = i + other.i;       
    return result;              
  }

    MyNumeric operator/(const MyNumeric &other) const {
    MyNumeric result = *this;    
    result.i = i / other.i;        
    return result;         
  }
       
    int i;
};

int main() 
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    auto mean_value = opar::mean<int>(v.begin(), v.end());
    double dvalue = opar::mean<int, double>(v.begin(), v.end());

    std::set<float> l = {1,2,3,4,5,6,7,8,9,10};
    auto lmean_value = opar::mean<float>(l.begin(), l.end());
    float ldvalue = opar::mean<float, float>(l.begin(), l.end());

    std::list<MyNumeric> n = {1,2,3,4,5,6,7,8,9,10};
    auto nmean_value = opar::mean<MyNumeric>(n.begin(), n.end());
    MyNumeric ndvalue = opar::mean<MyNumeric, MyNumeric>(n.begin(), n.end());

    auto [mean0, quantiles0] = opar::calculate(v.begin(), v.end(), opar::mean_stat<int>{}, opar::quantile_stat<int>({0.1f, 0.5f, 0.9f}) );
    auto [mean1, quantiles1] = opar::calculate<true>(v.begin(), v.end(), opar::mean_stat<int>{}, opar::quantile_stat<int>({0.1f, 0.5f, 0.9f}) );
    auto [mean2, quantiles2] = opar::calculate<true, opar::mean_stat<int>, opar::quantile_stat<int>>(v.begin(), v.end(), {}, {0.1f, 0.5f, 0.9f});
    return 0;
}