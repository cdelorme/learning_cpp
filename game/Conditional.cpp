/**
 * Conditional.cpp
 *
 * author: Casey DeLorme <cdelorme@gmail.com>
 * date: 2014-6-15
 * link: http://stackoverflow.com/questions/516200/relative-paths-not-working-in-xcode-c
 *
 * description:
 *  A feeble attempt to externalize conditional logic
 *  from the core of my code.
 *
 */

// Apple/OS X specific code for resources path in app bundles
#ifdef __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif

// local
#include "Conditional.h"

// Assure our directory is relative to data so we can access it (primarily OSX)
void Conditional::paths() {

// ----------------------------------------------------------------------------
// This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
#ifdef __APPLE__
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX);
    CFRelease(resourcesURL);
    chdir(path);
#endif

};
