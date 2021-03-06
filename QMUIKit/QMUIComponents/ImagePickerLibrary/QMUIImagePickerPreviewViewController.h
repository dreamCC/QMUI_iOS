//
//  QMUIImagePickerPreviewViewController.h
//  qmui
//
//  Created by Kayo Lee on 15/5/3.
//  Copyright (c) 2015年 QMUI Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QMUIImagePreviewViewController.h"
#import "QMUIAsset.h"

@class QMUIButton, QMUINavigationButton;
@class QMUIImagePickerViewController;
@class QMUIImagePickerPreviewViewController;

@protocol QMUIImagePickerPreviewViewControllerDelegate <NSObject>

@optional

/// 取消选择图片后被调用
- (void)imagePickerPreviewViewControllerDidCancel:(QMUIImagePickerPreviewViewController *)imagePickerPreviewViewController;
/// 即将选中图片
- (void)imagePickerPreviewViewController:(QMUIImagePickerPreviewViewController *)imagePickerPreviewViewController willCheckImageAtIndex:(NSInteger)index;
/// 已经选中图片
- (void)imagePickerPreviewViewController:(QMUIImagePickerPreviewViewController *)imagePickerPreviewViewController didCheckImageAtIndex:(NSInteger)index;
/// 即将取消选中图片
- (void)imagePickerPreviewViewController:(QMUIImagePickerPreviewViewController *)imagePickerPreviewViewController willUncheckImageAtIndex:(NSInteger)index;
/// 已经取消选中图片
- (void)imagePickerPreviewViewController:(QMUIImagePickerPreviewViewController *)imagePickerPreviewViewController didUncheckImageAtIndex:(NSInteger)index;

@end


@interface QMUIImagePickerPreviewViewController : QMUIImagePreviewViewController <QMUIImagePreviewViewDelegate>

@property(nonatomic, weak) id<QMUIImagePickerPreviewViewControllerDelegate> delegate;

@property(nonatomic, strong) UIColor *toolBarBackgroundColor UI_APPEARANCE_SELECTOR;
@property(nonatomic, strong) UIColor *toolBarTintColor UI_APPEARANCE_SELECTOR;

@property(nonatomic, strong, readonly) UIView *topToolBarView;
@property(nonatomic, strong, readonly) QMUINavigationButton *backButton;
@property(nonatomic, strong, readonly) QMUIButton *checkboxButton;

/// 由于组件需要通过本地图片的 QMUIAsset 对象读取图片的详细信息，因此这里的需要传入的是包含一个或多个 QMUIAsset 对象的数组
@property(nonatomic, strong) NSMutableArray<QMUIAsset *> *imagesAssetArray;
@property(nonatomic, strong) NSMutableArray<QMUIAsset *> *selectedImageAssetArray;

@property(nonatomic, assign) QMUIAssetDownloadStatus downloadStatus;

/// 最多可以选择的图片数，默认为无穷大
@property(nonatomic, assign) NSUInteger maximumSelectImageCount;
/// 最少需要选择的图片数，默认为 0
@property(nonatomic, assign) NSUInteger minimumSelectImageCount;
/// 选择图片超出最大图片限制时 alertView 的标题
@property(nonatomic, copy) NSString *alertTitleWhenExceedMaxSelectImageCount;
/// 选择图片超出最大图片限制时 alertView 的标题
@property(nonatomic, copy) NSString *alertButtonTitleWhenExceedMaxSelectImageCount;

/**
 *  更新数据并刷新 UI，手工调用
 *
 *  @param imageAssetArray         包含所有需要展示的图片的数组
 *  @param selectedImageAssetArray 包含所有需要展示的图片中已经被选中的图片的数组
 *  @param currentImageIndex       当前展示的图片在 imageAssetArray 的索引
 *  @param singleCheckMode         是否为单选模式，如果是单选模式，则不显示 checkbox
 */
- (void)updateImagePickerPreviewViewWithImagesAssetArray:(NSArray<QMUIAsset *> *)imageAssetArray
                                 selectedImageAssetArray:(NSArray<QMUIAsset *> *)selectedImageAssetArray
                                       currentImageIndex:(NSInteger)currentImageIndex
                                         singleCheckMode:(BOOL)singleCheckMode;

@end


@interface QMUIImagePickerPreviewViewController (UIAppearance)

+ (instancetype)appearance;

@end
