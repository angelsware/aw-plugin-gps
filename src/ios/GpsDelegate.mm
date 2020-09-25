#import "GpsDelegate.h"
#import <gps/aw_sensorlistener.h>

@implementation GpsDelegate

+(void) onRequestGpsPermissionResult:(int64_t) id granted:(bool) granted {
    reinterpret_cast<Gps::ISensorListener*>(id)->onRequestGpsPermissionResult(granted);
}

+(void) onGpsLocation:(int64_t) id latitude:(double) latitude longitude:(double) longitude timeSinceLastUpdate:(int64_t) timeSinceLastUpdate accuracy:(float) accuracy {
    reinterpret_cast<Gps::ISensorListener*>(id)->onGpsLocation(latitude, longitude, timeSinceLastUpdate, accuracy);
}

@end
