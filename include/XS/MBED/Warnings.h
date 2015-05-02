/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*******************************************************************************/

#ifndef XS_MBED_WARNINGS_H
#define XS_MBED_WARNINGS_H

#ifndef __GNUC__
#error "XS::MBED requires GCC as a compiler"
#endif

#pragma GCC diagnostic error "-pedantic-errors"
#pragma GCC diagnostic error "-pedantic"
#pragma GCC diagnostic error "-Waddress"
#pragma GCC diagnostic error "-Wall"
#pragma GCC diagnostic error "-Warray-bounds"
#pragma GCC diagnostic error "-Wbad-function-cast"
#pragma GCC diagnostic error "-Wc++-compat"
#pragma GCC diagnostic error "-Wc++11-compat"
#pragma GCC diagnostic error "-Wcast-align"
#pragma GCC diagnostic error "-Wcast-qual"
#pragma GCC diagnostic error "-Wchar-subscripts"
#pragma GCC diagnostic error "-Wclobbered"
#pragma GCC diagnostic error "-Wcomment"
#pragma GCC diagnostic error "-Wconditionally-supported"
#pragma GCC diagnostic error "-Wconversion"
#pragma GCC diagnostic error "-Wdate-time"
#pragma GCC diagnostic error "-Wdeclaration-after-statement"
#pragma GCC diagnostic error "-Wdelete-incomplete"
#pragma GCC diagnostic error "-Wdisabled-optimization"
#pragma GCC diagnostic error "-Wdouble-promotion"
#pragma GCC diagnostic error "-Wempty-body"
#pragma GCC diagnostic error "-Wenum-compare"
#pragma GCC diagnostic error "-Werror"
#pragma GCC diagnostic error "-Wextra"
#pragma GCC diagnostic error "-Wfatal-errors"
#pragma GCC diagnostic error "-Wfloat-conversion"
#pragma GCC diagnostic error "-Wfloat-equal"
#pragma GCC diagnostic error "-Wformat-nonliteral"
#pragma GCC diagnostic error "-Wformat-security"
#pragma GCC diagnostic error "-Wformat-y2k"
#pragma GCC diagnostic error "-Wformat"
#pragma GCC diagnostic error "-Wignored-qualifiers"
#pragma GCC diagnostic error "-Wimplicit-function-declaration"
#pragma GCC diagnostic error "-Wimplicit-int"
#pragma GCC diagnostic error "-Wimplicit"
#pragma GCC diagnostic error "-Winit-self"
#pragma GCC diagnostic error "-Winline"
#pragma GCC diagnostic error "-Winvalid-pch"
#pragma GCC diagnostic error "-Wjump-misses-init"
#pragma GCC diagnostic error "-Wlogical-op"
#pragma GCC diagnostic error "-Wlong-long"
#pragma GCC diagnostic error "-Wmain"
#pragma GCC diagnostic error "-Wmaybe-uninitialized"
#pragma GCC diagnostic error "-Wmissing-braces"
#pragma GCC diagnostic error "-Wmissing-declarations"
#pragma GCC diagnostic error "-Wmissing-field-initializers"
#pragma GCC diagnostic error "-Wmissing-format-attribute"
#pragma GCC diagnostic error "-Wmissing-include-dirs"
#pragma GCC diagnostic error "-Wmissing-parameter-type"
#pragma GCC diagnostic error "-Wmissing-prototypes"
#pragma GCC diagnostic error "-Wnested-externs"
#pragma GCC diagnostic error "-Wnonnull"
#pragma GCC diagnostic error "-Wold-style-declaration"
#pragma GCC diagnostic error "-Wold-style-definition"
#pragma GCC diagnostic error "-Wopenmp-simd"
#pragma GCC diagnostic error "-Woverlength-strings"
#pragma GCC diagnostic error "-Woverride-init"
#pragma GCC diagnostic error "-Wpacked-bitfield-compat"
#pragma GCC diagnostic error "-Wpacked"
#pragma GCC diagnostic error "-Wpadded"
#pragma GCC diagnostic error "-Wparentheses"
#pragma GCC diagnostic error "-Wpointer-arith"
#pragma GCC diagnostic error "-Wpointer-sign"
#pragma GCC diagnostic error "-Wredundant-decls"
#pragma GCC diagnostic error "-Wreturn-type"
#pragma GCC diagnostic error "-Wsequence-point"
#pragma GCC diagnostic error "-Wshadow"
#pragma GCC diagnostic error "-Wsign-compare"
#pragma GCC diagnostic error "-Wsign-conversion"
#pragma GCC diagnostic error "-Wsizeof-pointer-memaccess"
#pragma GCC diagnostic error "-Wstack-protector"
#pragma GCC diagnostic error "-Wstrict-aliasing"
#pragma GCC diagnostic error "-Wstrict-overflow"
#pragma GCC diagnostic error "-Wstrict-prototypes"
#pragma GCC diagnostic error "-Wsuggest-attribute=format"
#pragma GCC diagnostic error "-Wsuggest-attribute=noreturn"
#pragma GCC diagnostic error "-Wswitch-default"
#pragma GCC diagnostic error "-Wswitch-enum"
#pragma GCC diagnostic error "-Wswitch"
#pragma GCC diagnostic error "-Wsync-nand"
#pragma GCC diagnostic error "-Wsystem-headers"
#pragma GCC diagnostic error "-Wtraditional-conversion"
#pragma GCC diagnostic error "-Wtraditional"
#pragma GCC diagnostic error "-Wtrampolines"
#pragma GCC diagnostic error "-Wtrigraphs"
#pragma GCC diagnostic error "-Wtype-limits"
#pragma GCC diagnostic error "-Wundef"
#pragma GCC diagnostic error "-Wuninitialized"
#pragma GCC diagnostic error "-Wunknown-pragmas"
#pragma GCC diagnostic error "-Wunsafe-loop-optimizations"
#pragma GCC diagnostic error "-Wunsuffixed-float-constants"
#pragma GCC diagnostic error "-Wunused-but-set-parameter"
#pragma GCC diagnostic error "-Wunused-but-set-variable"
#pragma GCC diagnostic error "-Wunused-function"
#pragma GCC diagnostic error "-Wunused-label"
#pragma GCC diagnostic error "-Wunused-local-typedefs"
#pragma GCC diagnostic error "-Wunused-parameter"
#pragma GCC diagnostic error "-Wunused-value"
#pragma GCC diagnostic error "-Wunused-variable"
#pragma GCC diagnostic error "-Wunused"
#pragma GCC diagnostic error "-Wuseless-cast"
#pragma GCC diagnostic error "-Wvarargs"
#pragma GCC diagnostic error "-Wvariadic-macros"
#pragma GCC diagnostic error "-Wvector-operation-performance"
#pragma GCC diagnostic error "-Wvla"
#pragma GCC diagnostic error "-Wvolatile-register-var"
#pragma GCC diagnostic error "-Wwrite-strings"

/*
#pragma GCC diagnostic error "-Waggregate-return"
#pragma GCC diagnostic error "-Wzero-as-null-pointer-constant"
#pragma GCC diagnostic error "-Wsuggest-attribute=const"
#pragma GCC diagnostic error "-Wsuggest-attribute=pure"
*/
#endif /* XS_MBED_WARNINGS_H */
