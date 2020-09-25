#import <Foundation/Foundation.h>

@interface GpsDelegate : NSObject

+(void) onRequestGpsPermissionResult:(int64_t) id granted:(bool) granted;
+(void) onGpsLocation:(int64_t) id latitude:(double) latitude longitude:(double) longitude timeSinceLastUpdate:(int64_t) timeSinceLastUpdate accuracy:(float) accuracy;

@end
