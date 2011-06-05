/*
 * ImageProcessing.framework for iOS
 * Sample APP-1(Live view processing)
 * cameraViewController.m
 *
 * Copyright (c) Yusuke Sekikawa, 11/06/02
 * All rights reserved.
 * 
 * BSD License
 *
 * Redistribution and use in source and binary forms, with or without modification, are 
 * permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice, this list of
 *  conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this list
 *  of conditions and the following disclaimer in the documentation and/or other materia
 * ls provided with the distribution.
 * - Neither the name of the "Yuichi Yoshida" nor the names of its contributors may be u
 * sed to endorse or promote products derived from this software without specific prior 
 * written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY E
 * XPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES O
 * F MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SH
 * ALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENT
 * AL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROC
 * UREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS I
 * NTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRI
 * CT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF T
 * HE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#import "cameraViewController.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
#import <ImageProcessing/effect.h>
#import <ImageProcessing/ImageProcessing.h>
//#import <ImageProcessing/ImageProcessingHelper.h>

@implementation cameraViewController
@synthesize _session=session;
@synthesize _prevLayer=prevLayer;
<<<<<<< HEAD
=======
=======
#import <ImageProcessing/ImageProcessing.h>
#import <ImageProcessing/effect.h>

@implementation cameraViewController
@synthesize _session=session;
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759

uint8_t *shadingPtr=nil;
- (void)dealloc
{
    [_session release];
	if (_shadingData)
	{
		free(_shadingData);
	}
    if (_filteredImageBuffer)
	{
		free(_filteredImageBuffer);
	}
    [ImageProcessing cleanUpCV];

    [super dealloc];
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle
<<<<<<< HEAD
=======
- (UIImage *) flipImageVerticaly:(UIImage *)img{
    CGImageRef imgRef = [img CGImage];
    CGContextRef context;
	
    UIGraphicsBeginImageContext(CGSizeMake(img.size.width, img.size.height));
    context = UIGraphicsGetCurrentContext();
    CGContextTranslateCTM(context, img.size.width, 0);
    CGContextScaleCTM(context, 1.0, -1.0);
    CGContextRotateCTM(context, -M_PI);
	
    CGContextDrawImage(context, CGRectMake(0, 0, img.size.width, img.size.height), imgRef);
    UIImage *ret = UIGraphicsGetImageFromCurrentImageContext();  
	
    UIGraphicsEndImageContext();
    return ret;
}

- (UIImage*)resizedImage:(UIImage *)img
{
#define resizedImgWidth		80
    CGFloat imgWidth  = img.size.width;
    CGFloat imgHeigh = img.size.height;
    
    CGSize resizedSize = (imgWidth < imgHeigh) ? CGSizeMake(resizedImgWidth, imgHeigh*(resizedImgWidth/imgWidth)):CGSizeMake(imgWidth*(resizedImgWidth/imgHeigh), resizedImgWidth);
	
    UIGraphicsBeginImageContext(resizedSize);
	
    [img drawInRect:CGRectMake(0, 0, resizedSize.width, resizedSize.height)];
    UIImage* resizedImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return resizedImage;
}
- (UIImage*)imageByCroppingSquare:(CGImageRef)imageToCrop
{
    size_t width = CGImageGetWidth(imageToCrop);
    size_t height = CGImageGetHeight(imageToCrop);
    
    NSLog(@"imageByCroppingSquare %lu:%lu",width,height);
    
    int xyDiffs=width-height;
    CGRect squareToCrop;
    if(xyDiffs>0){
        squareToCrop=CGRectMake(xyDiffs/2, 0, height, height);
    }else{
        squareToCrop=CGRectMake(0 , -xyDiffs/2, width, width);
        
    }
    CGImageRef imageRef = CGImageCreateWithImageInRect(imageToCrop, squareToCrop);
    UIImage *cropped =[UIImage imageWithCGImage:imageRef];
    CGImageRelease(imageRef);
    return cropped;
}
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759


- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    
	CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
	CVPixelBufferLockBaseAddress(imageBuffer, 0);
	uint8_t *baseAddress = (uint8_t *)CVPixelBufferGetBaseAddress(imageBuffer);
	size_t bytesPerRow = CVPixelBufferGetBytesPerRow(imageBuffer);
	size_t width = CVPixelBufferGetWidth(imageBuffer);
	size_t height = CVPixelBufferGetHeight(imageBuffer);
	size_t bufSize = bytesPerRow * height;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
    
    
    if (_filteredImageBufferSize < bufSize)
    {
        if (_filteredImageBuffer)
            free(_filteredImageBuffer);
        _filteredImageBuffer = malloc(bufSize);
        if (!_filteredImageBuffer)
            return;
    }
    switch (eTypeSeg.selectedSegmentIndex){
        case 11:
            if(prevLayer.hidden){
                prevLayer.hidden=NO;
                session.sessionPreset = AVCaptureSessionPresetLow
                ;
            }
            break;
        default:
            if(!prevLayer.hidden){
                prevLayer.hidden=YES;
                session.sessionPreset = AVCaptureSessionPresetMedium;
            }
            break;
    }
    switch (eTypeSeg.selectedSegmentIndex)
    {
        case 0:
            effecteEdge((int *)baseAddress,_filteredImageBuffer,width,height);
            break;
        case 1:
            effectDither((int *)baseAddress,_filteredImageBuffer,width,height);
            break;
        case 2:
            effectSwap((int *)baseAddress,_filteredImageBuffer,width,height,1);
            break;
        case 3:
            effectBin((int *)baseAddress,(int *)_filteredImageBuffer,width,height,128,0xff000fff);
            break; 
        case 4:
            effectHiConBW((int *)baseAddress,_filteredImageBuffer,width,height);
            break; 
        case 5:
            effectMirror((int *)baseAddress,_filteredImageBuffer,width,height,0);
            break; 
        case 6:
            effectBlur((int *)baseAddress,_filteredImageBuffer,width,height,width/2,height/2,64);
            break; 
        case 7:
            if(_shadingData==NULL){
                _shadingData=malloc(width*height*4);
                createShadingTable(_shadingData,width,height, NULL, 0, 0);
                NSLog(@"Create shading table");
            }
            effectFastShading((int *)baseAddress,_filteredImageBuffer,width,height,_shadingData);
            //effectHiContrast((int *)baseAddress,_filteredImageBuffer,width,heightO);
            break;
        case 8:
            effectPST((int *)baseAddress,_filteredImageBuffer,width,height);
            break;  
        case 9:
            effectRainbow((int *)baseAddress,_filteredImageBuffer,width,height);
            break;
        case 10:
            effectFish((int *)baseAddress,_filteredImageBuffer,width,height);
            break;
        default:
            if(width!=192){
                return;
            }
            [_markerLayre drawFaceRect:[ImageProcessing detectFace:baseAddress width:width height:height type:CV_FACE_DETECT_FAST_WITHOUT_PROFILE]];
            //NSArray * faceArray = [ImageProcessing detectFace:baseAddress width:width height:height type:CV_FACE_DETECT_FAST_WITHOUT_PROFILE];
            
            return;
<<<<<<< HEAD
=======
            //memcpy(_filteredImageBuffer, baseAddress, bufSize);
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
            break;
    }
    
    
    //effectMirror((int *)baseAddress,_filteredImageBuffer,width,height,0);
    NSData *data = [NSData dataWithBytesNoCopy:_filteredImageBuffer
                                        length:bufSize
                                  freeWhenDone:NO];
    CGDataProviderRef dp = CGDataProviderCreateWithCFData((CFDataRef)data);
    
    CGColorSpaceRef colorSpace;
    int bytesPerPixel;
    uint32_t byteOrder;
    uint8_t bytesPerRowDiv;
    
    switch (eTypeSeg.selectedSegmentIndex) {
        case 0:
            colorSpace =CGColorSpaceCreateDeviceGray();
            bytesPerPixel=8;
            bytesPerRowDiv=4;
            byteOrder=(kCGBitmapByteOrderDefault);
            break;
        default:
            colorSpace= CGColorSpaceCreateDeviceRGB();
            bytesPerPixel=32;
            bytesPerRowDiv=1;
            byteOrder=(kCGBitmapByteOrder32Little | kCGImageAlphaPremultipliedFirst);
            break;
    }
    
    
    CGImageRef cgImage = CGImageCreate(width, height, 8, bytesPerPixel, bytesPerRow/bytesPerRowDiv, colorSpace, byteOrder,
                                       dp, NULL, NO, kCGRenderingIntentDefault);
    UIImage *img = [[[UIImage alloc] initWithCGImage:cgImage] autorelease];
    [liveView setImage:img];
    CGColorSpaceRelease(colorSpace);
    CGDataProviderRelease(dp);
    CGImageRelease(cgImage);
    
<<<<<<< HEAD
=======
=======
	
    if(eTypeSeg.selectedSegmentIndex==0){
        //NSLog(@"tyr cvCanny %lu %lu",width,height);
        [liveView setImage:[ImageProcessing effectFastLine:baseAddress width:width height:height]];
#if 0
        NSArray * faceArray = [ImageProcessing detectFace:baseAddress width:width height:height type:CV_FACE_DETECT_FAST_WITHOUT_PROFILE];
        for(NSNumber *rectNumber in faceArray){
            NSLog(@"Face:%f,%f,%f,%f",[rectNumber CGRectValue].origin.x,[rectNumber CGRectValue].origin.y,[rectNumber CGRectValue].size.width,[rectNumber CGRectValue].size.height);
        }
#endif
        
    }else{
        if (_filteredImageBufferSize < bufSize)
        {
            if (_filteredImageBuffer)
                free(_filteredImageBuffer);
            _filteredImageBuffer = malloc(bufSize);
            if (!_filteredImageBuffer)
                return;
        }
        
        effectMirror((int *)baseAddress,_filteredImageBuffer,width,height,0);
        NSData *data = [NSData dataWithBytesNoCopy:_filteredImageBuffer
                                            length:bufSize
                                      freeWhenDone:NO];
        CGDataProviderRef dp = CGDataProviderCreateWithCFData((CFDataRef)data);
        
        CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
        CGImageRef cgImage = CGImageCreate(width, height, 8, 32, bytesPerRow, colorSpace, 
                                           (kCGBitmapByteOrder32Little | kCGImageAlphaPremultipliedFirst),
                                           dp, NULL, NO, kCGRenderingIntentDefault);
        UIImage *img = [[[UIImage alloc] initWithCGImage:cgImage] autorelease];
        [liveView setImage:img];
        CGColorSpaceRelease(colorSpace);
        CGDataProviderRelease(dp);
        CGImageRelease(cgImage);
    }
    
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
    [liveView setNeedsDisplay];
}


- (void) initCapture
{
	AVCaptureDevice *captureDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
	
	AVCaptureDeviceInput *captureInput = [AVCaptureDeviceInput deviceInputWithDevice:captureDevice error:nil];
	AVCaptureVideoDataOutput *captureOutput = [[AVCaptureVideoDataOutput alloc] init];
	
	captureOutput.alwaysDiscardsLateVideoFrames = YES; 
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	
	//dispatch_queue_t queue;
	//queue = dispatch_queue_create("cameraQueue", NULL);
	//[captureOutput setSampleBufferDelegate:nil queue:queue];
	//dispatch_release(queue);
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
    
    [captureOutput setSampleBufferDelegate:self queue:dispatch_get_main_queue()];

	
	NSString* key = (NSString*)kCVPixelBufferPixelFormatTypeKey; 
# if GRAY_TEST  
    NSNumber* value = [NSNumber numberWithUnsignedInt:kCVPixelFormatType_32BGRA]; 
#else
    NSNumber* value = [NSNumber numberWithUnsignedInt:kCVPixelFormatType_32BGRA];
#endif
    NSDictionary* videoSettings = [NSDictionary dictionaryWithObject:value forKey:key]; 
    [captureOutput setVideoSettings:videoSettings]; 
	
	session = [[AVCaptureSession alloc] init];
	//session.sessionPreset = AVCaptureSessionPreset1280x720;
    session.sessionPreset = AVCaptureSessionPresetMedium;
    //session.sessionPreset = AVCaptureSessionPresetLow;
    
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
    prevLayer = [AVCaptureVideoPreviewLayer layerWithSession: session];
    [prevLayer setOrientation:AVCaptureVideoOrientationLandscapeRight];
    
    prevLayer.frame = CGRectMake(0.0, 0.0, 426 , 320);
    prevLayer.videoGravity = AVLayerVideoGravityResizeAspect;
    [self.view.layer addSublayer: prevLayer];
    prevLayer.hidden=YES;
    
    if(_markerLayre==NULL){
        _markerLayre=[markerLayer layer];
        _markerLayre.frame=CGRectMake(0.0, 0.0, 426 , 320);;
        [self.view.layer addSublayer:_markerLayre];
    }
    
<<<<<<< HEAD
=======
=======
//    AVCaptureVideoPreviewLayer *prevLayer = [AVCaptureVideoPreviewLayer layerWithSession: session];
//    [prevLayer setOrientation:AVCaptureVideoOrientationLandscapeRight];
//    
//    prevLayer.frame = CGRectMake(0.0, 0.0, 480 , 320);
//    prevLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
//    [self.view.layer addSublayer: prevLayer];
//    
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
    
	[session addInput:captureInput];
	[session addOutput:captureOutput];
	[captureOutput release];
	
	
	[session commitConfiguration];
	[session startRunning];

}
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.


- (void)viewDidLoad
{
    [super viewDidLoad];
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
    [eTypeSeg setTransform:CGAffineTransformMakeRotation(M_PI/2)]; 
    [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(initCapture) userInfo:nil repeats:NO];
    

<<<<<<< HEAD
=======
=======
    //[self initCapture];
    [eTypeSeg setTransform:CGAffineTransformMakeRotation(M_PI/2)]; 
    [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(initCapture) userInfo:nil repeats:NO];
>>>>>>> 6b3149e71160485a21af43630cb6366a63ac8ccb
>>>>>>> c77b0b452ca96cc8eb26b0db7bae3b900d481759
}


- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationLandscapeRight);
}

@end
