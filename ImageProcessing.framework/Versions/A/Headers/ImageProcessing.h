//
//  ImageProcessing.h
//

#import <UIKit/UIKit.h>
#import "ImageProcessingHelper.h"



#define CV_FACE_DETECT_SLOW_WITHOUT_PROFILE 0x01
#define CV_FACE_DETECT_SLOW_WITH_PROFILE 0x81
#define CV_FACE_DETECT_FAST_WITHOUT_PROFILE 0x04
#define CV_FACE_DETECT_FAST_WITH_PROFILE 0x84




@interface ImageProcessing : NSObject {
	;
}
+ (void)cleanUpCV;
+ (NSArray*)detectFace:(uint8_t*)sourcePtr width:(int)width height:(int)height type:(int)type;
+ (UIImage*)effectEdge:(UIImage *)sourceImage;
+ (UIImage*)effectBW:(UIImage *)sourceImage;
+ (UIImage*)effectBin:(UIImage *)sourceImage th:(int)th color:(int)color;
+ (UIImage*)effectBlur:(UIImage *)sourceImage pointX:(int)pointX pointY:(int)pointY power:(int)power;
+ (UIImage*)effectContrast:(UIImage *)sourceImage contrast:(float)contrast;
+ (UIImage*)effectFish:(UIImage *)sourceImage;
+ (UIImage*)effectHSV:(UIImage *)sourceImage hue:(int)hue saturation:(int)saturation value:(int)value;
+ (UIImage*)effectMin:(UIImage *)sourceImage;
+ (UIImage*)effectMirror:(UIImage *)sourceImage type:(int)type;
+ (UIImage*)effectPola:(UIImage *)sourceImage;
+ (UIImage*)effectPOP:(UIImage *)sourceImage;
+ (UIImage*)effectSepia:(UIImage *)sourceImage;
+ (UIImage*)effectSoft:(UIImage *)sourceImage power:(int)power;
+ (UIImage*)effectSpot:(UIImage *)sourceImage centerColor:(int)centerColor colorWidth:(int)colorWidth;
+ (UIImage*)effectSwap:(UIImage *)sourceImage type:(int)type;
+ (UIImage*)effectToy:(UIImage *)sourceImage;
+ (UIImage*)effectHiConBW:(UIImage *)sourceImage;
+ (UIImage*)effectBlurFlat:(UIImage *)sourceImage power:(int)power;
+ (UIImage*)effectBlurFlatWeak:(UIImage *)sourceImage power:(int)power;
+ (UIImage*)effectDitherMono:(UIImage *)sourceImage;
+ (UIImage*)effectDither:(UIImage *)sourceImage;
+ (UIImage*)effectPST:(UIImage *)sourceImage;
+ (UIImage*)effectRainbow:(UIImage *)sourceImage;

@end
