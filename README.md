![](http://blog-imgs-42.fc2.com/v/a/n/vanishlab/originalICON.png)


FEATURE
=======
+VERY FAST face detection. <br>
  8fps[iPhone4,OS 4.3.2,face exist]<br>
+Various fast image effect including Edge,Grayscale,Binarization,Blur,Postalization,Mirror,Spot Color,Residual image,Fish Eye,Gamma manupuration,Dither,Swap Color...and More!<br>
  Many effects is very high speed that you can use it with live view effect like sample code.<br>
+Easy to use.<br>
  There is C and Objective-C APIs that is simple to apply with iOS.<br>

HOW TO USE
=======
1.Download and open /sample01_live/camera01.xcodeproj<br>
2.Run<br>
*This framework and sample project currently works only iOS devices with armv7(iPhone3G and 1st gen iPodTouch is not supported.<br>
I will support armv6 and simulator in future).<br><br>

You can add ImageProcessing.framework to your project like other framework.
*Please set the following configuration when using in your own project.<br>
1.In your project setting,set architecture to armv7.(override)<br>
2.In your project setting,turn Thumb instruction to Off<br>
3.In your project setting,set Optimization Level to O3<br>
4.Add Accelerate.framework<br>
5.Add haarcascades to your project in framework.<br>

App Store
=======
You can download iOS APP [PiPic] using this framework on APP Store

HP((In construction)) & Blog
=======
[vanishlab]<br>
[blog]

Others
=======
Android version will be release soon.


Dependency
=======
Accelerate.framework
 
Contacts
=======
[facebook]<br>
[twitter]

Acknowledgement
=======
My colleague Ko Yokokawa designed HP and gave me advice

References
=======
[A very fast BGRA to Grayscale conversion on Iphone « Computer Vision Talks]<br>
[Optimizing OpenCV face detection for the i.MX51]

License
=======
BSD License.
This framework use OpenCV.
Please read License agreement below.


IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING. 

 By downloading, copying, installing or using the software you agree to this license.
 If you do not agree to this license, do not download, install,
 copy or use the software.


                          License Agreement
               For Open Source Computer Vision Library

Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
Copyright (C) 2008-2010, Willow Garage Inc., all rights reserved.
Third party copyrights are property of their respective owners.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  * Redistribution's of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

  * Redistribution's in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * The name of the copyright holders may not be used to endorse or promote products
    derived from this software without specific prior written permission.

This software is provided by the copyright holders and contributors "as is" and
any express or implied warranties, including, but not limited to, the implied
warranties of merchantability and fitness for a particular purpose are disclaimed.
In no event shall the Intel Corporation or contributors be liable for any direct,
indirect, incidental, special, exemplary, or consequential damages
(including, but not limited to, procurement of substitute goods or services;
loss of use, data, or profits; or business interruption) however caused
and on any theory of liability, whether in contract, strict liability,
or tort (including negligence or otherwise) arising in any way out of
the use of this software, even if advised of the possibility of such damage.


[PiPic]: http://www.facebook.com/apps/application.php?id=168715359851028

[vanishlab]: http://vanishlab.web.fc2.com/

[blog]: http://vanishlab.blog128.fc2.com/blog-entry-24.html

[facebook]: http://www.facebook.com/yusuke.sekikawa

[twitter]: http://twitter.com/#!/YusukeSekikawa

[BSD License]: http://www.opensource.org/licenses/bsd-license.php

[A very fast BGRA to Grayscale conversion on Iphone « Computer Vision Talks]: http://computer-vision-talks.com/2011/02/a-very-fast-bgra-to-grayscale-conversion-on-iphone/

[Optimizing OpenCV face detection for the i.MX51]: http://imxcommunity.org/group/computervisionusingtheimx/forum/topics/optimizing-opencv-face
