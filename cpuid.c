#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

int main ()
{
    CFMutableDictionaryRef matching;
    matching = IOServiceMatching("IOPlatformExpertDevice");
    io_service_t service;
    service = IOServiceGetMatchingService(kIOMasterPortDefault, matching);
    
    CFStringRef serialNumber;
    
    serialNumber = IORegistryEntryCreateCFProperty(service, CFSTR("IOPlatformSerialNumber"), kCFAllocatorDefault, 0);
    
    /* 
     * CFShow outputs to stderr, before the output, we first copy the CFStringRef to a char
     * so we can use printf to output to stdout
     */
    const char* str = CFStringGetCStringPtr(serialNumber,kCFStringEncodingMacRoman);
    printf("%s\n", str);

    //CFShow(serialNumber);
    return 0;
}
