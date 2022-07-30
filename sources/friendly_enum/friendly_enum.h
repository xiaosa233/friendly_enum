#include "friendly_enum/enum_traiter.h"

#define _fenum_select(                                                                             \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,     \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
    _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, \
    _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, \
    _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, \
    _97, _98, _99, _100, _101, _102, _103, _104, _105, _106, _107, _108, _109, _110, _111, _112,   \
    _113, _114, _115, _116, _117, _118, _119, _120, _121, _122, _123, _124, _125, _126, _127,      \
    _128, _129, _130, _131, _132, _133, _134, _135, _136, _137, _138, _139, _140, _141, _142,      \
    _143, _144, _145, _146, _147, _148, _149, _150, _151, _152, _153, _154, _155, _156, _157,      \
    _158, _159, _160, _161, _162, _163, _164, _165, _166, _167, _168, _169, _170, _171, _172,      \
    _173, _174, _175, _176, _177, _178, _179, _180, _181, _182, _183, _184, _185, _186, _187,      \
    _188, _189, _190, _191, _192, _193, _194, _195, _196, _197, _198, _199, _200, _201, _202,      \
    _203, _204, _205, _206, _207, _208, _209, _210, _211, _212, _213, _214, _215, _216, _217,      \
    _218, _219, _220, _221, _222, _223, _224, _225, _226, _227, _228, _229, _230, _231, _232,      \
    _233, _234, _235, _236, _237, _238, _239, _240, _241, _242, _243, _244, _245, _246, _247,      \
    _248, _249, _250, _251, _252, _253, _254, _255, _256, n, ...)                                  \
  n
#define _fenum_n                                                                                   \
  256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238,   \
      237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220,    \
      219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202,    \
      201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184,    \
      183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166,    \
      165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148,    \
      147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130,    \
      129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112,    \
      111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92,  \
      91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69,  \
      68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46,  \
      45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23,  \
      22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

#define _fenum_dispatch_n2(n) _fenum##n
#define _fenum_dispatch_n(n) _fenum_dispatch_n2(n)
#define _fenum_helper(N) _fenum_select N

// _fenumn(1,2,3,n) --> _fenumn
#define _fenumn(...) _fenum_dispatch_n(_fenum_helper((__VA_ARGS__, _fenum_n)))

#define _fenum1(EnumType, First) EnumType::First
#define _fenum2(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum3(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum4(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum5(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum6(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum7(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum8(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum9(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum10(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum11(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum12(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum13(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum14(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum15(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum16(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum17(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum18(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum19(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum20(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum21(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum22(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum23(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum24(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum25(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum26(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum27(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum28(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum29(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum30(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum31(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum32(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum33(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum34(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum35(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum36(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum37(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum38(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum39(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum40(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum41(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum42(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum43(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum44(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum45(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum46(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum47(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum48(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum49(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum50(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum51(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum52(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum53(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum54(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum55(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum56(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum57(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum58(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum59(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum60(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum61(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum62(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum63(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum64(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum65(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum66(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum67(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum68(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum69(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum70(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum71(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum72(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum73(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum74(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum75(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum76(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum77(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum78(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum79(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum80(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum81(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum82(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum83(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum84(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum85(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum86(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum87(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum88(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum89(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum90(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum91(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum92(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum93(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum94(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum95(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum96(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum97(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum98(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum99(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum100(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum101(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum102(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum103(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum104(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum105(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum106(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum107(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum108(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum109(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum110(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum111(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum112(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum113(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum114(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum115(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum116(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum117(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum118(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum119(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum120(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum121(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum122(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum123(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum124(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum125(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum126(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum127(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum128(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum129(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum130(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum131(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum132(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum133(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum134(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum135(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum136(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum137(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum138(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum139(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum140(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum141(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum142(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum143(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum144(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum145(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum146(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum147(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum148(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum149(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum150(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum151(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum152(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum153(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum154(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum155(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum156(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum157(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum158(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum159(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum160(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum161(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum162(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum163(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum164(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum165(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum166(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum167(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum168(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum169(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum170(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum171(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum172(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum173(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum174(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum175(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum176(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum177(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum178(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum179(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum180(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum181(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum182(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum183(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum184(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum185(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum186(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum187(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum188(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum189(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum190(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum191(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum192(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum193(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum194(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum195(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum196(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum197(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum198(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum199(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum200(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum201(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum202(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum203(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum204(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum205(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum206(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum207(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum208(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum209(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum210(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum211(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum212(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum213(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum214(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum215(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum216(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum217(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum218(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum219(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum220(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum221(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum222(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum223(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum224(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum225(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum226(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum227(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum228(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum229(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum230(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum231(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum232(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum233(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum234(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum235(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum236(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum237(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum238(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum239(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum240(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum241(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum242(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum243(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum244(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum245(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum246(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum247(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum248(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum249(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum250(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum251(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum252(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum253(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum254(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum255(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)
#define _fenum256(EnumType, First, ...) EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)

#define EXTEND_ENUM_VALUE(EnumType, First, ...)                                                    \
  EnumType::First, _fenumn(__VA_ARGS__)(EnumType, __VA_ARGS__)

#define FRIENDLY_ENUM(EnumType, ...)                                                               \
  enum class EnumType { __VA_ARGS__ };                                                             \
  using EnumType##Traiter =                                                                        \
      fenum::EnumTraiter<EnumType, EXTEND_ENUM_VALUE(EnumType, __VA_ARGS__)>;                      \
  inline constexpr auto GetTraiterByTag(fenum::EnumTag<EnumType> = {}) {                           \
    using EnumType##Traiter =                                                                      \
        fenum::EnumTraiter<EnumType, EXTEND_ENUM_VALUE(EnumType, __VA_ARGS__)>;                    \
    constexpr const EnumType##Traiter inst(#__VA_ARGS__);                                          \
    return inst;                                                                                   \
  }                                                                                                \
  using EnumType##Tag = fenum::EnumTag<EnumType>

#define FRIENDLY_INNER_ENUM(EnumType, ...)                                                         \
  enum class EnumType { __VA_ARGS__ };                                                             \
  using EnumType##Traiter =                                                                        \
      fenum::EnumTraiter<EnumType, EXTEND_ENUM_VALUE(EnumType, __VA_ARGS__)>;                      \
  inline static constexpr auto GetTraiterByTag(fenum::EnumTag<EnumType> = {}) {                    \
    using EnumType##Traiter =                                                                      \
        fenum::EnumTraiter<EnumType, EXTEND_ENUM_VALUE(EnumType, __VA_ARGS__)>;                   \
    constexpr const EnumType##Traiter inst(#__VA_ARGS__);                                          \
    return inst;                                                                                   \
  }                                                                                                \
  using EnumType##Tag = fenum::EnumTag<EnumType>
