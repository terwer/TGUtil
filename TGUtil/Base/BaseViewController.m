//
//  BaseViewController.m
//  YFStock
//
//  Created by happy on 15/9/10.
//  Copyright (c) 2015年 Yifa Network. All rights reserved.
//

#import "BaseViewController.h"
#import "AppMacros.h"
#import "AppStyle.h"

@interface BaseViewController ()

@end

@implementation BaseViewController

#pragma mark - life cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    //设置导航栏
    [self setupNavigationBar];
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear: animated];
}

#pragma mark - private

- (void)setupNavigationBar{
    //导航栏背景
    if (IOS7_OR_LATER) {
        self.navigationController.navigationBar.barTintColor = navbgcolor;
        self.navigationController.navigationBar.translucent = NO;
    }else {
        self.navigationController.navigationBar.tintColor = navbgcolor;
    }
    //导航栏字体和颜色
    self.navigationController.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName: titleColor,
                                                                    NSFontAttributeName:[UIFont boldSystemFontOfSize:titleFontSize]
                                                                    };
}

#pragma mark - action

- (void)onBack{
    [self.navigationController popViewControllerAnimated:YES];
}


#pragma mark - release

- (void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
