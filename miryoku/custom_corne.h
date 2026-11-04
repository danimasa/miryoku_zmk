// Copyright 2024 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Corne-specific customizations, included only from config/corne.keymap.

// Fievel / OS mouse navigation: dedicated toggle for the pure alpha Tap
// layer (U_TAP) on the top-leftmost physical key (matrix position 0: the
// top key of the outer pinky column of the left half). Stock Miryoku leaves
// that key unused (&none) on every layer.

// Physical Corne mapping, identical to MIRYOKU_LAYOUTMAPPING_CORNE
// (miryoku/mapping/42/corne.h) except that the top-leftmost key is bound to
// &tog U_TAP instead of XXX.
#if !defined (MIRYOKU_LAYOUTMAPPING_CORNE_TAPTOGGLE)

#define MIRYOKU_LAYOUTMAPPING_CORNE_TAPTOGGLE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&tog U_TAP  K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  XXX \
XXX  K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  XXX \
XXX  K20  K21  K22  K23  K24       K25  K26  K27  K28  K29  XXX \
               K32  K33  K34       K35  K36  K37

#endif

// Base layer: the top-left key enters the Tap layer.
#if !defined (MIRYOKU_LAYERMAPPING_BASE)
#define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_LAYOUTMAPPING_CORNE_TAPTOGGLE
#endif

// Tap layer: the same top-left key toggles back out. While the Tap layer
// is active it sits above Base in the layer stack, so this binding is what
// fires for that key. Without it, the Tap layer would have no exit at all:
// stock Tap layer content is all plain &kp, including the thumb keys
// (&kp ESC / SPACE / TAB / RET / BSPC / DEL), with no layer switches.
#if !defined (MIRYOKU_LAYERMAPPING_TAP)
#define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_LAYOUTMAPPING_CORNE_TAPTOGGLE
#endif