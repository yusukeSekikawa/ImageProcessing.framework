//
//  debugMacros.h
//  ImageProcessing
//
//  Created by Sekikawa Yusuke on 6/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifdef DEBUG
#define LOG(...) NSLog(__VA_ARGS__);
#define LOG_METHOD NSLog(@"%s",__func__);
#define DNSLogPint(p) NSLog(@"P(%f,%f)",p.x,p.y);
#define DNSLogSize(p) NSLog(@"S(%f,%f)",p.width,p.height);
#define DNSLogRect(p) NSLog(@"(%f,%f)(%f,%f)",p.origing.x,p.origing.y.p.size.width,p.size.height);
#else
#define LOG(...) ;
#define LOG_METHOD ;
#define DNSLogPint(p) ;
#define DNSLogSize(p) ;
#define DNSLogRect(p) ;
#endif