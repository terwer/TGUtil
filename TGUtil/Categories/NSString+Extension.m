//
//  NSString+Extension.h
//  YFStock
//
//  Created by Terwer Green on 15/9/9.
//  Copyright (c) 2015年 www.terwer.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (Extension)

/**
 *  获取指定Size情况下，字符串value的高度（注意使用之前确保控件的font已经设置好）
 *
 *  @param font   字体的大小
 *  @param maxSize 最大Size
 *
 *  @return 返回的高度
 */
- (CGSize)sizeWithFont:(UIFont *)font maxSize:(CGSize)maxSize;

/**
 *  获取指定宽度情况下，字符串value的高度（注意使用之前确保控件的font和width已经设置好）
 *
 *  @param font   字体的大小
 *  @param width 限制字符串显示区域的宽度
 *
 *  @return 返回的高度
 */
- (CGFloat) heightWithFont:(UIFont *)font andWidth:(CGFloat)width;

/**
 *  获取指定宽度情况下，字符串value的行数
 *
 *  @param font   字体的大小
 *  @param width 限制字符串显示区域的宽度
 *
 *  @return 返回的高度
 */
- (CGFloat) lineNumbersWithFont:(UIFont *)font andWidth:(CGFloat)width;

@end
