#include <random>
#include <set>
#include <stdexcept>

#include <lozti/core/block_factory.hpp>

#include <lozti/core/algorithm.hpp>

using lozti::block_factory;

using lozti::block;
using lozti::flip_lr;

block_factory::block_factory()
    : blocks(make_blocks())
{
}

block::iterator
block_factory::make_random() const
{
    if (blocks.size() <= 0)
        throw std::runtime_error("we shouldn't be here");

    static std::random_device device;
    static std::mt19937 generator(device());

    auto it = blocks.begin();

    std::uniform_int_distribution<> distribution(0, std::distance(it, blocks.end()) - 1);
    std::advance(it, distribution(generator));

    return it->iterate();
}

block_factory::size_type
block_factory::size() const
{
    return blocks.size();
}

block_factory::container_type::const_iterator
block_factory::begin() const
{
    return blocks.begin();
}

block_factory::container_type::const_iterator
block_factory::end() const
{
    return blocks.end();
}

block::matrix_type
block_factory::draw_l()
{
    block::matrix_type::container_type data({
            1, 0,
            1, 0,
            1, 1,
            });
    block::matrix_type::size_type w = 2;
    block::matrix_type::size_type h = data.size() / w;
    return block::matrix_type(w, h, std::move(data));
}

block::matrix_type
block_factory::draw_o()
{
    block::matrix_type::container_type data({
            1, 1,
            1, 1,
            });
    block::matrix_type::size_type w = 2;
    block::matrix_type::size_type h = data.size() / w;
    return block::matrix_type(w, h, std::move(data));
}

block::matrix_type
block_factory::draw_z()
{
    block::matrix_type::container_type data({
            1, 1, 0,
            0, 1, 1,
            });
    block::matrix_type::size_type w = 3;
    block::matrix_type::size_type h = data.size() / w;
    return block::matrix_type(w, h, std::move(data));
}

block::matrix_type
block_factory::draw_t()
{
    block::matrix_type::container_type data({
            1, 1, 1,
            0, 1, 0,
            });
    block::matrix_type::size_type w = 3;
    block::matrix_type::size_type h = data.size() / w;
    return block::matrix_type(w, h, std::move(data));
}

block::matrix_type
block_factory::draw_i()
{
    block::matrix_type::container_type data({
            1,
            1,
            1,
            1,
            });
    block::matrix_type::size_type w = 1;
    block::matrix_type::size_type h = data.size() / w;
    return block::matrix_type(w, h, std::move(data));
}

std::vector<block>
block_factory::make_blocks()
{
    std::set<block> unique_blocks;

    std::vector<block::matrix_type> matrices({
            draw_l(),
            draw_o(),
            draw_z(),
            draw_t(),
            draw_i(),
            });

    for (auto &matrix : matrices) {
        unique_blocks.insert(block(matrix));
        flip_lr(matrix);
        unique_blocks.insert(block(std::move(matrix)));
    }

    std::vector<block> ret;
    std::copy(unique_blocks.begin(), unique_blocks.end(), std::back_inserter(ret));

    return ret;
}

// vim:set sw=4 ts=4 et tw=120:
