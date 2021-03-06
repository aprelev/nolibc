#include <helpers.h>
#include nolibc_header(assert.h)
#include nolibc_header(stdbool.h)

static inline bool
is_static_assert_defined(
    void
) {
    #if defined static_assert
        return true;
    #else
        return false;
    #endif
}

int main(
    void
) {
    if (!is_static_assert_defined()) {
        return 1;
    }

    return 0;
}
