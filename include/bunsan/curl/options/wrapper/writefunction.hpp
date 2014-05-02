#pragma once

#include <bunsan/curl/options/traits.hpp>
#include <bunsan/curl/options/wrapper/basic_function.hpp>

#include <curl/curl.h>

#include <functional>
#include <utility>

namespace bunsan{namespace curl{namespace options{namespace wrapper
{
    struct writefunction_traits
    {
        typedef basic_function<writefunction_traits> wrapper;

        typedef std::function<
            std::size_t (char *ptr, size_t size, size_t nmemb)
        > function_type;

        static inline std::size_t static_call(
            char *ptr, size_t size, size_t nmemb, void *userdata)
        {
            const auto this_ = static_cast<const wrapper *>(userdata);
            return this_->call(ptr, size, nmemb);
        }
    };

    typedef writefunction_traits::wrapper writefunction;
}}}}