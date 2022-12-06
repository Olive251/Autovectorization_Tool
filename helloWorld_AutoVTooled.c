
void *helloWorld_SVE2() {
    printf("Hello World");
}

void *helloWorld_SVE() {
    printf("Hello World");
}

void *helloWorld_NonSVE() {
    printf("Hello World");
}

#include <sys/auxv.h>

static void (*resolve_helloWorld(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return helloWorld_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return helloWorld_SVE;
    else 
        return helloWorld_NonSVE;
}

void *helloWorld() __attribute__((ifunc("resolve_helloWorld")));

int main() {
    helloWorld();
}
