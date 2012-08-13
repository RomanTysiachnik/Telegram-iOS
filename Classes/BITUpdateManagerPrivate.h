/*
 * Author: Andreas Linde <mail@andreaslinde.de>
 *         Peter Steinberger
 *
 * Copyright (c) 2012 HockeyApp, Bit Stadium GmbH.
 * Copyright (c) 2011 Andreas Linde.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#import <UIKit/UIKit.h>


@interface BITUpdateManager () {
}

// set the server URL
@property (nonatomic, retain) NSString *updateURL;

// is an update available?
@property (nonatomic, assign, getter=isUpdateAvailable) BOOL updateAvailable;

// are we currently checking for updates?
@property (nonatomic, assign, getter=isCheckInProgress) BOOL checkInProgress;

@property (nonatomic, retain) NSMutableData *receivedData;

@property (nonatomic, copy) NSDate *lastCheck;

// get array of all available versions
@property (nonatomic, copy) NSArray *appVersions;

@property (nonatomic, retain) NSURLConnection *urlConnection;

@property (nonatomic, copy) NSDate *usageStartTimestamp;

@property (nonatomic, retain) UIView *blockingView;

// if YES, the API will return an existing JMC config
// if NO, the API will return only version information
@property (nonatomic, assign) BOOL checkForTracker;

// Contains the tracker config if received from server
@property (nonatomic, retain) NSDictionary *trackerConfig;


- (id)initWithAppIdentifier:(NSString *)appIdentifier isAppStoreEnvironemt:(BOOL)isAppStoreEnvironment;

- (void)startManager;

// checks for update, informs the user (error, no update found, etc)
- (void)checkForUpdateShowFeedback:(BOOL)feedback;

// initiates app-download call. displays an system UIAlertView
- (BOOL)initiateAppDownload;

// checks wether this app version is authorized
- (BOOL)appVersionIsAuthorized;

// start checking for an authorization key
- (void)checkForAuthorization;

// get/set current active hockey view controller
@property (nonatomic, retain) BITUpdateViewController *currentHockeyViewController;

// convenience method to get current running version string
- (NSString *)currentAppVersion;

// get newest app version
- (BITAppVersionMetaInfo *)newestAppVersion;

// check if there is any newer version mandatory
- (BOOL)hasNewerMandatoryVersion;

@end
