#include <helpers.h>
#include nolibc_header(stdlib.h)

static inline void
check_for_default_abort(
    void
) {
    abort();
}

int
main(
    void
) {
    return 0;
}
