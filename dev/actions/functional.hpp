#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP
#define REQUIRES(...) class=std::enable_if_t<(__VA_ARGS__)>

namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    template<class F>
    struct pipe_closure : F {
        template<class... Xs>
        pipe_closure(Xs&&... xs) : F(std::forward<Xs>(xs)...)
        {}
    };
    template<class T, class F>
    decltype(auto) operator|(T&& x, const pipe_closure<F>& p)
    {
        return p(std::forward<T>(x));
    }
  }
  /// @}
}

#endif