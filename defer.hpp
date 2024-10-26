#pragma once

namespace jsp
{
    template<typename Lambda>
    class Deferrable
    {
    public:
        Deferrable() = delete;
        Deferrable( Lambda  _f ): f( _f ) {}
        ~Deferrable() { f(); }
    private:
        const Lambda f;
    };
}

// Preprocessor magic so __COUNTER__ can be expanded correctly
#define JSP_CONCATENATE( l, r )         JSP_DO_CONCATENATE( l, r )
#define JSP_DO_CONCATENATE( l, r )      JSP_DO_CONCATENATE_2( l, r )
#define JSP_DO_CONCATENATE_2( l, r )    l##r

#define JSP_DEFER(f) const auto JSP_CONCATENATE(_deferred, __COUNTER__) = jsp::Deferrable( [&](){ f; } );
