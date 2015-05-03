#include "video.h"
#include "utils.h"
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif

void kernel_main()
{
    Video video;
    video.clean();
    video.print("Hello world kernel!!");
}
