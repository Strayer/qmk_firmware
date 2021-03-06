#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 2
#define _RAISE 3
#define _HYPER 1
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

/* #define HYESC MT(MOD_HYPR, KC_ESC) */
#define HYESC LT(_HYPER, KC_ESC)
#define ENTSFT MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty */
  [_QWERTY] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    HYESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,                         KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,                         KC_DEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENTSFT, \
    _______, _______, KC_LCTL,     KC_LALT,      KC_LGUI, KC_SPC, LOWER,           RAISE, KC_BSPC, KC_RGUI,          KC_RALT, KC_RCTL, _______, _______ \
  ),

  /* Lower */
  [_LOWER] = LAYOUT(
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, \
    KC_TAB,   LSFT(KC_1),    LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),    LSFT(KC_5),    KC_TAB,                         KC_BSPC, LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0), LSFT(KC_BSLS) , \
    KC_LSFT, KC_EQL,    KC_MINS,    LSFT(KC_EQL),    LSFT(KC_LCBR),    LSFT(KC_RCBR),    KC_DEL,                         KC_RALT, KC_LCBR,    KC_RCBR,    KC_SCLN,   LSFT(KC_SCLN),   KC_BSLS, KC_RSFT, \
    _______, _______, KC_LCTL,     KC_LALT,      KC_LGUI, KC_SPC, LOWER,           RAISE, KC_BSPC, KC_RGUI,          KC_RALT, KC_RCTL, _______, _______ \
  ),

  /* Raise */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,                        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    HYESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TAB,                         KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_DQT , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,                         KC_RALT, KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, ENTSFT, \
    KC_LCTL, KC_LALT, KC_LALT,     _______,      KC_LGUI, KC_SPC, LOWER,           RAISE, KC_BSPC, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  [_HYPER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    HYPR(KC_SPC), _______, HYPR(KC_W), _______, _______, LGUI(KC_T),_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, HYPR(KC_F), _______,_______,                       _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,_______, _______, \
    _______, _______, _______, LGUI(KC_C), LGUI(KC_V), _______,LALT(KC_SPC),                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,LALT(KC_SPC),_______,       _______,_______, _______,          _______, _______, _______, _______  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, VLK_TOG, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
