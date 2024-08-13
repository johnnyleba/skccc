/****************************************************************
  copyright   : Copyright (C) 2013-2015, chenbichao,
              : All rights reserved.
              : www.pptun.com, www.peergine.com
              :
  filename    : pgLibTunnel.h
  discription :
  modify      : create, chenbichao, 2013/12/13
              :
              : Modify, chenbichao, 2015/03/31
              : 1.√ø∏ˆAPI∫Ø ˝√˚≥∆º”…œ°∞Tunnel°±«∞◊∫£¨«¯±”⁄∆‰À˚SDKµƒAPI∫Ø ˝√˚
              :
              : Modify, chenbichao, 2015/04/29
              : 1.pgTunnelSysInfo∫Ø ˝‘ˆº”lpszCfgFile≤Œ ˝
              :
              : Modify, chenbichao, 2016/04/26
              : 1.‘ˆº”pgTunnelSetNetCard∫Ø ˝
              :
              : Modify, chenbichao, 2016/11/14
              : 1.‘ˆº”œ¬¡–∫Ø ˝£∫
              :     pgTunnelVersionGet
              :     pgTunnelDomainSet
              :     pgTunnelDomainGet
              :     pgTunnelCommentSet
              :     pgTunnelCommentGet
              :     pgTunnelTunnelSet
              :     pgTunnelConnectAdd
              :     pgTunnelConnectDelete
              :     pgTunnelConnectQuery
              :     pgTunnelConnectLocalDelete
              :     pgTunnelConnectLocalQuery
              :     pgTunnelUserExtend
              :     pgTunnelPushGet
              :
              : Modify, chenbichao, 2017/02/18
              : 1.‘ˆº”pgTunnelStatusGet∫Ø ˝
              :
              : Modify, chenbichao, 2017/06/13
              : 1.‘ˆº”pgTunnelSetCfgParam∫Ø ˝
              :
              : Modify, chenbichao, 2020/04/04
              : 1.‘ˆº”pgTunnelControl∫Ø ˝
              :
              : Modify, chenbichao, 2020/04/27
              : 1.‘ˆº”pgTunnelChannelSet∫Ø ˝
              :
              : Modify, chenbichao, 2023/03/22
              : 1.‘ˆº”pgTunnelPeerFwdCfg∫Ø ˝
              :
              : Modify, chenbichao, 2023/07/10
              : 1.‘ˆº”pgTunnelPeerAuthReply∫Ø ˝
              :
*****************************************************************/
#import <Foundation/Foundation.h>

#ifndef _PG_LIB_TUNNEL_H
#define _PG_LIB_TUNNEL_H


#ifdef __cplusplus
extern "C" {
#endif


/**
 *  ¥ÌŒÛ¬Î∂®“Â
 */
typedef enum tagPG_TUNNEL_ERROR_E {
    PG_TUNNEL_ERROR_OK = 0,             // ≥…π¶
    PG_TUNNEL_ERROR_SYSTEM = -1,        // œµÕ≥¥ÌŒÛ°£
    PG_TUNNEL_ERROR_BADPARAM = -2,      // ¥´µ›µƒ≤Œ ˝¥ÌŒÛ°£
    PG_TUNNEL_ERROR_BADCLASS = -3,      // Œﬁ–ßµƒπ¶ƒ‹¿‡
    PG_TUNNEL_ERROR_BADMETHOD = -4,     // Œﬁ–ßµƒ∑Ω∑®
    PG_TUNNEL_ERROR_BADOBJECT = -5,     // Œﬁ–ßµƒ∂‘œÛ
    PG_TUNNEL_ERROR_BADSTATUS = -6,     // ◊¥Ã¨≤ª’˝»∑°£
    PG_TUNNEL_ERROR_BADFILE = -7,       // Œﬁ–ßµƒŒƒº˛
    PG_TUNNEL_ERROR_BADUSER = -8,       // ”√ªß≤ª¥Ê‘⁄°£
    PG_TUNNEL_ERROR_BADPASS = -9,       // √‹¬Î¥ÌŒÛ
    PG_TUNNEL_ERROR_NOLOGIN = -10,      // Œ¥µ«¬º
    PG_TUNNEL_ERROR_NETWORK = -11,      // Õ¯¬Áπ ’œ
    PG_TUNNEL_ERROR_TIMEOUT = -12,      // ≤Ÿ◊˜≥¨ ±
    PG_TUNNEL_ERROR_REJECT = -13,       // æ‹æ¯≤Ÿ◊˜
    PG_TUNNEL_ERROR_BUSY = -14,         // œµÕ≥’˝√¶
    PG_TUNNEL_ERROR_OPENED = -15,       // ◊ ‘¥“—æ≠¥Úø™
    PG_TUNNEL_ERROR_CLOSED = -16,       // ◊ ‘¥“—æ≠πÿ±’
    PG_TUNNEL_ERROR_EXIST = -17,        // ◊ ‘¥“—æ≠¥Ê‘⁄
    PG_TUNNEL_ERROR_NOEXIST = -18,      // ◊ ‘¥≤ª¥Ê‘⁄
    PG_TUNNEL_ERROR_NOSPACE = -19,      // ø’º‰ªÚ»›¡øœﬁ÷∆
    PG_TUNNEL_ERROR_BADTYPE = -20,      // Œﬁ–ßµƒ¿‡–Õ
    PG_TUNNEL_ERROR_CHECKERR = -21,     // –£—È¥ÌŒÛ
    PG_TUNNEL_ERROR_BADSERVER = -22,    // Œﬁ–ßµƒ∑˛ŒÒ∆˜
    PG_TUNNEL_ERROR_BADDOMAIN = -23,    // Œﬁ–ßµƒ”Ú
    PG_TUNNEL_ERROR_NODATA = -24,       // √ª”– ˝æ›
    PG_TUNNEL_ERROR_UNKNOWN = -255,     // Œ¥÷™¥ÌŒÛ
    PG_TUNNEL_ERROR_NOIMP = -256,       // ∏√π¶ƒ‹√ª”– µœ÷°£
} PG_TUNNEL_ERROR_E;


/**
 *  P2PÕ®µ¿µƒ¡¨Ω”¿‡–Õ
 */
typedef enum tagPG_TUNNEL_CNNT_E {
    PG_TUNNEL_CNNT_Unknown = 0,            // Œ¥÷™£¨ªπ√ª”–ºÏ≤‚µΩ¡¨Ω”¿‡–Õ

    PG_TUNNEL_CNNT_IPV4_Pub = 4,           // π´Õ¯IPv4µÿ÷∑
    PG_TUNNEL_CNNT_IPV4_NATConeFull = 5,   // ÕÍ»´◊∂–ŒNAT
    PG_TUNNEL_CNNT_IPV4_NATConeHost = 6,   // ÷˜ª˙œﬁ÷∆◊∂–ŒNAT
    PG_TUNNEL_CNNT_IPV4_NATConePort = 7,   // ∂Àø⁄œﬁ÷∆◊∂–ŒNAT
    PG_TUNNEL_CNNT_IPV4_NATSymmet = 8,     // ∂‘≥∆NAT

    PG_TUNNEL_CNNT_IPV4_Private = 12,      // ÀΩÕ¯÷±¡¨
    PG_TUNNEL_CNNT_IPV4_NATLoop = 13,      // ÀΩÕ¯NATª∑ªÿ

    PG_TUNNEL_CNNT_IPV4_TunnelTCP = 16,    // TCPv4◊™∑¢
    PG_TUNNEL_CNNT_IPV4_TunnelHTTP = 17,   // HTTPv4◊™∑¢

    PG_TUNNEL_CNNT_IPV4_PeerFwd = 24,      // ΩË÷˙P2PΩ⁄µ„◊™∑¢

    PG_TUNNEL_CNNT_IPV6_Pub = 32,          // π´Õ¯IPv6µÿ÷∑
    PG_TUNNEL_CNNT_IPV6_Local = 36,        // ÀΩÕ¯IPv6µÿ÷∑

    PG_TUNNEL_CNNT_IPV6_TunnelTCP = 40,    // TCPv6◊™∑¢
    PG_TUNNEL_CNNT_IPV6_TunnelHTTP = 41,   // HTTPv6◊™∑¢

    PG_TUNNEL_CNNT_P2P = 128,              // P2P¡¨Ω”
    PG_TUNNEL_CNNT_Local = 129,            // ÀΩÕ¯¡¨Ω”
    PG_TUNNEL_CNNT_PeerForward = 130,      // Ω⁄µ„◊™∑¢¡¨Ω”
    PG_TUNNEL_CNNT_RelayForward = 131,     // ÷–ºÃ◊™∑¢¡¨Ω”

    PG_TUNNEL_CNNT_Offline = 65535,        // ∂‘∂À≤ª‘⁄œﬂ

} PG_TUNNEL_CNNT_E;

/**
 *  ≤È—Ø◊¥Ã¨µƒ—°œÓ
 */
typedef enum tagPG_TUNNEL_GET_STA_E {
    PG_TUNNEL_GET_STA_LOGIN = 0,    // ≤È—Øµ«¬º◊¥Ã¨
} PG_TUNNEL_GET_STA_E;

/**
 *  µ«¬º◊¥Ã¨∂®“Â
 */
typedef enum tagPG_TUNNEL_STA_LOGIN_E {
    PG_TUNNEL_STA_LOGIN_SUCCESS = 0,       // µ«¬º≥…π¶
    PG_TUNNEL_STA_LOGIN_CONFIG = 4,        // º”‘ÿ≈‰÷√Œƒº˛ ß∞‹
    PG_TUNNEL_STA_LOGIN_SYSINFO = 5,       // œµÕ≥–≈œ¢≤Œ ˝¥ÌŒÛ
    PG_TUNNEL_STA_LOGIN_RESOLUTION = 6,    // ”Ú√˚Ω‚Œˆ ß∞‹
    PG_TUNNEL_STA_LOGIN_BUILDACCOUNT = 7,  // …˙≥…’À∫≈–≈œ¢ ß∞‹
    PG_TUNNEL_STA_LOGIN_INITNODE = 8,      // ≥ı ºªØPeergine node ß∞‹
    PG_TUNNEL_STA_LOGIN_INITFAILED = 9,    // ∆‰À˚≥ı ºªØ ß∞‹
    PG_TUNNEL_STA_LOGIN_LOGINFAILED = 10,  // ∑¢ÀÕµ«¬º«Î«Û ß∞‹
    PG_TUNNEL_STA_LOGIN_LOGOUTED = 11,     // “—æ≠◊¢œ˙£®…‘∫Û÷ÿ ‘µ«¬º«Î«Û£©
    PG_TUNNEL_STA_LOGIN_REQUESTING = 16,   // ’˝‘⁄«Î«Ûµ«¬º
    PG_TUNNEL_STA_LOGIN_TIMEOUT = 17,      // µ«¬º¥ÌŒÛ£®«Î«Û≥¨ ±£©
    PG_TUNNEL_STA_LOGIN_NETWORK = 18,      // µ«¬º¥ÌŒÛ£®Õ¯¬Á¥ÌŒÛ£©
    PG_TUNNEL_STA_LOGIN_BADUSER = 19,      // µ«¬º¥ÌŒÛ£®”√ªß√˚¥ÌŒÛ£©
    PG_TUNNEL_STA_LOGIN_BADPASS = 20,      // µ«¬º¥ÌŒÛ£®√‹¬Î¥ÌŒÛ£©
    PG_TUNNEL_STA_LOGIN_REJECT = 21,       // µ«¬º¥ÌŒÛ£®æ‹æ¯∑√Œ £©
    PG_TUNNEL_STA_LOGIN_BUSY = 22,         // µ«¬º¥ÌŒÛ£®∑˛ŒÒ∆˜’˝√¶£©
    PG_TUNNEL_STA_LOGIN_FAILED = 23,       // µ«¬º¥ÌŒÛ£®∆‰À˚µ«¬º ß∞‹£©
    PG_TUNNEL_STA_LOGIN_KICKOUT = 32,      // ”√ªß√˚≥ÂÕª±ª∑˛ŒÒ∆˜Ãﬂœ¬œﬂ
    PG_TUNNEL_STA_LOGIN_UNKNOWN = 255,     // Œ¥÷™◊¥Ã¨
    PG_TUNNEL_STA_LOGIN_EXTEND = 256,      // ”√ªß◊‘∂®“Â¥ÌŒÛ¬Îµƒø™ º
} PG_TUNNEL_STA_LOGIN_E;


/**
 *   ¬º˛ID∂®“Â
 */
typedef enum tagPG_TUNNEL_EVENT_E {
    PG_TUNNEL_EVENT_EXIT = 0,                  // Tunnel SDK ÕÀ≥ˆ
    PG_TUNNEL_EVENT_ERROR = 1,                 // œµÕ≥¥ÌŒÛ£¨¥ÌŒÛ¬Î≤Œøº'PG_TUNNEL_EVENT_ERROR_E'
    PG_TUNNEL_EVENT_LOGIN = 2,                 // µ«¬º£®≥¢ ‘µ«¬º£©µƒΩ·π˚
    PG_TUNNEL_EVENT_LOGOUT = 3,                // ◊¢œ˙µ«¬º
    PG_TUNNEL_EVENT_KICKOUT = 4,               // ”√ªß√˚£®ID£©≥ÂÕª±ªÃﬂœ¬œﬂ
    PG_TUNNEL_EVENT_PEER_UP = 5,               // ”Î∂‘∂ÀµƒP2PÕ®µ¿“—¡¨Ω”
    PG_TUNNEL_EVENT_PEER_DOWN = 6,             // ”Î∂‘∂ÀµƒP2PÕ®µ¿“—∂œø™
    PG_TUNNEL_EVENT_PEER_OFFLINE = 7,          // ∂‘∂À“—æ≠¿Îœﬂ
    PG_TUNNEL_EVENT_CONNECT_ADD = 8,           // ÀÌµ¿”≥…‰ÃÌº”
    PG_TUNNEL_EVENT_CONNECT_DELETE = 9,        // ÀÌµ¿”≥…‰…æ≥˝
    PG_TUNNEL_EVENT_CONNECT_UP = 10,           // ÀÌµ¿”≥…‰“—¡¨Ω”
    PG_TUNNEL_EVENT_CONNECT_DOWN = 11,         // ÀÌµ¿”≥…‰“—∂œø™
    PG_TUNNEL_EVENT_SERVER_PUSH = 12,          // P2P∑˛ŒÒ∆˜Õ∆ÀÕœ˚œ¢
    PG_TUNNEL_EVENT_PEER_INFO = 13,            // P2P¡¨Ω”Õ®µ¿µƒ–≈œ¢
    PG_TUNNEL_EVENT_CONNECT_USED = 14,         // ÀÌµ¿”≥…‰µƒ∂Àø⁄“—æ≠±ª π”√
    PG_TUNNEL_EVENT_PEER_FWD_STATUS = 15,      // Ω⁄µ„◊™∑¢µƒ◊¥Ã¨–≈œ¢
    PG_TUNNEL_EVENT_PEER_FWD_STATISTIC = 16,   // Ω⁄µ„◊™∑¢µƒπ±œ◊Õ≥º∆–≈œ¢
    PG_TUNNEL_EVENT_PEER_FWD_STAT_USED = 17,   // Ω⁄µ„◊™∑¢µƒœ˚∑—Õ≥º∆–≈œ¢
    PG_TUNNEL_EVENT_SESSION_FAILED = 18,       // TCPª·ª∞¡¨Ω”«Î«Û ß∞‹
    PG_TUNNEL_EVENT_PEER_AUTH_REQUEST = 19,    // ”Î∂‘∂À¡¨Ω”µƒ»œ÷§«Î«Û
    PG_TUNNEL_EVENT_PEER_AUTH_RESULT = 20,     // ”Î∂‘∂À¡¨Ω”µƒ»œ÷§Ω·π˚
    PG_TUNNEL_EVENT_SESSION_STATISTIC = 21,    // TCPª·ª∞µƒ◊¥Ã¨Õ≥º∆–≈œ¢
} PG_TUNNEL_EVENT_E;

/**
 *   ¬º˛ 'PG_TUNNEL_EVENT_ERROR' …œ±®µƒ¥ÌŒÛ¬Î
 */
typedef enum tagPG_TUNNEL_EVENT_ERROR_E {
    PG_TUNNEL_EVENT_ERROR_OK = 0,
    PG_TUNNEL_EVENT_ERROR_MEMORY_ALLOC = 1,          // ƒ⁄¥Ê∑÷≈‰ ß∞‹
    PG_TUNNEL_EVENT_ERROR_SOCKET_ACCEPT = 2,         // µ˜”√acceptΩ” ‹TCP client¡¨Ω” ß∞‹
    PG_TUNNEL_EVENT_ERROR_SOCKET_CREATE = 3,         // ¥¥Ω®socket ß∞‹
    PG_TUNNEL_EVENT_ERROR_SOCKET_OPTION = 4,         // …Ë÷√socket option ß∞‹
    PG_TUNNEL_EVENT_ERROR_SOCKET_CONNECT = 5,        // µ˜”√connect¡¨Ω”TCP server ß∞‹
    PG_TUNNEL_EVENT_ERROR_SOCKET_GETADDR = 6,        // µ˜”√getsocknameªÒ»°socket∞Û∂®µƒµÿ÷∑ ß∞‹
    PG_TUNNEL_EVENT_ERROR_SESSION_LIMIT = 7,         // TCP¡¨Ω” ˝¡ø¥ÔµΩ¡ÀMaxSessœﬁ÷∆
    PG_TUNNEL_EVENT_ERROR_SESSION_RESOLUTION = 8,    // TCP«Î«Ûµƒ”Ú√˚Ω‚Œˆ ß∞‹
    PG_TUNNEL_EVENT_ERROR_SESSION_FILTER = 9,        // «Î«Û±ªTCP∑˛ŒÒ∆˜IPµÿ÷∑π˝¬ÀπÊ‘Ú¿πΩÿ
    PG_TUNNEL_EVENT_ERROR_SOCKET_BIND = 10,          // µ˜”√bind∞Û∂®socketµÿ÷∑ ß∞‹
} PG_TUNNEL_EVENT_ERROR_E;

/**
 *  Ω⁄µ„◊™∑¢µƒ◊¥Ã¨
 */
typedef enum tagPG_TUNNEL_PEER_FWD_STA_E {
    PG_TUNNEL_PEER_FWD_STA_DISABLE = 0,    // Ω⁄µ„◊™∑¢Œ™Ω˚”√°£
    PG_TUNNEL_PEER_FWD_STA_PAUSE = 1,      // Ω⁄µ„◊™∑¢Œ™‘›Õ££¨“ÚŒ™±æ∂À’˝‘⁄ π”√Õ¯¬Á¥¯øÌ°£
    PG_TUNNEL_PEER_FWD_STA_IDLE = 2,       // Ω⁄µ„◊™∑¢Œ™∆Ù”√£¨«“µ±«∞ø’œ–°£
    PG_TUNNEL_PEER_FWD_STA_USED = 3,       // Ω⁄µ„◊™∑¢Œ™∆Ù”√£¨«“µ±«∞’˝‘⁄–≠÷˙◊™∑¢°£
} PG_TUNNEL_PEER_FWD_STA_E;

/**
 *  øÿ÷∆∂Ø◊˜ID∂®“Â
 */
typedef enum tagPG_TUNNEL_CONTROL_E {
    PG_TUNNEL_CONTROL_LOGIN_NOW   = 0,     // ÷–∂œÕÀ±‹£¨¡¢º¥µ«¬º
    PG_TUNNEL_CONTROL_RELOAD_CFG  = 1,     // ÷ÿ–¬◊∞‘ÿ≈‰÷√≤Œ ˝
} PG_TUNNEL_CONTROL_E;

/**
 *  ¥´ ‰Õ®µ¿¿‡–Õ∂®“Â
 */
typedef enum tagPG_TUNNEL_CHANNEL_E {
    PG_TUNNEL_CHANNEL_AUTO  = 0,           // ◊‘∂Ø  ”¶P2P¥©Õ∏Õ®µ¿∫ÕRelay◊™∑¢Õ®µ¿£®ƒ¨»œ£©
    PG_TUNNEL_CHANNEL_P2P   = 1,           // ÷ª π”√P2P¥©Õ∏Õ®µ¿
    PG_TUNNEL_CHANNEL_RELAY = 2,           // «ø÷∆ π”√Relay◊™∑¢Õ®µ¿
} PG_TUNNEL_CHANNEL_E;

/**
 *  ª·ª∞¥´ ‰µƒ∑ΩœÚ∂®“Â
 */
typedef enum tagPG_TUNNEL_SESS_DIR_E {
    PG_TUNNEL_SESS_DIR_RECV  = 0,           // Ω” ’∑ΩœÚ
    PG_TUNNEL_SESS_DIR_SEND  = 1,           // ∑¢ÀÕ∑ΩœÚ
} PG_TUNNEL_SESS_DIR_E;

/**
 * ∞Ê±æ–≈œ¢Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_VERSION_S {
    char szVersion[64];             // ∞Ê±æ–≈œ¢
} PG_TUNNEL_VERSION_S;

/**
 * ◊¥Ã¨–≈œ¢Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_STATUS_S {
    unsigned int uStatus;           // ◊¥Ã¨–≈œ¢£¨º˚'PG_TUNNEL_STA_LOGIN_E'√∂æŸ∂®“Â
} PG_TUNNEL_STATUS_S;

/**
 * ”Ú√˚≥∆Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_DOMAIN_S {
    char szDomain[128];             // ”Ú√˚≥∆
} PG_TUNNEL_DOMAIN_S;

/**
 * øÕªß∂ÀÀµ√˜Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_COMMENT_S {
    char szComment[256];            // øÕªß∂ÀÀµ√˜–≈œ¢
} PG_TUNNEL_COMMENT_S;

/**
 * P2PÕ®µ¿–≈œ¢Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_PEER_INFO_S {
    char szPeerID[128];             // ∂‘∂Àµƒ”√ªßID
    unsigned int uType;             // P2PÕ®µ¿¿‡–Õ£¨º˚√∂æŸ°ÆPG_TUNNEL_CNNT_E°Ø∂®“Â°£
    char szAddrLocal[64];           // ±æ∂Àµƒµ«¬ºµÿ÷∑∂Àø⁄
    char szAddrRemote[64];          // ∂‘∂Àµƒµ«¬ºµÿ÷∑∂Àø⁄
    char szTunnelLocal[64];         // ±æ∂ÀµƒÕ®µ¿µÿ÷∑∂Àø⁄
    char szTunnelRemote[64];        // ∂‘∂ÀµƒÕ®µ¿µÿ÷∑∂Àø⁄
    char szPrivateRemote[64];       // ∂‘∂ÀµƒÀΩÕ¯µÿ÷∑∂Àø⁄
} PG_TUNNEL_PEER_INFO_S;

/**
 * øÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_CLIENT_ADDR_S {
    char szClientAddr[64];          // ±æ∂ÀµƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄
} PG_TUNNEL_CLIENT_ADDR_S;

/**
 * ÀÌµ¿¡¨Ω”–≈œ¢Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_CONNECT_INFO_S {
    char szPeerID[128];             // ∂‘∂Àµƒ”√ªßID
    unsigned int uType;             // ÀÌµ¿¡¨Ω”µƒ¿‡–Õ
    unsigned int uEncrypt;          //  «∑Òº”√‹
    char szListenAddr[64];          // ∂‘∂Àµƒ’ÏÃ˝µÿ÷∑∂Àø⁄
    char szClientAddr[64];          // ±æ∂ÀµƒøÕªß∂Àµÿ÷∑∂Àø⁄
} PG_TUNNEL_CONNECT_INFO_S;

/**
 * ◊‘∂®“Â ˝æ›Ω·ππÃÂ
 */
typedef struct tagPG_TUNNEL_DATA_S {
    unsigned int uSize;             // ÷∏√˜ 'szData' ª∫≥Â«¯µƒ≥§∂»£®◊÷Ω⁄£©
    char szData[4];                 // Ω” ’ ˝æ›µƒª∫≥Â«¯
} PG_TUNNEL_DATA_S;

/**
 * ±æ∂Àµƒ”√ªßP2P IDΩ·ππÃÂ
 */
typedef struct tagPG_TUNNEL_SELF_S {
    char szSelf[128];               // ±æ∂Àµƒ”√ªßP2P ID
} PG_TUNNEL_SELF_S;


/**
 *  »’÷æ ‰≥ˆªÿµ˜∫Ø ˝
 *
 *  uLevel£∫[IN] »’÷æº∂±
 *
 *  lpszOut£∫[IN] »’÷æ ‰≥ˆƒ⁄»›
 */
typedef void (*TfnTunnelLogOut)(unsigned int uLevel, const char* lpszOut);


/**
 *   ¬º˛…œ±®ªÿµ˜∫Ø ˝
 *
 *  uEvent£∫[IN]  ¬º˛ID£¨≤Œøº√∂æŸ'PG_TUNNEL_EVENT_E'∂®“Â
 *
 *  lpszParam£∫[IN]  ¬º˛≤Œ ˝
 */
typedef void (*TfnTunnelEventProc)(unsigned int uEvent, const char* lpszParam);


/**
 *  √Ë ˆ£∫◊¢≤·ªÿµ˜∫Ø ˝Ω”ø⁄°£
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  pfnEventProc [IN]  ¬º˛…œ±®ªÿµ˜∫Ø ˝µƒ÷∏’Î°£ªÿµ˜∫Ø ˝‘≠–Õº˚°ÆTfnTunnelEventProc°Ø∂®“Â°£
 */
void pgTunnelCallbackSet(TfnTunnelEventProc pfnEventProc);


/**
 *  √Ë ˆ£∫∆Ù∂Ø Peergine tunnel ƒ£øÈ
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpszCfgFile£∫[IN] ≈‰÷√Œƒº˛µƒ¬∑æ∂
 *
 *  lpszSysInfo£∫[IN] …Ë±∏µƒœµÕ≥–≈œ¢°£ø…“‘”√pgTunnelSysInfo()∏®÷˙∫Ø ˝ªÒ»°°£
 *      ∏Ò Ω£∫"(DevID){1234}(MacAddr){}(CpuMHz){1}(MemSize){1}(BrwVer){}(OSVer){}(OSSpk){}(OSType){}"
 *      ‘⁄ª®¿®∫≈÷–ÃÓ»Î≤Œ ˝µƒ÷µ£¨∆‰÷–°∞DevID°± «±ÿ–Îµƒ£¨∆‰À˚≤Œ ˝ «ø…—°µƒ°£
 *
 *  lpvParam£∫[IN] ◊‘∂®“Â≤Œ ˝£¨±£¡Ù°£
 *
 *  pfnLogOut£∫[IN] »’÷æ ‰≥ˆªÿµ˜∫Ø ˝µƒ÷∏’Î°£ªÿµ˜∫Ø ˝‘≠–Õº˚°ÆTfnTunnelLogOut°Ø∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelStart(const char* lpszCfgFile, const char* lpszSysInfo,
    void* lpvParam, TfnTunnelLogOut pfnLogOut);


/**
 *  √Ë ˆ£∫Õ£÷π Peergine tunnel ƒ£øÈ°£
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 */
void pgTunnelStop();


/**
*  √Ë ˆ£∫÷±Ω”…Ë÷√≈‰÷√Œƒº˛≤Œ ˝ƒ⁄»›
*       ◊¢“‚£∫±ÿ–Î‘⁄pgTunnelStart()÷Æ«∞µ˜”√°£
*       “ÚŒ™≈‰÷√Œƒº˛¿Ô”–“ª–©√Ù∏–µƒ√˜Œƒ–≈œ¢£¨À˘“‘”––©≥°æ∞œ¬≤ªœ£Õ˚”√ªßø¥µΩ≈‰÷√Œƒº˛µƒƒ⁄»›°£
*       ’‚÷÷≥°æ∞œ¬£¨ø…“‘µ˜”√¥À∫Ø ˝÷±Ω”∞—≈‰÷√Œƒº˛µƒƒ⁄»›…Ë÷√±£¥ÊµΩSDKµƒƒ⁄≤ø±‰¡ø÷–£¨∂¯≤ª–Ë“™‘ŸÃ·π©“ª∏ˆ≈‰÷√Œƒº˛°£
*
*  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
*
*  lpszCfgParam£∫[IN] ≈‰÷√≤Œ ˝ƒ⁄»›(∏Ò Ω∫Õƒ⁄»›≤Œøº≈‰÷√Œƒº˛≤Œ ˝Àµ√˜)
*
*  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
*/
int pgTunnelSetCfgParam(const char* lpszCfgParam);


/**
 *  √Ë ˆ£∫ªÒ»°µ±«∞…Ë±∏µƒœµÕ≥–≈œ¢°£(∏®÷˙∫Ø ˝£¨”––©…Ë±∏ªÚ≤Ÿ◊˜œµÕ≥…œ√ª”– µœ÷)
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpszCfgFile£∫[IN] ≈‰÷√Œƒº˛¬∑æ∂°£(¥”≈‰÷√Œƒº˛ªÒ»°…≥∫–µƒ¬∑æ∂£¨LOGŒƒº˛∫Õ¡Ÿ ±Œƒº˛Ω´–¥µΩ…≥∫–ƒø¬º)°£
 *
 *  lpszInfo£∫[OUT] Ω” ‹œµÕ≥–≈œ¢µƒª∫≥Â«¯°£
 *
 *  uSize£∫[IN] °∞lpszInfo°±ª∫≥Â«¯µƒ≥§∂»°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelSysInfo(const char* lpszCfgFile, char* lpszInfo, unsigned int uSize);


/**
 *  √Ë ˆ£∫÷∏∂® π”√µƒÕ¯ø®°£(∏®÷˙∫Ø ˝£¨‘⁄LINUXœµÕ≥”– µœ÷°£)
 *       ◊¢“‚£∫±ÿ–Î‘⁄pgTunnelStart()÷Æ«∞µ˜”√°£
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpszNetCard£∫[IN] ÷∏∂®µƒÕ¯ø®Ω”ø⁄√˚≥∆£¨¿˝»Á£∫eth0, eth1, ...
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelSetNetCard(const char* lpszNetCard);


/**
 *  √Ë ˆ£∫ªÒ»°pgLibTunnel SDKµƒ∞Ê±æ∫≈
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpstVersion£∫[OUT] ∞Ê±æ∫≈–≈œ¢£¨º˚'PG_TUNNEL_VERSION_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelVersionGet(PG_TUNNEL_VERSION_S* lpstVersion);


/**
 *  √Ë ˆ£∫ªÒ»°µ«¬ºµΩP2P∑˛ŒÒ∆˜µƒ◊¥Ã¨
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  uOption£∫[IN] —°œÓ£¨º˚'PG_TUNNEL_GET_STA_E'∂®“Â°£
 *
 *  lpstStatus£∫[OUT] ◊¥Ã¨–≈œ¢£¨º˚'PG_TUNNEL_STATUS_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelStatusGet(unsigned int uOption, PG_TUNNEL_STATUS_S* lpstStatus);


/**
 *  √Ë ˆ£∫…Ë÷√”Ú ∂±¬Î£¨∞—±æøÕªß∂Àº”»ÎµΩ∏√ ∂±¬Î∂‘”¶µƒ”√ªß”Ú¿Ô°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszPasscode£∫[IN] ”Úµƒ ∂±¬Î°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelDomainSet(const char* lpszPasscode);


/**
 *  √Ë ˆ£∫ªÒ»°øÕªß∂Àµ±«∞µƒ”Ú√˚≥∆°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpstDomain£∫[OUT] ”Úµƒ√˚≥∆£¨º˚'PG_TUNNEL_DOMAIN_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelDomainGet(PG_TUNNEL_DOMAIN_S* lpstDomain);


/**
 *  √Ë ˆ£∫…Ë÷√øÕªß∂ÀµƒÀµ√˜°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszComment£∫[IN] øÕªß∂ÀµƒÀµ√˜°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelCommentSet(const char* lpszComment);


/**
 *  √Ë ˆ£∫ªÒ»°øÕªß∂ÀµƒÀµ√˜°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpstComment£∫[OUT] øÕªß∂ÀµƒÀµ√˜–≈œ¢£¨º˚'PG_TUNNEL_COMMENT_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelCommentGet(PG_TUNNEL_COMMENT_S* lpstComment);


/**
 *  √Ë ˆ£∫…Ë÷√øÕªß∂Àµƒ”Ú ∂±¬Î∫ÕÀµ√˜°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszPasscode£∫[IN] øÕªß∂Àµƒ”Ú ∂±¬Î°£
 *
 *  lpszComment£∫[IN] øÕªß∂ÀµƒÀµ√˜–≈œ¢°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelTunnelSet(const char* lpszPasscode, const char* lpszComment);


/**
 *  √Ë ˆ£∫ªÒ»°±æøÕªß∂À∫Õ÷∏∂®”√ªßIDµƒ‘∂≥ÃøÕªß∂À÷Æº‰µƒP2PÕ®µ¿–≈œ¢°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszPeerID£∫[IN] ∂‘∂ÀøÕªß∂Àµƒ”√ªßID°£
 *
 *  lpstPeerInfo£∫[OUT] P2PÕ®µ¿µƒ–≈œ¢£¨º˚'PG_TUNNEL_PEER_INFO_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelPeerInfoGet(const char* lpszPeerID, PG_TUNNEL_PEER_INFO_S* lpstPeerInfo);


/**
 *  √Ë ˆ£∫±æøÕªß∂À∫Õ÷∏∂®”√ªßIDµƒ‘∂≥ÃøÕªß∂À÷Æº‰ÃÌº”“ªÃıÀÌµ¿¡¨Ω”°£
 *        »Áπ˚ÃÌº”≥…π¶£¨∑µªÿ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄–≈œ¢°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszSession£∫[IN] µ«¬ºª·ª∞ID°£
 *      £®ø…—°£¨¥´ø’◊÷∑˚¥Æ£¨÷ª”–‘⁄P2P∑˛ŒÒ∆˜∂Àø™∆Ùµ«¬ºª·ª∞—È÷§µƒ ±∫Ú–Ë“™¥´»Î”––ß÷µ£©
 *
 *  lpszPeerID£∫[IN] ∂‘∂ÀøÕªß∂Àµƒ”√ªßID°£
 *
 *  uType£∫[IN] ÀÌµ¿¡¨Ω”µƒ¿‡–Õ£¨0:Œ™TCP¡¨Ω”£¨1Œ™HTTP¥˙¿Ì¡¨Ω”
 *
 *  uEncrypt£∫[IN] ÀÌµ¿¡¨Ω” «∑Òº”√‹£¨0Œ™≤ªº”√‹£¨1Œ™º”√‹°£
 *
 *  lpszListenAddr£∫[IN] ∂‘∂ÀTCP∑˛ŒÒ∆˜µƒ’ÏÃ˝µÿ÷∑∂Àø⁄°£
 *
 *  lpszClientAddr£∫[IN] ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄°£
 *      »Áπ˚¥´ø’◊÷∑˚¥Æ£¨‘Ú”…P2P∑˛ŒÒ∆˜◊‘∂Ø∑÷≈‰µÿ÷∑∂Àø⁄°£
 *
 *  lpstClientAddr£∫[OUT] øÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄–≈œ¢£¨º˚'PG_TUNNEL_CLIENT_ADDR_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelConnectAdd(const char* lpszSession, const char* lpszPeerID,
    unsigned int uType, unsigned int uEncrypt, const char* lpszListenAddr,
    const char* lpszClientAddr, PG_TUNNEL_CLIENT_ADDR_S* lpstClientAddr);


/**
 *  √Ë ˆ£∫…æ≥˝“ªÃıÀÌµ¿¡¨Ω”°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszSession£∫[IN] µ«¬ºª·ª∞ID°£
 *      £®ø…—°£¨¥´ø’◊÷∑˚¥Æ£¨÷ª”–‘⁄P2P∑˛ŒÒ∆˜∂Àø™∆Ùµ«¬ºª·ª∞—È÷§µƒ ±∫Ú–Ë“™¥´»Î”––ß÷µ£©
 *
 *  lpszPeerID£∫[IN] ∂‘∂ÀøÕªß∂Àµƒ”√ªßID°£
 *
 *  uType£∫[IN] ÀÌµ¿¡¨Ω”µƒ¿‡–Õ£¨0:Œ™TCP¡¨Ω”£¨1Œ™HTTP¥˙¿Ì¡¨Ω”
 *
 *  uEncrypt£∫[IN] ÀÌµ¿¡¨Ω” «∑Òº”√‹£¨0Œ™≤ªº”√‹£¨1Œ™º”√‹°£
 *
 *  lpszListenAddr£∫[IN] ∂‘∂ÀTCP∑˛ŒÒ∆˜µƒ’ÏÃ˝µÿ÷∑∂Àø⁄°£
 *
 *  lpszClientAddr£∫[IN] ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄°£
 *      »Áπ˚¥´ø’◊÷∑˚¥Æ£¨‘Ú…æ≥˝”…°∞lpszPeerID°¢uType°¢uEncrypt°¢lpszListenAddr°±’‚4∏ˆ≤Œ ˝∆•≈‰µƒÀÌµ¿¡¨Ω”°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelConnectDelete(const char* lpszSession, const char* lpszPeerID,
    unsigned int uType, unsigned int uEncrypt, const char* lpszListenAddr,
    const char* lpszClientAddr);


/**
 *  √Ë ˆ£∫ªÒ»°“ªÃıÀÌµ¿¡¨Ω”µƒ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszPeerID£∫[IN] ∂‘∂ÀøÕªß∂Àµƒ”√ªßID°£
 *
 *  uType£∫[IN] ÀÌµ¿¡¨Ω”µƒ¿‡–Õ£¨0:Œ™TCP¡¨Ω”£¨1Œ™HTTP¥˙¿Ì¡¨Ω”
 *
 *  uEncrypt£∫[IN] ÀÌµ¿¡¨Ω” «∑Òº”√‹£¨0Œ™≤ªº”√‹£¨1Œ™º”√‹°£
 *
 *  lpszListenAddr£∫[IN] ∂‘∂ÀTCP∑˛ŒÒ∆˜µƒ’ÏÃ˝µÿ÷∑∂Àø⁄°£
 *
 *  lpstClientAddr£∫[OUT] ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄–≈œ¢£¨º˚'PG_TUNNEL_CLIENT_ADDR_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelConnectQuery(const char* lpszPeerID, unsigned int uType, unsigned int uEncrypt,
    const char* lpszListenAddr, PG_TUNNEL_CLIENT_ADDR_S* lpstClientAddr);


/**
 *  √Ë ˆ£∫∏˘æ›±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄–≈œ¢…æ≥˝“ªÃıÀÌµ¿¡¨Ω”°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszSession£∫[IN] µ«¬ºª·ª∞ID°£
 *      £®ø…—°£¨¥´ø’◊÷∑˚¥Æ£¨÷ª”–‘⁄P2P∑˛ŒÒ∆˜∂Àø™∆Ùµ«¬ºª·ª∞—È÷§µƒ ±∫Ú–Ë“™¥´»Î”––ß÷µ£©
 *
 *  lpszClientAddr£∫[IN] ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelConnectLocalDelete(const char* lpszSession, const char* lpszClientAddr);


/**
 *  √Ë ˆ£∫∏˘æ›±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄–≈œ¢ªÒ»°“ªÃıÀÌµ¿¡¨Ω”µƒ»´≤ø–≈œ¢°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszClientAddr£∫[IN] ±æ∂À”≥…‰µƒøÕªß∂À¡¨Ω”µÿ÷∑∂Àø⁄°£
 *
 *  lpstConnectInfo£∫[OUT] ÀÌµ¿¡¨Ω”µƒ»´≤ø–≈œ¢£¨º˚'PG_TUNNEL_CONNECT_INFO_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelConnectLocalQuery(const char* lpszClientAddr, PG_TUNNEL_CONNECT_INFO_S* lpstConnectInfo);


/**
 *  √Ë ˆ£∫∑¢ÀÕ◊‘∂®“Â«Î«Û∏¯P2P∑˛ŒÒ∆˜£¨≤¢Ω” ’∑˛ŒÒ∆˜µƒ”¶¥°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpszRequestData£∫[IN] ∑¢ÀÕ∏¯∑˛ŒÒ∆˜µƒ«Î«Û ˝æ›°£
 *
 *  lpstReplyData£∫[OUT] Ω” ’µΩ∑˛ŒÒ∆˜µƒ∑µªÿ ˝æ›°£
 *
 *  uTimeout£∫[IN] µ»¥˝≥¨ ± ±º‰£®∫¡√Î£©°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelUserExtend(const char* lpszRequestData, PG_TUNNEL_DATA_S* lpstReplyData, unsigned int uTimeout);


/**
 *  √Ë ˆ£∫Ω” ’P2P∑˛ŒÒ∆˜œ¬∑¢µƒÕ∆ÀÕœ˚œ¢°£
 *
 *  ◊Ë»˚∑Ω Ω£∫»Áπ˚øÕªß∂Àµƒª∫≥Â«¯÷–“—æ≠”–œ¬Õ∆µƒœ˚œ¢ ˝æ›£¨‘Ú¡¢º¥∑µªÿª∫≥Â«¯¿Ôµƒœ˚œ¢ ˝æ›°£
 *            »Áπ˚øÕªß∂Àµƒª∫≥Â«¯÷–ªπ√ª”–œ¬Õ∆µƒœ˚œ¢ ˝æ›£¨‘Úµ»¥˝P2P∑˛ŒÒ∆˜œ¬Õ∆œ˚œ¢ ˝æ›°£
 *
 *  lpstPushData£∫[OUT] Ω” ’µΩ∑˛ŒÒ∆˜µƒÕ∆ÀÕœ˚œ¢ ˝æ›°£
 *
 *  uTimeout£∫[IN] µ»¥˝≥¨ ± ±º‰£®∫¡√Î£©°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelPushGet(PG_TUNNEL_DATA_S* lpstPushData, unsigned int uTimeout);


/**
 *  √Ë ˆ£∫ªÒ»°±æ∂Àµƒ”√ªßID°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  lpstSelf[OUT] Ω” ’µΩ±æ∂Àµƒ”√ªßID°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelSelfGet(PG_TUNNEL_SELF_S* lpstSelf);


/**
 *  √Ë ˆ£∫∏˘æ›À˜“˝÷ÃıªÒ»°ÀÌµ¿¡¨Ω”µƒ»´≤ø–≈œ¢°£
 *
 *  ◊Ë»˚∑Ω Ω£∫◊Ë»˚£¨µ»¥˝∑˛ŒÒ∆˜÷¥––≤Ÿ◊˜°£
 *
 *  uIndex [IN] ÀÌµ¿µƒÀ˜“˝∫≈£∫0, 1, 2, 3, 4, ...
 *
 *  lpstConnectInfo£∫[OUT] ÀÌµ¿¡¨Ω”µƒ»´≤ø–≈œ¢£¨º˚'PG_TUNNEL_CONNECT_INFO_S'∂®“Â°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelConnectEnum(unsigned int uIndex, PG_TUNNEL_CONNECT_INFO_S* lpstConnectInfo);


/**
 *  √Ë ˆ£∫÷¥––∂‘ÀÌµ¿µƒøÿ÷∆≤Ÿ◊˜
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  uCtrl [IN] øÿ÷∆∂Ø◊˜ID£¨º˚'PG_TUNNEL_CONTROL_E'∂®“Â°£
 *
 *  lpszParam [IN] øÿ÷∆∂Ø◊˜µƒ≤Œ ˝£¨‘§¡Ù∏¯“‘∫Û π”√°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelControl(unsigned int uCtrl, const char* lpszParam);


/**
 *  √Ë ˆ£∫…Ë÷√”Î∂‘∂ÀÕ®–≈µƒÕ®µ¿¿‡–Õ
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpszPeerID£∫[IN] ∂‘∂ÀøÕªß∂Àµƒ”√ªßID°£
 *
 *  uType [IN] Õ®µ¿¿‡–Õ£¨º˚'PG_TUNNEL_CHANNEL_E'∂®“Â°£
 *
 *  lpszParam [IN] ≤Œ ˝£¨‘§¡Ù∏¯“‘∫Û π”√°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelChannelSet(const char* lpszPeerID, unsigned int uType, const char* lpszParam);


/**
 *  √Ë ˆ£∫∂ØÃ¨…Ë÷√Ω⁄µ„◊™∑¢µƒ≤Œ ˝
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  iSpeed [IN] ‘ –Ì±æΩ⁄µ„◊˜Œ™◊™∑¢Ω⁄µ„°£
 *      –°”⁄0£∫≤ª∏ƒ±‰∏√≈‰÷√≤Œ ˝£¨¥Û”⁄0£∫‘ –Ì◊™∑¢µƒ¥¯øÌ(◊÷Ω⁄/√Î)£¨0£∫Ω˚”√◊™∑¢°£
 *
 *  iGate [IN] ±æΩ⁄µ„¥•∑¢Õ£÷π–≠÷˙◊™∑¢µƒ◊‘”√¥¯øÌµƒ„–÷µ(◊÷Ω⁄/√Î)°£
 *      –°”⁄0£∫≤ª∏ƒ±‰∏√≈‰÷√≤Œ ˝£¨¥Û”⁄ªÚµ»”⁄0£∫÷∏∂®„–÷µ°£ƒ¨»œ£∫262144
 *
 *  iUse [IN] ±æΩ⁄µ„ «∑Ò π”√∆‰À˚Ω⁄µ„◊˜Œ™◊™∑¢Ω⁄µ„°£
 *      –°”⁄0£∫≤ª∏ƒ±‰∏√≈‰÷√≤Œ ˝£¨¥Û”⁄0£∫ «£¨0£∫∑Ò°£ƒ¨»œ£∫1°£
 *
 *  iMaxSess [IN] ±æΩ⁄µ„–≠÷˙◊™∑¢◊Ó¥Ûª·ª∞ ˝°£
 *      –°”⁄0£∫≤ª∏ƒ±‰∏√≈‰÷√≤Œ ˝£¨¥Û”⁄ªÚµ»”⁄0£∫÷∏∂®◊Ó¥Ûª·ª∞ ˝°£ƒ¨»œ£∫3°£
 *
 *  lpszOption [IN] —°œÓ£¨‘§¡Ù∏¯“‘∫Û π”√°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelPeerFwdCfg(int iSpeed, int iGate, int iUse, int iMaxSess, const char* lpszOption);


/**
 *  √Ë ˆ£∫…Ë÷√”Î∂‘∂À¡¨Ω”µƒ»œ÷§–≈œ¢
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpszPeerID£∫[IN] ∂‘∂ÀøÕªß∂Àµƒ”√ªßID°£
 *
 *  lpszAuthInfo [IN] »œ÷§–≈œ¢≤Œ ˝°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelPeerAuthSet(const char* lpszPeerID, const char* lpszAuthInfo);


/**
 *  √Ë ˆ£∫”¶¥”Î∂‘∂À¡¨Ω”µƒ»œ÷§«Î«Û
 *
 *  ◊Ë»˚∑Ω Ω£∫∑«◊Ë»˚£¨¡¢º¥∑µªÿ°£
 *
 *  lpszHandle[IN] —È÷§«Î«Û 'PG_TUNNEL_EVENT_PEER_AUTH_REQUEST'  ¬º˛÷–µƒhandle≤Œ ˝÷µ°£
 *
 *  uErrCode [IN] ”¶¥µƒ¥ÌŒÛ¬Î£¨Õ®π˝ 'PG_TUNNEL_EVENT_PEER_AUTH_RESULT'  ¬º˛∑µªÿ∏¯¡¨Ω”«Î«Û∂À°£
 *                ∏˘æ›»œ÷§Ω·π˚ π”√“‘œ¬÷µ÷–µƒ“ª∏ˆ£∫
 *                  PG_TUNNEL_ERROR_OK (0)£∫—È÷§≥…π¶£¨
 *                  -PG_TUNNEL_ERROR_REJECT (13)£∫æ‹æ¯≤Ÿ◊˜£®«∞√Êµƒ'-'Œ™∏∫∫≈£©£¨
 *                  -PG_TUNNEL_ERROR_BADUSER (8)£∫”√ªß√˚¥ÌŒÛ£®«∞√Êµƒ'-'Œ™∏∫∫≈£©£¨
 *                  -PG_TUNNEL_ERROR_BADPASS (9)£∫√‹¬Î¥ÌŒÛ£®«∞√Êµƒ'-'Œ™∏∫∫≈£©°£
 *
 *  lpszParam [IN] ø…—°≤Œ ˝£¨Õ®π˝ 'PG_TUNNEL_EVENT_PEER_AUTH_RESULT'  ¬º˛∑µªÿ∏¯¡¨Ω”«Î«Û∂À°£
 *
 *  ∑µªÿ÷µ£∫º˚√∂æŸ°ÆPG_TUNNEL_ERROR_E°Øµƒ∂®“Â
 */
int pgTunnelPeerAuthReply(const char* lpszHandle, unsigned int uErrCode, const char* lpszParam);


#ifdef __cplusplus
}
#endif


#endif // _PG_LIB_TUNNEL_H
