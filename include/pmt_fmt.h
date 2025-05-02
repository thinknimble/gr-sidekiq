#pragma once

#include <fmt/core.h>
#include <pmt/pmt.h>
#include <memory>

// Add formatter for shared_ptr<pmt::pmt_base>
template <>
struct fmt::formatter<std::shared_ptr<pmt::pmt_base>> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const std::shared_ptr<pmt::pmt_base>& ptr, FormatContext& ctx) -> decltype(ctx.out()) {
        if (!ptr)
            return fmt::format_to(ctx.out(), "PMT(nullptr)");
        else
            return fmt::format_to(ctx.out(), "PMT({})", pmt::write_string(ptr));
    }
};