//
//  AppStyle.h
//  Express
//
//  Created by Terwer Green on 16/3/27.
//  Copyright © 2016年 www.terwer.com. All rights reserved.
//

#import "AppMacros.h"

#ifndef SuperApp_AppStyle_h
#define SupersApp_AppStyle_h

//随机颜色
#define randomColor RGBACOLOR(arc4random_uniform(255),arc4random_uniform(255),arc4random_uniform(255),1.0);
//导航栏背景
#define navbgcolor RGBACOLOR(16.0,116.0,208.0,1.0)
//标题背景
#define titleFontSize (IS_IPHONE_6P == 0 ? 20.0f : 26.0f)
//标题颜色
#define titleColor [UIColor whiteColor]

#endif
