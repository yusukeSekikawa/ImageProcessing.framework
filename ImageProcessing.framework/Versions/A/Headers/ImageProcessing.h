//
//  ImageProcessing.h
//

#import <UIKit/UIKit.h>
<<<<<<< HEAD
#import "ImageProcessingHelper.h"


=======
<<<<<<< HEAD
#import "ImageProcessingHelper.h"


=======
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759

#define CV_FACE_DETECT_SLOW_WITHOUT_PROFILE 0x01
#define CV_FACE_DETECT_SLOW_WITH_PROFILE 0x81
#define CV_FACE_DETECT_FAST_WITHOUT_PROFILE 0x04
#define CV_FACE_DETECT_FAST_WITH_PROFILE 0x84



<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
typedef struct {
	uint8_t *imagePtr;
	int height;
	int width;
	int bytesPerRow;
	CFDataRef data;
    CGDataProviderRef dataProvider;
} _imageInfo;
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759

@interface ImageProcessing : NSObject {
	;
}
+ (void)cleanUpCV;
+ (NSArray*)detectFace:(uint8_t*)sourcePtr width:(int)width height:(int)height type:(int)type;
<<<<<<< HEAD
+ (UIImage*)effectEdge:(UIImage *)sourceImage;
=======
<<<<<<< HEAD
+ (UIImage*)effectEdge:(UIImage *)sourceImage;
=======
+ (UIImage*)effectFastLine:(uint8_t *)sourcePtr width:(int)width height:(int)height;
+ (UIImage*)effectLine:(UIImage *)sourceImage;
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
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
