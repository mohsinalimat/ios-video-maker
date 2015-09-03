//
//  BasePickerAssetsDataSource.h
//  VideoEditor2
//
//  Created by Alexander on 9/1/15.
//  Copyright (c) 2015 Onix-Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>

typedef void (^PickerAssetLoadCompletionBlock)(NSError *error);

@interface BaseImageSelectDataSource : NSObject

+(ALAssetsLibrary*) assetLibrary;
-(void) loadAssetsFromGrop: (ALAssetsGroup*) group into: (NSMutableArray*) assets withCmpletion:(PickerAssetLoadCompletionBlock) groupLoaded;

@property (strong, nonatomic) NSArray *assets;
@property (nonatomic) BOOL isLoading;
@property (nonatomic) BOOL supportSearch;
@property (strong, nonatomic) PickerAssetLoadCompletionBlock didFinishLoading;

-(void)loadAssets;

-(NSInteger)getNumberofSectionsInData;
-(NSDictionary*) getAssetsBySections;
-(NSArray*) getSectionsKeys;
-(NSString*) getSectionTitle: (id) sectionKey;

-(void)searchFor: (NSString*) searchTerm withCompletion: (PickerAssetLoadCompletionBlock) onLoad;
-(void)loadMore: (PickerAssetLoadCompletionBlock) onLoad;
-(NSString*) getCurrentSearchTerm;
-(NSArray*) getSeachScopes;
-(NSInteger) selectedSearchScope;
-(void) switchSearhcScope: (NSInteger) searchScope;

@end