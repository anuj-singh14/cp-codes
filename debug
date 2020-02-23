#ifdef LOCAL
#include <C:\Programs\prettyprint.hpp>
template <typename ...Ts>
void trace1(Ts ...T){ ((cerr << "{ " << T << " }\n" ), ...); }
#define trace(...) cerr << "[" #__VA_ARGS__ << "] : " << '\n', trace1(__VA_ARGS__), cerr << '\n';
#else
#define trace(...)
#define trace1(...)
#endif
