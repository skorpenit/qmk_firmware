#include QMK_KEYBOARD_H

//#include "keymap_norwegian_osx_iso.h"
//#include "keymap_norwegian.h"

#define KC_ACUT KC_NO
#define KC_AE RALT(KC_QUOT)
#define KC_OSTR RALT(KC_O)
#define KC_ARNG RALT(KC_A)

enum ferris_layers {
  _COLEMAKDH,
  _CMD,
  _CTRL,
  _SPECIAL,
  _NUMBERS,
  _NAV,
  _NORWEGIAN,
};

enum ferris_tap_dance {
  TD_AE = 0,
  TD_AA,
  TD_OE,

  TD_ESC
  
};

enum ferris_combos {
  THUMB_14_SHIFT = 0,
  THUMB_23_NORWEGIAN
};

const uint16_t PROGMEM thumb14_combo[] = { LT(_NUMBERS,KC_SPC), LT(_SPECIAL,KC_ENT), COMBO_END };
const uint16_t PROGMEM thumb23_combo[] = { LT(_CTRL, KC_TAB), KC_BSPC, COMBO_END };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDH] = LAYOUT_split_3x5_2(
				    KC_Q, KC_W, KC_F, KC_P, KC_B,
				    KC_J, KC_L, KC_U, KC_Y, KC_DEL,

				    LT(_NAV, KC_A), MT(MOD_LALT, KC_R), KC_S, KC_T, KC_G,
				    KC_M, KC_N, KC_E, MT(MOD_RALT, KC_I), LT(_NORWEGIAN, KC_O),

				    KC_Z, KC_X, KC_C, KC_D, KC_V,
				    KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,

				    LT(_NUMBERS,KC_SPC), LT(_CTRL, KC_TAB),
				    MT(MOD_LGUI, KC_BSPC), LT(_SPECIAL,KC_ENT)),
  [_CMD] = LAYOUT_split_3x5_2(
			      LGUI(KC_Q), LGUI(KC_W), LGUI(KC_F), LGUI(KC_P), LGUI(KC_B),
			      LGUI(KC_J), LGUI(KC_L), LGUI(KC_U), LGUI(KC_Y), LGUI(KC_DEL),

			      LGUI(KC_A), LGUI(KC_R), LGUI(KC_S), LGUI(KC_T), LGUI(KC_G),
			      LGUI(KC_M), LGUI(KC_N), LGUI(KC_E), LGUI(KC_I), LGUI(KC_O),

			      LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_D), LGUI(KC_V),
			      LGUI(KC_K), LGUI(KC_H), LGUI(KC_COMM), LGUI(KC_DOT), LGUI(KC_SLSH),

			      LGUI(KC_SPC), KC_TAB,
			      LGUI(KC_BSPC), LGUI(KC_ENT)
			      ),
  [_CTRL] = LAYOUT_split_3x5_2(
			       LCTL(KC_Q), LCTL(KC_W), LCTL(KC_F), LCTL(KC_P), LCTL(KC_B),
			       LCTL(KC_J), LCTL(KC_L), LCTL(KC_U), LCTL(KC_Y), LCTL(KC_DEL),

			       LCTL(KC_A), LCTL(KC_R), LCTL(KC_S), LCTL(KC_T), LCTL(KC_G),
			       LCTL(KC_M), LCTL(KC_N), LCTL(KC_E), LCTL(KC_I), LCTL(KC_O),

			       LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_D), LCTL(KC_V),
			       LCTL(KC_K), LCTL(KC_H), LCTL(KC_COMM), LCTL(KC_DOT), LCTL(KC_SLSH),

			       LCTL(KC_SPC), LCTL(KC_TAB),
			       LT(_CMD, KC_BSPC), LCTL(KC_ENT)
			       ),
  [_SPECIAL] = LAYOUT_split_3x5_2(
				  KC_ESC, KC_AT, KC_HASH, KC_DLR, KC_PERC,
				  KC_CIRC, KC_AMPR, KC_ASTR, KC_ACUT, KC_NO,

				  KC_GRV, KC_UNDS, KC_QUOT, KC_QUES, KC_DQUO,
				  KC_BSLS, KC_LCBR, KC_RCBR, KC_PIPE, KC_PLUS,

				  KC_TILD, KC_LABK, KC_RABK, KC_EXLM, KC_EQL,
				  KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_MINS,

				  KC_TRNS, KC_TRNS,
				  KC_TRNS, KC_TRNS),
	
  [_NUMBERS] = LAYOUT_split_3x5_2(
				  KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,
				  KC_EQL, KC_7, KC_8, KC_9, KC_NO,
					
				  KC_NO, MT(MOD_LALT, KC_F4), MT(MOD_LGUI, KC_F5), MT(MOD_LSFT, KC_F6), KC_F11,
				  KC_DOT, KC_4, KC_5, KC_6, KC_0,

				  KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,
				  KC_NO, KC_1, KC_2, KC_3, KC_SLSH,

				  KC_SPC, LCTL(KC_TAB),
				  KC_BSPC, KC_ENT),
	
  [_NAV] = LAYOUT_split_3x5_2(
			      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
			      KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO,

			      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
			      KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,

			      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
			      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

			      KC_NO, KC_NO,
			      KC_NO, KC_NO),
	
  [_NORWEGIAN] = LAYOUT_split_3x5_2(
				    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
				    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

				    KC_NO, KC_AE, KC_OSTR, KC_ARNG, KC_NO,
				    KC_NO, KC_RSFT, KC_NO, KC_NO, KC_NO,

				    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
				    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

				    KC_NO, KC_NO,
				    KC_NO, KC_NO)
};

/*
tap_dance_action_t tap_dance_actions[] = {
  [TD_AE] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_B),
  [TD_AA] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_D),
  [TD_OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_C),

  [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
*/

combo_t key_combos[] = {
  [THUMB_14_SHIFT] = COMBO(thumb14_combo, KC_CAPS),
  [THUMB_23_NORWEGIAN] = COMBO(thumb23_combo, OSL(_CMD))
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
