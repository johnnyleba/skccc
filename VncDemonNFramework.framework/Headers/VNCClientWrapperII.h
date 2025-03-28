#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface VNCClientWrapperII : NSObject

// 初始化 VNC 客户端
- (instancetype)init;
- (BOOL)isConnected;

// 连接到 VNC 服务器
- (BOOL)connectToServer:(NSString *)serverAddress port:(int)port password:(NSString *)password;


// 处理 VNC 事件
- (void)handleEvents;

- (int) getClientErr;

- (BOOL) isAuthErr;

// 发送鼠标事件
- (void)sendMouseEventWithX:(int)x y:(int)y buttonMask:(int)buttonMask;

// 发送键盘事件
//- (void)sendKeyEventWithKey:(rfbKeySym)key pressed:(BOOL)pressed;

// 获取帧缓冲数据
- (uint8_t *)getFrameBuffer;

// 获取帧缓冲宽度
- (int)getFrameBufferWidth;

// 获取帧缓冲高度
- (int)getFrameBufferHeight;

// 释放 VNC 客户端
- (void)releaseClient;

@end

NS_ASSUME_NONNULL_END
