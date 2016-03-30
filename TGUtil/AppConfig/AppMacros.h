//
//  AppMacros.h
//  Express
//
//  Created by Terwer Green on 16/3/27.
//  Copyright © 2016年 www.terwer.com. All rights reserved.
//

//应用委托
#define kAppDelegate        ((AppDelegate *)[UIApplication sharedApplication].delegate)

//设备相关
#define isIPad              (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define isIPhone            (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define isIP5Screen         ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136),[[UIScreen mainScreen] currentMode].size) : NO)

#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS (isIPhone && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5 (isIPhone && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6 (isIPhone && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P (isIPhone && SCREEN_MAX_LENGTH == 736.0)

//系统版本和语言
#define IOS7_OR_LATER       ([[[UIDevice currentDevice] systemVersion] compare:@"7.0"] != NSOrderedAscending)
#define kSystemVersion      ([[UIDevice currentDevice] systemVersion])
#define kCurrentLanguage    ([[NSLocale preferredLanguages] objectAtIndex:0])

//应用名称和版本
#define kAPPName            [[[NSBundle mainBundle]infoDictionary] objectForKey:@"CFBundleDisplayName"]
#define kAPPVersion         [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

//appStore相关
#define kAPPCommentUrl       @"itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%d"
#define kAPPCommentUrl_IOS7  @"itms-apps://itunes.apple.com/app/id%d"
#define kAPPUpdateUrl        @"http://itunes.apple.com/lookup?id=%d"

#define SYSTEM_VERSION        [[[UIDevice currentDevice] systemVersion] floatValue]

//设备屏幕尺寸
#define kScreenWidth        ([UIScreen mainScreen].bounds.size.width)
#define kScreenHeight       ([UIScreen mainScreen].bounds.size.height)

#define STATUSBAR_HEIGHT      [[UIApplication sharedApplication] statusBarFrame].size.height
#define NAVBAR_HEIGHT         (44.f + ((SYSTEM_VERSION >= 7) ? STATUSBAR_HEIGHT : 0))
#define FULL_WIDTH            SCREEN_WIDTH
#define FULL_HEIGHT           (SCREEN_HEIGHT - ((SYSTEM_VERSION >= 7) ? 0 : STATUSBAR_HEIGHT))
#define CONTENT_HEIGHT        (FULL_HEIGHT - NAVBAR_HEIGHT)

// 屏幕高度
#define VIEW_HEIGHT           self.view.bounds.size.height

// 屏幕宽度
#define VIEW_WIDTH            self.view.bounds.size.width

//工具栏高度
#define TABBAR_HEIGHT self.tabBarController.tabBar.frame.size.height

//度弧度转换
#define kDegreesToRadian(x)         (M_PI * (x) / 180.0)
#define kRadianToDegrees(radian)    (radian*180.0) / (M_PI)

//Block self
#define WEAKSELF    __weak          typeof(self)  weakSelf = self;
#define STRONGSELF  __strong        typeof(weakSelf) strongSelf = weakSelf;

//GCD
#define kGCDBackground(block)       dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), (block))
#define kGCDMain(block)             dispatch_async(dispatch_get_main_queue(),(block))

//颜色
#define RGBCOLOR(r,g,b)             [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1.0f]
#define RGBACOLOR(r,g,b,a)          [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define HEXCOLOR(c) [UIColor colorWithRed:((c>>24)&0xFF)/255.0f green:((c>>16)&0xFF)/255.0f blue:((c>>8)&0xFF)/255.0f alpha:((c)&0xFF)/255.0f];

//安全释放
#define MM_RELEASE_SAFELY(__POINTER) {  [__POINTER release]; __POINTER = nil; }

//计时器
#define MM_INVALIDATE_TIMER(__TIMER) { [__TIMER invalidate]; __TIMER = nil; }

//以tag读取View
#define kViewByTag(parentView, tag, Class)  (Class *)[parentView viewWithTag:tag]

//读取Xib文件的类
#define kViewByNib(Class, owner, index) [[[NSBundle mainBundle] loadNibNamed:Class owner:owner options:nil] objectAtIndex:index]

//空值判断
#define objectOrNull(obj) ((obj) ? (obj) : [NSNull null])
#define objectOrEmptyStr(obj) ((obj) ? (obj) : @"")
#define isNull(x)             (!x || [x isKindOfClass:[NSNull class]])
#define toInt(x)              (isNull(x) ? 0 : [x intValue])
#define isEmptyString(x)      (isNull(x) || [x isEqual:@""] || [x isEqual:@"(null)"])

#define sleep(s);             [NSThread sleepForTimeInterval:s];
#define Syn(x)                @synthesize x = _##x

//界面相关
#define BoldSystemFont(size)  [UIFont boldSystemFontOfSize:size]
#define systemFont(size)      [UIFont systemFontOfSize:size]
#define beginAutoPool         NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init]; {
#define endAutoPool           } [pool release];
#define skipspace(c)          while (isspace(*c)) ++c
#define skipUntil(c,x)        while (x != *c) ++c
#define TheWindowHeight      ([UIDevice isAfterOS7] ? [UIScreen mainScreen].bounds.size.height : ([UIScreen mainScreen].bounds.size.height - 20))
#define IntToNumber(int)        ([NSNumber numberWithInt:int])
#define isIOS7 [[UIDevice currentDevice].systemVersion doubleValue]>=7.0?YES:NO
#define IPHONE4 ([[UIScreen mainScreen] bounds ].size.height == 480 )

//数据存储
#define FileManager     ([NSFileManager defaultManager])
#define TheUserDefaults ([NSUserDefaults standardUserDefaults])

//单例
#undef	AS_SINGLETON
#define AS_SINGLETON( __class ) \
+ (__class *)sharedInstance;

#undef	DEF_SINGLETON
#define DEF_SINGLETON( __class ) \
+ (__class *)sharedInstance \
{ \
static dispatch_once_t once; \
static __class * __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[__class alloc] init]; } ); \
return __singleton__; \
}

//断言
#undef NSAssert
#define NSAssert(condition, frmt, ...) \
do { \
@try { \
if (!(condition)) { \
NSString *text = @"Assert Exception: "; \
text = [text stringByAppendingFormat:frmt, ##__VA_ARGS__]; \
NSLog(@"%@", text); \
[NSException raise:nil format:nil]; \
} \
} \
@catch (NSException *exception) {} \
} while (0);
#define LogBreakpoint(frmt, ...)    NSAssert(NO, frmt, ##__VA_ARGS__)

//日志
#ifdef DEBUG
#define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif

//block定义
typedef void(^BaseBlock)(void);
typedef void(^BaseBlockWithString)(NSString *);







