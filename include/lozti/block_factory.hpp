#if !defined(_LOZTI_BLOCK_FACTORY_HPP_)
#define _LOZTI_BLOCK_FACTORY_HPP_

#include <utility>
#include <vector>

#include <lozti/block.hpp>

namespace lozti {

class
block_factory
{
public:
    typedef std::vector<block> container_type;
    typedef container_type::size_type size_type;

private:
    const container_type blocks;

public:
    block_factory();

    block::iterator make_random() const;

    size_type size() const;
    container_type::const_iterator begin() const;
    container_type::const_iterator end() const;

private:
    static block::matrix_type draw_l();
    static block::matrix_type draw_o();
    static block::matrix_type draw_z();
    static block::matrix_type draw_t();
    static block::matrix_type draw_i();

    static std::vector<block> make_blocks();
};

}

#endif // !defined(_LOZTI_BLOCK_FACTORY_HPP_)

// vim:set sw=4 ts=4 et tw=120:
