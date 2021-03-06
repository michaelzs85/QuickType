#include "distance_types.hpp"
#include <iostream>
#include <ratio>
#include <vector>

#include <benchmark/benchmark.h>

static const std::vector<int> LHS{890338,  -87006,  103412,  993560,  -760846, 979473,  736662,  -40080,  -608879, 832025,  -521130, 901664,  993761,
                                  212548,  -676437, 327125,  338492,  276770,  -482302, -176962, -890814, 70450,   87050,   939187,  -295402, 540368,
                                  601812,  39895,   -378805, -585620, 602186,  147019,  400395,  -476016, 31097,   -305060, -806560, -108823, 256693,
                                  -208293, 371871,  37359,   217570,  106582,  94610,   635185,  796014,  -5509,   -764679, -259009, 113647,  709987,
                                  -514937, -192558, -426799, -103532, -88134,  -721002, 983180,  -950162, 347660,  -466240, -255647, -241835, 257665,
                                  -325084, 912845,  -679258, 808835,  293985,  -916606, 871926,  882875,  -899521, -430130, 678500,  -723008, -365660,
                                  979343,  606404,  -795137, -766733, -138703, -595107, -619153, -184672, 916650,  230573,  890508,  -285422, -442923,
                                  545441,  -943396, -420741, -25174,  -6582,   752740,  908082,  -600671, 126385};
static const std::vector<int> RHS{-457528, -918332, 661356,  647506,  920884,  104370,  -277106, -123979, -321010, 492309,  368467,  -551546, 849478,
                                  690877,  932072,  -640231, 529769,  838640,  -423040, -706270, 800895,  663348,  407755,  -580976, -289873, -867386,
                                  129745,  414263,  -545258, -564475, -307517, -743626, -994590, -151199, 612108,  -115854, 26237,   -595794, -249658,
                                  -687603, -532698, 885,     636744,  74416,   -697621, -259795, -949439, 871746,  256669,  922120,  -792536, -197634,
                                  -611127, -484853, 523454,  663676,  -74158,  -845509, 506576,  900536,  -608383, 374368,  45255,   -649423, 556418,
                                  -305232, 711687,  -105450, 677692,  623082,  -810463, 652546,  572164,  -926171, 30705,   443133,  -211763, 747747,
                                  -882384, 924555,  1686,    240956,  -528640, 126434,  304464,  -606416, 109494,  450268,  632030,  -319918, 902905,
                                  -577641, 664678,  -37507,  816674,  816362,  798672,  488849,  -351808, 692207};

static void addMeters(benchmark::State &state)
{
    for (auto _ : state)
    {
        for (size_t i = 0; i < LHS.size(); ++i)
        {
            int a = LHS[i];
            int b = RHS[i];
            benchmark::DoNotOptimize(((Meters(a) + Meters(b)).val == a + b));
        }
    }
}
BENCHMARK(addMeters);

static void addInts(benchmark::State &state)
{
    for (auto _ : state)
    {
        for (size_t i = 0; i < LHS.size(); ++i)
        {
            int a = LHS[i];
            int b = RHS[i];
            benchmark::DoNotOptimize(a + b == a + b);
        }
    }
}
BENCHMARK(addInts);

static void MultiplyMeters(benchmark::State &state)
{
    for (auto _ : state)
    {
        for (size_t i = 0; i < LHS.size(); ++i)
        {
            int a = LHS[i];
            int b = RHS[i];
            benchmark::DoNotOptimize(((Meters(a) * b).val == a * b));
        }
    }
}
BENCHMARK(MultiplyMeters);

static void MultiplyInts(benchmark::State &state)
{
    for (auto _ : state)
    {
        for (size_t i = 0; i < LHS.size(); ++i)
        {
            int a = LHS[i];
            int b = RHS[i];
            benchmark::DoNotOptimize((a * b == a * b));
        }
    }
}
BENCHMARK(MultiplyInts);

BENCHMARK_MAIN(); // NOLINT
