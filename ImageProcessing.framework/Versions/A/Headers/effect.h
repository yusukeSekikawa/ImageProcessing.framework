/************************************************/
/******************effect.h**********************/
/************************************************/

/*Word replace script for Mac*/
/* 
 find ./ -name "*.c" -exec perl -i -pe 's|Effects|VEffects|' {} \;
 */

//__android_log_write(ANDROID_LOG_DEBUG,"SEKI","RGB");  

#ifndef _EFFECT
#define _EFFECT

#define TARGET_IOS		0
#define TARGET_ADNROID	1

#define TARGET_PF		TARGET_IOS
/*COMMON INCLUDE*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/************Neon Setting************/
#if (TARGET_PF==TARGET_IOS)
#import <TargetConditionals.h>
    #if (TARGET_IPHONE_SIMULATOR)
        //Not use Neon
    #else
        #define USE_NEON
    #endif//(TARGET_IPHONE_SIMULATOR)
#else//(TARGET_PF==TARGET_ADNROID)
    #define USE_NEON
#endif//(TARGET_PF==TARGET_IOS)


#ifdef USE_NEON
#include <arm_neon.h>
#endif
/***********END********************/


/*Android Specific*/
#if TARGET_PF==TARGET_ADNROID
/*------ANDROID-------*/
#include <jni.h>
#include <android/log.h>
#elif TARGET_PF==TARGET_IOS
/*------IOS-------*/
#endif
/**
 * ... Function Prototype -1 ...
 */
/**
 * Add Frame to image.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int*:arr2 Pointer to the frame image
 * @param[in] int:width Width of the frame image.
 * @param[in] int:height Height of frame image.
 * @param[in] int:f_width Width of picture the frame image.
 * @param[in] int:f_height Height of picture the frame image.
 * @param[in] int:p_width Width of the frame image.
 * @param[in] int:p_height Height of frame image.
 * @param[in] int:p_origin_x Width of picture the frame image.
 * @param[in] int:p_origin_y Height of picture the frame image.
 * @retval true case Success
 * @retval false case Failure
 */
int addFrame(int* arr1,int* arr2,int width,int height,int f_width,int f_height,int p_width,int p_height,int p_origin_x,int p_origin_y);

/**
 * Add Bitmap text  to image.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int*:arr2 Pointer to the frame image
 * @param[in] int:width Width of the frame image.
 * @param[in] int:height Height of frame image.
 * @param[in] int:textHeight Width of picture the frame image.
 * @param[in] int:textWidth Height of picture the frame image.
 * @retval true case Success
 * @retval false case Failure
 */
int addText(int* arr1,int* arr2,int width,int height,int textHeight,int textWidth);

/**
 * Black and White Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectBW(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS
int effectBW(int* arr1,int* arr2,int width,int height);
int effectBW_1_4(int* arr1,int* arr2,int width,int height);
int effectBW_1_2(int* arr1,int* arr2,int width,int height);
#endif
/**
 * Binary Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:thresh Threthhold.
 * @param[in] int:color Color of image.Format:0xFFRRGGBB.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectBin(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint thresh,jint color1,jint color2);
#elif TARGET_PF==TARGET_IOS
int effectBin(int* arr1,int* arr2,int width,int height,int thresh,int color1,int color2);
#endif
/**
 * Blur Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:pointX Threthhold.
 * @param[in] int:pointX Center of blur x.
 * @param[in] int:pointY Center of blur y.
 * @param[in] int:power Blur power.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectBlur(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint power);
#elif TARGET_PF==TARGET_IOS
int effectBlur(int* arr1,int* arr2,int width,int height,int pointX,int pointY,int power);
#endif
/**
 * Change Contrast.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:contrast Contrast Curve(1:No original).
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectContrast(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jfloat contrast);
#elif TARGET_PF==TARGET_IOS
    int effectContrast(int* arr1,int* arr2,int width,int height,float contrast);
#endif
    
/**
 * Fish Eye Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectFish(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS
int effectFish(int* arr1,int* arr2,int width,int height);
#endif
/**
 * Change HSV.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectHSV(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint hue,jint saturation,jint value);
#elif TARGET_PF==TARGET_IOS
int effectHSV(int* arr1,int* arr2,int width,int height,int hue,int saturation,int value);
#endif

/**
 * Miniture Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
int effectMin(int* arr1,int* arr2,int width,int height);

/**
 * Mirror Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectMirror(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint type);
#elif TARGET_PF==TARGET_IOS
int effectMirror(int* arr1,int* arr2,int width,int height,int type);
#endif
/**
 * Polaroid Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectPola(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS
int effectPola(int* arr1,int* arr2,int width,int height);
#endif
/**
 * POP Color Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectPOP(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS
int effectPOP(int* arr1,int* arr2,int width,int height);
#endif
/**
 * Sepia Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectSepia(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS
int effectSepia(int* arr1,int* arr2,int width,int height);
#endif
/**
 * Soft Focus Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:Softness.(1:No effect) should be less than val=width>height ? height:width
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectSoft(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint power); 
#elif TARGET_PF==TARGET_IOS
int effectSoft(int* arr1,int* arr2,int width,int height,int power);
#endif
/**
 * Spot Color Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectSpot(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint centerColor,jint colorWidth); 
#elif TARGET_PF==TARGET_IOS
int effectSpot(int* arr1,int* arr2,int width,int height,int centerColor,int colorWidth);
#endif
/**
 * Swap Color.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectSpot(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint type); 
#elif TARGET_PF==TARGET_IOS
int effectSwap(int* arr1,int* arr2,int width,int height,int type);
#endif
/**
 * Toy Camera Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
    jboolean Java_sekki_VEffects_Main_effectToy(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS
    int effectToy(int* arr1,int* arr2,int width,int height);
#endif



/**
 * Hi contrast Camera Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectHiContrast(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS		
    int effectHiContrast(int* arr1,int* arr2,int width,int height);
#endif

/**
 * HiConBW Camera Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectHiConBW(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS		
int effectHiConBW(int* arr1,int* arr2,int width,int height);
#endif
/**
 * effectBlurFlat Camera Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectBlurFlat(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,int power);
#elif TARGET_PF==TARGET_IOS		
int effectBlurFlat(int* arr1,int* arr2,int width,int height,int power);
#endif
/**
 * effectShading Camera Effect.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectShading(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint type);
#elif TARGET_PF==TARGET_IOS
int effectShading(int* arr1,int* arr2,int width,int height,int type);
#endif


/**
 * effectDitherMono.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectDitherMono(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);  
#elif TARGET_PF==TARGET_IOS
int effectDitherMono(int* arr1,int* arr2,int width,int height);
#endif
   

/**
 * effectDither.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectDither(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);  
#elif TARGET_PF==TARGET_IOS
int effectDither(int* arr1,int* arr2,int width,int height);
#endif


/**
 * effectOverlay.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
int Java_sekki_VEffects_Main_effectOverlay(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS	
int effectOverlay(int* arr1,int* arr2,int width,int height);
#endif 
/**
 * effectOverlay.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
int effectOverlay2(int* src1,int* arr2,int* src2,int width,int height);


/**
 * effectBlurFlatWeak.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectBlurFlatWeak(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint power);
#elif TARGET_PF==TARGET_IOS
int effectBlurFlatWeak(int* arr1,int* arr2,int width,int height,int power);
#endif  


/**
 * effectPST.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectPST(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height); 
#elif TARGET_PF==TARGET_IOS	
int effectPST(int* arr1,int* arr2,int width,int height);
#endif 

/**
 * effectRainbow.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @retval true case Success
 * @retval false case Failure
 */
#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectRainbow(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);  
#elif TARGET_PF==TARGET_IOS			
int effectRainbow(int* arr1,int* arr2,int width,int height);
#endif


#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectEdge(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height);
#elif TARGET_PF==TARGET_IOS	
int effecteEdge(int* arr1,int* arr2,int width,int height);
#endif

#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectAverage(JNIEnv* env,jobject thiz, jintArray src,jint width,jint height,jint add_cnt);
#elif TARGET_PF==TARGET_IOS			
int effectAverage(int* arr1,int* arr2,int* buffer,int width,int height,int add_cnt);
#endif

#if TARGET_PF==TARGET_ADNROID
jboolean Java_sekki_VEffects_Main_effectErace(JNIEnv* env,jobject thiz, jintArray src,jintArray buffer,jint width,jint height,jint centerColor,jint eraceWidth);
#elif TARGET_PF==TARGET_IOS			
int effectErace(int* arr1,int* arr2,int* buffer,int width,int height,int centerColor,int eraceWidth,int mode);
#endif

/**
 * effectFastShading
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:inspectX Origin of rect to inspect.
 * @param[in] int:inspectY Origin of rect to inspect.
 * @param[in] int:inspectW Width of the rect to inspect.
 * @param[in] int:inspectH Height of the rect to inspect.
 * @retval 0xFFRRGGBB format in Success
 * @retval case error 0X00******
 */
int effectFastShading(int* arr1,int* arr2,int width,int height,uint8_t *shadingTable);



/**
 * effectFastShading
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:inspectX Origin of rect to inspect.
 * @param[in] int:inspectY Origin of rect to inspect.
 * @param[in] int:inspectW Width of the rect to inspect.
 * @param[in] int:inspectH Height of the rect to inspect.
 * @retval 0xFFRRGGBB format in Success
 * @retval case error 0X00******
 */
int effectGamma(int* arr1,int* arr2,int width,int height,uint8_t *r_gamma,uint8_t *g_gamma,uint8_t *b_gamma);
int effectGammaV(int* arr1,int* arr2,int width,int height,uint8_t *r_gamma,uint8_t *g_gamma,uint8_t *b_gamma);
        
     
/**
 * Get average RBG value.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:inspectX Origin of rect to inspect.
 * @param[in] int:inspectY Origin of rect to inspect.
 * @param[in] int:inspectW Width of the rect to inspect.
 * @param[in] int:inspectH Height of the rect to inspect.
 * @retval 0xFFRRGGBB format in Success
 * @retval case error 0X00******
 */
int createShadingTable(uint8_t* shadingTable,int width,int height,uint8_t *table,int s_width,int s_height);

/**
 * Get average RBG value.
 *
 * @param[in] int*:arr1 Pointer to the picture image.
 * @param[in] int:width Width of the picture image.
 * @param[in] int:height Height of picture image.
 * @param[in] int:inspectX Origin of rect to inspect.
 * @param[in] int:inspectY Origin of rect to inspect.
 * @param[in] int:inspectW Width of the rect to inspect.
 * @param[in] int:inspectH Height of the rect to inspect.
 * @retval 0xFFRRGGBB format in Success
 * @retval case error 0X00******
 */
int inspectDiffs(int* newPtr,int* oldPtr,int width,int height,int inspectX,int inspectY,int inspectW,int inspectH);

/*Function Prototype -4 Private */
int addCopyDetectionCode(int *bufPtr,int width,int height); 
int addTrialIndicator(int *bufPtr,int width,int height);


#endif