@import Foundation;

#import "BTErrors.h"

extern NSString *const BTClientTokenKeyAuthorizationFingerprint;
extern NSString *const BTClientTokenKeyClientApiURL;
extern NSString *const BTClientTokenKeyConfigURL;
extern NSString *const BTClientTokenKeyChallenges;
extern NSString *const BTClientTokenKeyAnalytics;
extern NSString *const BTClientTokenKeyURL;
extern NSString *const BTClientTokenKeyMerchantId;
extern NSString *const BTClientTokenKeyVersion;
extern NSString *const BTClientTokenKeyApplePay;
extern NSString *const BTClientTokenKeyStatus;

extern NSString *const BTClientTokenKeyPayPal;
extern NSString *const BTClientTokenKeyPayPalClientId;
extern NSString *const BTClientTokenKeyPayPalDirectBaseUrl;
extern NSString *const BTClientTokenKeyPayPalMerchantName;
extern NSString *const BTClientTokenKeyPayPalMerchantPrivacyPolicyUrl;
extern NSString *const BTClientTokenKeyPayPalMerchantUserAgreementUrl;
extern NSString *const BTClientTokenKeyPayPalEnvironment;
extern NSString *const BTClientTokenKeyPayPalEnabled;

extern NSString *const BTClientTokenPayPalEnvironmentCustom;
extern NSString *const BTClientTokenPayPalEnvironmentLive;
extern NSString *const BTClientTokenPayPalEnvironmentOffline;

extern NSString *const BTClientTokenKeyPayPalDisableAppSwitch;

extern NSString *const BTClientTokenKeyVenmo;

// Default PayPal merchant name in offline mode
extern NSString *const BTClientTokenPayPalNonLiveDefaultValueMerchantName;

// Default PayPal privacy policy URL in offline mode
extern NSString *const BTClientTokenPayPalNonLiveDefaultValueMerchantPrivacyPolicyUrl;

// Default PayPal user agreement URL in offline mode
extern NSString *const BTClientTokenPayPalNonLiveDefaultValueMerchantUserAgreementUrl;

@interface BTClientToken : NSObject <NSCoding, NSCopying>

#pragma mark Braintree Client API

@property (nonatomic, readonly, copy) NSString *authorizationFingerprint;

@property (nonatomic, readonly, strong) NSURL *clientApiURL;
@property (nonatomic, readonly, strong) NSURL *analyticsURL;
@property (nonatomic, readonly, strong) NSURL *configURL;
@property (nonatomic, readonly, copy) NSString *merchantId;

-(BOOL)analyticsEnabled;

#pragma mark Credit Card Processing

@property (nonatomic, readonly, strong) NSSet *challenges;

#pragma mark PayPal

// Returns the PayPal client id determined by Braintree that
// can be used when initializing `PayPalMobile`.
//
// `nil` if PayPal is not enabled for the merchant.
- (NSString *)btPayPal_clientId;

// Returns a boolean if PayPal is enabled.
- (BOOL) btPayPal_isPayPalEnabled;

// Returns the PayPal environment name
- (NSString *)btPayPal_environment;

- (BOOL)btPayPal_isTouchDisabled;

- (NSString *)btPayPal_merchantName;
- (NSURL *)btPayPal_merchantUserAgreementURL;
- (NSURL *)btPayPal_privacyPolicyURL;

// Returns the base URL determined by Braintree that points
// to a PayPal stage to be used in when configuring `PayPalMobile`.
//
// @see PayPalMobile.h
//
// @return the PayPal stage URL, including a version path appropriate for the vendored PayPal mSDK, or `nil` if mock mode should be used
- (NSURL *)btPayPal_directBaseURL;

#pragma mark Venmo

- (NSString *)btVenmo_status;

#pragma mark Apple Pay

@property (nonatomic, readonly, strong) NSDictionary *applePayConfiguration;

#pragma mark -

- (instancetype)initWithClientTokenString:(NSString *)JSONString error:(NSError **)error NS_DESIGNATED_INITIALIZER;

//// Initialize a client token with a dictionary of claims parsed from the client token string.
//- (instancetype)initWithClaims:(NSDictionary *)claims
//                         error:(NSError * __autoreleasing *)error;

@end
