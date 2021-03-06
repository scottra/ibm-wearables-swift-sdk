// Generated by Apple Swift version 2.1.1 (swiftlang-700.1.101.15 clang-700.1.81)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import CoreBluetooth;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

SWIFT_CLASS("_TtC13IBMMobileEdge15DeviceConnector")
@interface DeviceConnector : NSObject
@property (nonatomic, copy) NSString * __nonnull deviceName;
- (void)disconnect;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class CBCentralManager;
@class CBPeripheral;
@class NSError;
@class NSNumber;
@class CBService;
@class CBCharacteristic;

SWIFT_CLASS("_TtC13IBMMobileEdge18BLEDeviceConnector")
@interface BLEDeviceConnector : DeviceConnector <CBPeripheralDelegate, CBCentralManagerDelegate>
@property (nonatomic, readonly, copy) NSString * __nonnull turnOnOperation;
@property (nonatomic, readonly, copy) NSString * __nonnull turnOffOperation;
@property (nonatomic, readonly, copy) NSString * __nonnull notifyOnOperation;
@property (nonatomic, readonly, copy) NSString * __nonnull notifyOffOperation;
- (void)disconnect;
- (void)centralManagerDidUpdateState:(CBCentralManager * __nonnull)central;
- (void)centralManager:(CBCentralManager * __nonnull)central didDisconnectPeripheral:(CBPeripheral * __nonnull)peripheral error:(NSError * __nullable)error;
- (void)centralManager:(CBCentralManager * __nonnull)central didDiscoverPeripheral:(CBPeripheral * __nonnull)peripheral advertisementData:(NSDictionary<NSString *, id> * __nonnull)advertisementData RSSI:(NSNumber * __nonnull)RSSI;
- (void)centralManager:(CBCentralManager * __nonnull)central didConnectPeripheral:(CBPeripheral * __nonnull)peripheral;
- (void)peripheral:(CBPeripheral * __nonnull)peripheral didDiscoverServices:(NSError * __nullable)error;
- (void)peripheral:(CBPeripheral * __nonnull)peripheral didDiscoverCharacteristicsForService:(CBService * __nonnull)service error:(NSError * __nullable)error;
- (void)peripheral:(CBPeripheral * __nonnull)peripheral didUpdateValueForCharacteristic:(CBCharacteristic * __nonnull)characteristic error:(NSError * __nullable)error;
@end


SWIFT_CLASS("_TtC13IBMMobileEdge18BaseInterpretation")
@interface BaseInterpretation : NSObject
- (nonnull instancetype)initWithInterpretationName:(NSString * __nonnull)interpretationName OBJC_DESIGNATED_INITIALIZER;
- (void)registerListener:(void (^ __nonnull)(id __null_unspecified))listener;
- (void)registerStatusListener:(void (^ __nonnull)(id __null_unspecified))listener;
- (void)notifyResult:(id __null_unspecified)additionalInfo;
- (void)nofifyStatusUpdate:(id __null_unspecified)additionalInfo;
- (void)notifyResult;
@end


SWIFT_CLASS("_TtC13IBMMobileEdge14Classification")
@interface Classification : BaseInterpretation
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)loadGesturesByNames:(NSArray<NSString *> * __nonnull)gesturesFileNames;
- (void)loadGesturesByFilePath:(NSArray<NSString *> * __nonnull)gesturesFilePaths;
- (void)setSensitivity:(NSDictionary<NSString *, NSNumber *> * __nonnull)payload;
@end



SWIFT_CLASS("_TtC13IBMMobileEdge27ExtreamTemperatureDetection")
@interface ExtreamTemperatureDetection : BaseInterpretation
- (nonnull instancetype)initWithThreshold:(double)threshold OBJC_DESIGNATED_INITIALIZER;
- (void)setThreshold2:(double)threshold;
@end


SWIFT_CLASS("_TtC13IBMMobileEdge13FallDetection")
@interface FallDetection : BaseInterpretation
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC13IBMMobileEdge9SensorTag")
@interface SensorTag : BLEDeviceConnector
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)setAccelerometerRange:(uint8_t)range;
- (void)setMotionSensorPeriod:(uint8_t)period;
@end

#pragma clang diagnostic pop
