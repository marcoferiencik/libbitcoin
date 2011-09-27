#ifndef LIBBITCOIN_CONSTANTS_H
#define LIBBITCOIN_CONSTANTS_H

#include <cstdint>

#include <bitcoin/util/big_number.hpp>

namespace libbitcoin {

constexpr uint64_t block_reward = 50;

constexpr uint32_t magic_value = 0xd9b4bef9;

constexpr uint64_t max_money_recursive(uint64_t current)
{
    return (current > 0) ? 
        current + max_money_recursive(current >> 1) : 0;
}

constexpr uint64_t coin_price(uint64_t value=1)
{
    return value * 100000000;
}

constexpr uint64_t max_money()
{
    // 210000 ~ 4 years / 10 minutes
    return 210000 * max_money_recursive(coin_price(block_reward));
}

const hash_digest null_hash{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

constexpr uint32_t max_bits = 0x1d00ffff;
big_number max_target();

// Every two weeks we readjust target
constexpr uint64_t target_timespan = 14 * 24 * 60 * 60;
// Aim for blocks every 10 mins
constexpr uint64_t target_spacing = 10 * 60;
// Two weeks worth of blocks = readjust interval = 2016
constexpr uint64_t readjustment_interval = target_timespan / target_spacing;

} // libbitcoin

#endif
