// Copyright 2024 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Corne-specific customizations, included only from config/corne.keymap,
// AFTER miryoku.dtsi (needs U_BASE / U_TAP and the &mo behavior).

// Tap layer (U_TAP) momentary: chord S+T (Colemak-DH home row, left hand).
// Key positions in the 42-key Corne matrix: row 1 is 12..23 with 12 unused,
// so A=13 R=14 S=15 T=16.
//
// S keeps hold = Ctrl and T keeps hold = Shift on the Base layer. Combos are
// resolved before hold-taps, so the chord only fires when S and T go down
// within a short window; anything slower falls through to the normal
// hold-taps (Ctrl+Shift still works by pressing them one after the other).
// require-prior-idle-ms avoids triggering the chord while typing "st" in
// the middle of a word.
//
// The Tap layer stays active only while the chord is held; releasing S or T
// turns it off (&mo).
// The combo also sends S and T to the host while the chord is held (macro
// below: press &mo U_TAP, S, T; wait for release; release them in reverse).
/ {
  macros {
    tap_layer_st: tap_layer_st {
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      wait-ms = <0>;
      tap-ms = <0>;
      bindings =
        <&macro_press &mo U_TAP &kp S &kp T>,
        <&macro_pause_for_release>,
        <&macro_release &kp T &kp S &mo U_TAP>;
    };
  };

  combos {
    compatible = "zmk,combos";
    combo_tap_layer {
      layers = <U_BASE>;
      key-positions = <15 16>;
      bindings = <&tap_layer_st>;
      timeout-ms = <50>;
      require-prior-idle-ms = <150>;
    };
  };
};
