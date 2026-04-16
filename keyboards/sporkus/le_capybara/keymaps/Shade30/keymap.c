// Copyright 2023 sporkus
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum/keycodes.h"
#include "../../rgb.c"

#define layers shade30_layers
enum layers {
    _BASE = 0,
    _LWR,
    _RSE,
    _ADJ,
    _WIN,
};
#undef layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_3thumb(
        KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_MUTE,         KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,
        LT(_WIN, KC_A),   LGUI_T(KC_S),     LALT_T(KC_D),     LCTL_T(KC_F),     KC_G,                              KC_H,             RCTL_T(KC_J),     RALT_T(KC_K),     RGUI_T(KC_L),     LT(_WIN, KC_SCLN),
        KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,                              KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,
                                             LT(_RSE, KC_TAB), LSFT_T(KC_SPC),  LT(_LWR, KC_ENT),                  LT(_LWR, KC_ESC), RSFT_T(KC_BSPC),  LT(_RSE, KC_DEL)
    ),

    [_LWR] = LAYOUT_3thumb(
        KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            _______,         KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,
        KC_EXLM,          KC_AT,            KC_HASH,          KC_DLR,           KC_PERC,                           KC_CIRC,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RPRN,
        KC_1,             KC_2,             KC_3,             KC_4,             KC_5,                              KC_6,             KC_7,             KC_8,             KC_9,             KC_0,
                                            LT(_ADJ, KC_TAB), _______,          _______,                           _______,          _______,          LT(_ADJ, KC_DEL)
    ),

    [_RSE] = LAYOUT_3thumb(
        KC_PAST,          KC_P7,            KC_P8,            KC_P9,            KC_PPLS,          _______,         KC_CAPS,          KC_HOME,          KC_PSCR,          KC_PGUP,          S(KC_BSLS),
        LT(_WIN, KC_PSLS),LGUI_T(KC_P4),    LALT_T(KC_P5),    LCTL_T(KC_P6),    KC_PMNS,                           KC_LEFT,          RCTL_T(KC_DOWN),  RALT_T(KC_UP),    RGUI_T(KC_RGHT),  LT(_WIN, KC_INS),
        KC_P0,            KC_P1,            KC_P2,            KC_P3,            KC_PCMM,                           KC_SCRL,          KC_END,           KC_PAUS,          KC_PGDN,          KC_BSLS,
                                            _______,          _______,          LT(_ADJ, KC_ENT),                  LT(_ADJ, KC_ESC), _______,          _______
    ),

    [_ADJ] = LAYOUT_3thumb(
        QK_BOOT,          _______,          _______,          _______,          EE_CLR,           _______,         _______,          _______,          KC_BSPC,          _______,          _______,
        _______,          KC_LGUI,          KC_LALT,          KC_LCTL,          _______,                           _______,          MS_LEFT,          MS_UP,            MS_RGHT,          MS_WHLU,
        _______,          _______,          _______,          _______,          _______,                           _______,          MS_WHLL,          MS_DOWN,          MS_WHLR,          MS_WHLD,
                                            _______,          _______,          _______,                           MS_BTN1,          MS_BTN3,          MS_BTN2
    ),

    [_WIN] = LAYOUT_3thumb(
        KC_GRAVE,         _______,          _______,          _______,          _______,          _______,         KC_F11,           KC_F12,           G(KC_L),          KC_LBRC,          KC_RBRC,
        S(G(KC_1)),       S(G(KC_2)),       S(G(KC_3)),       S(G(KC_4)),       _______,                           C(KC_GRV),        KC_MINUS,         KC_EQL,           S(KC_MINUS),      KC_QUOT,
        G(KC_1),          G(KC_2),          G(KC_3),          G(KC_4),          G(KC_5),                           G(KC_6),          G(KC_7),          G(KC_8),          G(KC_9),          G(KC_0),
                                            _______,          _______,          _______,                           _______,          _______,          _______
    )
};

#ifdef ENCODER_MAP_ENABLE
#undef BLANK_LAYER
#define BLANK_LAYER { ENCODER_CCW_CW(_______, _______) }
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LWR]  =   BLANK_LAYER,
    [_RSE]  =   BLANK_LAYER,
    [_ADJ]  =   BLANK_LAYER,
    [_WIN]  =   BLANK_LAYER
};
#endif
