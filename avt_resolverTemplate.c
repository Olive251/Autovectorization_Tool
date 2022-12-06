#include <sys/auxv.h>

static void (*resolve_foo(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return foo_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return foo_SVE;
    else 
        return foo_NonSVE;
}

void *foo() __attribute__((ifunc("resolve_foo")));

int main() {
    foo();
}