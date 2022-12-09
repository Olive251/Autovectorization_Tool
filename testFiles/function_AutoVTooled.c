
#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}

#pragma GCC target "arch=armv8-a+sve2"
void *adjust_channels_SVE2(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=armv8-a+sve"
void *adjust_channels_SVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}

#pragma GCC target "arch=rmv8-a"
void *adjust_channels_NonSVE(unsigned char *image, int x_size, int y_size, 
        float red_factor, float green_factor, float blue_factor) {

        printf("Using adjust_channels() implementation #1 - Naive (autovectorizable)\n");
        
/*

        The image is stored in memory as pixels of 3 bytes, representing red/green/blue values.
        Each of these values is multiplied by the corresponding adjustment factor, with 
        saturation, and then stored back to the original memory location.
        
        This simple implementation causes int to float to int conversions.
        
*/

        for (int i = 0; i < x_size * y_size * 3; i += 3) {
                image[i]   = MIN((float)image[i]   * red_factor,   255);
                image[i+1] = MIN((float)image[i+1] * blue_factor,  255);
                image[i+2] = MIN((float)image[i+2] * green_factor, 255);
        }
}


#include <sys/auxv.h>

static void (*resolve_adjust_channels(void)) {
    long hwcaps = getauxval(AT_HWCAP);
    long hwcaps2 = getauxval(AT_HWCAP2);

    if (hwcaps2 & HWCAP2_SVE2)
        return adjust_channels_SVE2;
    else if (hwcaps & HWCAP_SVE)
        return adjust_channels_SVE;
    else 
        return adjust_channels_NonSVE;
}

void *adjust_channels() __attribute__((ifunc("resolve_adjust_channels")));

int main() {
    adjust_channels();
}
