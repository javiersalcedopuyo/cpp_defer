#pragma once

#include <functional>

namespace jsp
{
    class Deferrable
    {
    public:
        Deferrable() = delete;
        Deferrable( std::function<void()> _f ): f( _f ) {}
        ~Deferrable() { f(); }
    private:
        const std::function<void()> f;
    };
}

// Preprocessor magic so __COUNTER__ can be expanded correctly
#define JSP_CONCATENATE( l, r )         JSP_DO_CONCATENATE( l, r )
#define JSP_DO_CONCATENATE( l, r )      JSP_DO_CONCATENATE_2( l, r )
#define JSP_DO_CONCATENATE_2( l, r )    l##r

#define JSP_DEFER(f) const auto JSP_CONCATENATE(_deferred, __COUNTER__) = jsp::Deferrable( [&](){ f; } );
