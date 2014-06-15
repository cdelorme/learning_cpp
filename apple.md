
# apple

I want to keep tabs on things that I have to do that are platform specific, so I can work around them for cross-platform development going forward.

### resources path for app bundles

To get to resources from an app bundle you have to add these conditional lines to your main code:

    #ifdef __APPLE__
    #include "CoreFoundation/CoreFoundation.h"
    #endif

    // ----------------------------------------------------------------------------
    // This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
    #ifdef __APPLE__
        CFBundleRef mainBundle = CFBundleGetMainBundle();
        CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
        char path[PATH_MAX];
        if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
        {
            // error!
        }
        CFRelease(resourcesURL);

        chdir(path);
        std::cout << "Current Path: " << path << std::endl;
    #endif

_I noticed the `chdir` method which should drop me in the "right place", but I have not yet tested it._

If it does work as intended, I should be able to immediately begin referencing the paths inside "Resources" to reach project data files.
