#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

int main (int argc, const char * argv[])
{
    CFMutableDictionaryRef matching;
    matching = IOServiceMatching("IOPlatformExpertDevice");
    io_service_t service;
    service = IOServiceGetMatchingService(kIOMasterPortDefault, matching);
    
    CFStringRef serialNumber;
    
    serialNumber = IORegistryEntryCreateCFProperty(service, CFSTR("IOPlatformSerialNumber"), kCFAllocatorDefault, 0);
    
    CFShow(newText);
    return 0;
}