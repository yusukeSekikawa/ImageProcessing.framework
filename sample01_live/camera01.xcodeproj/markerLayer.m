//
//  markerLayer.m
//  camera01
//
//  Created by YUSUKE SEKIKAWA on 6/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "markerLayer.h"


@implementation markerLayer


-(void)subDrawFaceRect:(CGRect)_rect withContext:(CGContextRef)context{
    //CGRect rect=CGRectMake(_rect.origin.y, _rect.origin.x, _rect.size.height, _rect.size.width);
    CGRect rect=_rect;

    CGContextMoveToPoint(context, rect.origin.x,rect.origin.y);
    CGContextAddLineToPoint(context, rect.origin.x,rect.origin.y+rect.size.height);
    CGContextAddLineToPoint(context, rect.origin.x+rect.size.width,rect.origin.y+rect.size.height);
    CGContextAddLineToPoint(context, rect.origin.x+rect.size.width,rect.origin.y);
    CGContextAddLineToPoint(context, rect.origin.x,rect.origin.y);    
}

-(void)drawFaceRect:(NSArray*)array{
    if([array count]<1){
        self.opacity =0;
    }else{
        self.opacity =1;
        CGRect main_frame=CGRectMake(0, 0, 426, 320);
        
        UIGraphicsBeginImageContext(main_frame.size);
        CGContextRef context		= UIGraphicsGetCurrentContext();
        CGContextClearRect(context,main_frame);
        CGContextSetLineWidth(context, 2.0);
        CGContextSetRGBStrokeColor(context, 0.0, 1.0, 1.0, 1.);
        
        for(NSNumber *rectNumber in array){
            NSLog(@"Face:%f,%f,%f,%f",[rectNumber CGRectValue].origin.x,[rectNumber CGRectValue].origin.y,[rectNumber CGRectValue].size.width,[rectNumber CGRectValue].size.height);
            [self subDrawFaceRect:[rectNumber CGRectValue] withContext:context];
        }
        CGContextStrokePath(context);
    }
    
    
	UIImage *img=UIGraphicsGetImageFromCurrentImageContext();
	UIGraphicsEndImageContext();
	self.contents=(id)img.CGImage;
    
}


@end
