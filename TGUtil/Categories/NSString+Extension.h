//
//  NSString+Extension.m
//  YFStock
//
//  Created by Terwer Green on 15/9/9.
//  Copyright (c) 2015年 www.terwer.com. All rights reserved.
//

#import "NSString+Extension.h"

@implementation NSString (Extension)

#pragma mark 计算字符串大小

- (CGSize)sizeWithFont:(UIFont *)font maxSize:(CGSize)maxSize{
    /*NSDictionary *dict = @{NSFontAttributeName:font};
    CGSize textSize = [self  boundingRectWithSize:maxSize
                                          options:NSStringDrawingUsesLineFragmentOrigin |NSStringDrawingUsesFontLeading
                                       attributes:dict
                                          context:nil].size;
    return textSize;*/

    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7) {
        NSDictionary *stringAttributes = [NSDictionary dictionaryWithObject:font forKey: NSFontAttributeName];
        CGSize adjustedLabelSize = [self boundingRectWithSize:maxSize                                                      options:NSStringDrawingTruncatesLastVisibleLine|NSStringDrawingUsesLineFragmentOrigin
                                                   attributes:stringAttributes context:nil].size;
        return adjustedLabelSize;
    }
    else {
        CGSize adjustedLabelSize = [self sizeWithFont:font constrainedToSize:CGSizeMake(CGFLOAT_MAX, CGFLOAT_MAX) lineBreakMode:NSLineBreakByWordWrapping];
        
        return adjustedLabelSize;
    }
}

- (CGFloat) heightWithFont:(UIFont *)font andWidth:(CGFloat)width;{
    CGSize sizeToFit = [self sizeWithFont:font maxSize:CGSizeMake(width, CGFLOAT_MAX)];
    return sizeToFit.height;
}

- (CGFloat) lineNumbersWithFont:(UIFont *)font andWidth:(CGFloat)width{
    //计算不换行时
    CGSize size = [self sizeWithFont:font maxSize:CGSizeMake(width, MAXFLOAT)];
    //计算行数
    NSInteger lineNumbers =  size.width / width;
    return lineNumbers;
}

@end
