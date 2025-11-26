#ifndef CPP_FMTLIB_CORE_HPP
#define CPP_FMTLIB_CORE_HPP

#include <fmt/args.h>
#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/compile.h>
#include <fmt/core.h>
#include <fmt/format-inl.h>
#include <fmt/format.h>
#include <fmt/os.h>
#include <fmt/ostream.h>
#include <fmt/printf.h>
#include <fmt/ranges.h>
#include <fmt/std.h>
#include <fmt/xchar.h>

namespace fmtlib {
    enum class ANSIColor {
        black          = 30,
        red            = 31,
        green          = 32,
        yellow         = 33,
        blue           = 34,
        magenta        = 35,
        cyan           = 36,
        white          = 37,
        bright_black   = 90,
        bright_red     = 91,
        bright_green   = 92,
        bright_yellow  = 93,
        bright_blue    = 94,
        bright_magenta = 95,
        bright_cyan    = 96,
        bright_white   = 97,
    };
} // namespace fmtlib


#endif // CPP_FMTLIB_CORE_HPP
