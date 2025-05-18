#pragma once
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> generateRandomArray(size_t size, int min = -50, int max = 100)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    std::vector<int> arr(size);
    std::generate(arr.begin(), arr.end(), [&]()
                  { return dist(gen); });

    return arr;
}

std::vector<int> copyArray(const std::vector<int> &source)
{
    std::vector<int> result;
    std::copy(source.begin(), source.end(), std::back_inserter(result));
    return result;
}

std::vector<int> copyIfPositive(const std::vector<int> &source)
{
    std::vector<int> result;
    std::copy_if(source.begin(), source.end(), std::back_inserter(result), [](int x)
                 { return x > 0; });
    return result;
}
