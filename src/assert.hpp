// Redefine assert after including headers. Release builds may undefine the assert macro and result
// in -Wunused-variable warnings.
#if defined(NDEBUG) || !defined(assert)
#undef assert
#define assert(stmt)                                                                         \
    do {                                                                                     \
        if (!(stmt)) {                                                                       \
            std::cerr << "Assert on line " << __LINE__ << " failed: " << #stmt << std::endl; \
            abort();                                                                         \
        }                                                                                    \
    } while (0)
#endif
