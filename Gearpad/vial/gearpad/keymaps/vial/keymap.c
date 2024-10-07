/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum custom_keycodes{
	IN = QK_KB_0,
	ARAE_A,
	JI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( // 넘패드 
		TO(0), TO(1), TO(2), TO(3),
		KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
		
		KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS,
		KC_KP_4, KC_KP_5, KC_KP_6,
		KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT,
		KC_KP_0, KC_PDOT
	),
	
	[1] = LAYOUT( // 천지인 
		TO(0), TO(1), TO(2), TO(3),
		
		IN,  ARAE_A, JI, KC_BSPC,
		TD(0), TD(1), TD(2), KC_RSFT,
		TD(3), TD(4), TD(5),
		TD(7), TD(6), TD(8), KC_ENTER,
		KC_SPACE, KC_RALT
	),
	
	[2] = LAYOUT(
		TO(0), TO(1), TO(2), TO(3),
		
		TD(9), TD(10), TD(11), KC_BSPC,
		TD(12), TD(13), TD(14), KC_RSFT,
		TD(15), TD(16), TD(17),
		TD(7), KC_CAPS, TD(8), KC_ENTER,
		KC_SPACE, KC_RALT
	),
	
	[3] = LAYOUT(
		TO(0), TO(1), TO(2), TO(3),
		
		TD(18), TD(19), TD(20), KC_BSPC,
		TD(21), TD(22), TD(23), KC_RSFT,
		TD(24), KC_TAB, KC_ESC,
		TD(7), KC_LGUI, KC_LCTL, KC_ENTER,
		KC_SPACE, KC_RALT
	)
};

// 상태를 추적하기 위한 전역 변수 선언
static bool l_pressed = false;  // l이 눌렸는지 여부를 추적
static bool k_replaced = false; // k로 교체했는지 여부를 추적
static bool i_replaced = false; // i로 교체했는지 여부를 추적
static bool m_pressed = false;  // m이 눌렸는지 여부를 추적
static bool n_replaced = false; // n로 교체했는지 여부를 추적
static bool consonant = false;  // 자음 선택 여부를 추적
static uint8_t dot_count = 0;   // 점 카운트
static bool j_replaced = false; // j로 교체했는지 여부를 추적
static bool u_replaced = false; // u로 교체했는지 여부를 추적
static bool b_replaced = false; // b로 교체했는지 여부를 추적
static bool nj_replaced = false; // nj로 교체했는지 여부를 추적

// 상태를 초기화하는 함수
void reset_state(void) {
    l_pressed = false;
    k_replaced = false;
    m_pressed = false;
    n_replaced = false;
    i_replaced = false;
    j_replaced = false;
    u_replaced = false;
    b_replaced = false;
    nj_replaced = false;
    consonant = false;
    dot_count = 0;  // arae_a 카운트 초기화
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case IN:
                if (k_replaced) {
                    // i를 지우고 o를 출력 (ㅐ)
                    tap_code(KC_BSPC);      // 백스페이스로 i를 지움
                    tap_code(KC_O);         // o를 출력
                    reset_state();          // 상태 초기화
                    return false;           // l은 출력되지 않도록 함
                } else if (i_replaced) {
                    // i를 지우고 O를 출력 (ㅒ)
                    tap_code(KC_BSPC);          // 백스페이스로 i를 지움
                    register_code(KC_LSFT);     // Shift를 누른 상태
                    tap_code(KC_O);             // o를 출력
                    unregister_code(KC_LSFT);   // Shift를 땐 상태
                    reset_state();              // 상태 초기화
                    return false;
                } else if (consonant && dot_count == 1) {
                    // j를 출력 (ㅓ)
                    tap_code(KC_J);             // j를 출력
                    reset_state();              // 상태 초기화
                    j_replaced = true;
                    return false;
                } else if (consonant && dot_count == 2) {
                    // u를 출력 (ㅕ)
                    tap_code(KC_U);             // u를 출력
                    reset_state();              // 상태 초기화
                    u_replaced = true;
                    return false;
                } else if (j_replaced) {
                    // p를 출력 (ㅔ)
                    tap_code(KC_BSPC);
                    tap_code(KC_P);             // p를 출력
                    reset_state();              // 상태 초기화
                    return false;
                } else if (u_replaced) {
                    // P를 출력 (ㅖ)
                    tap_code(KC_BSPC);
                    register_code(KC_LSFT);     // Shift를 누른 상태
                    tap_code(KC_P);             // p를 출력
                    unregister_code(KC_LSFT);   // Shift를 땐 상태
                    reset_state();              // 상태 초기화
                    return false;
                } else if(!b_replaced && !nj_replaced && dot_count == 0) {
                    // l을 출력 (ㅣ)
                    tap_code(KC_L);             // l을 출력
                    l_pressed = true;           // l 상태 true
                    return false;                // l을 출력하도록 함
                }else if (b_replaced) {
                    // b를 지우고 nj를 출력 (ㅝ)
                    tap_code(KC_BSPC);          // 백스페이스로 b를 지움
                    tap_code(KC_N);             // n를 출력
                    tap_code(KC_J);             // j를 출력
                    reset_state();              // 상태 초기화
                    nj_replaced = true;         // l 상태 true
                    return false;
                }else if (nj_replaced) {
                    // i를 지우고 O를 출력 (ㅞ)
                    tap_code(KC_BSPC);          // 백스페이스로 j를 지움
                    tap_code(KC_P);             // p를 출력
                    reset_state();              // 상태 초기화
                    return false;
                }
                break;

            case ARAE_A:
                if (l_pressed && !k_replaced) {
                    // l을 지우고 k를 출력 (ㅏ)
                    tap_code(KC_BSPC);          // 백스페이스로 l을 지움
                    tap_code(KC_K);             // k를 출력
                    k_replaced = true;          // k 상태 true
                    dot_count = 0;              // 점 초기화
                    return false;
                } else if (l_pressed && k_replaced) {
                    // k를 지우고 i를 출력 (ㅑ)
                    tap_code(KC_BSPC);          // 백스페이스로 k를 지움
                    tap_code(KC_I);             // i를 출력
                    reset_state();              // 상태 초기화
                    i_replaced = true;          // i 상태 true
                    return false;
                } else if (m_pressed && !n_replaced) {
                    // m을 지우고 n을 출력 (ㅜ)
                    tap_code(KC_BSPC);          // 백스페이스로 m을 지움
                    tap_code(KC_N);             // n을 출력
                    n_replaced = true;          // n 상태 true
                    dot_count = 0;              // 점 초기화
                    return false;
                } else if (m_pressed && n_replaced) {
                    // n을 지우고 b를 출력 (ㅠ)
                    tap_code(KC_BSPC);          // 백스페이스로 n을 지움
                    tap_code(KC_B);             // b를 출력
                    reset_state();              // 상태 초기화
                    b_replaced = true;          // b 상태 true
                    return false;
                } else if (consonant) {
            		dot_count++;
				    return false;
				    
                } else if (dot_count == 3) {
                    // 점 카운트 초기화
                    dot_count = 0;
                    consonant =  false;
                    return false;
                }
                break;

            case JI:
                // m을 출력 (ㅡ)
                if (dot_count == 0) {
                	tap_code(KC_M);             // m을 출력
                    m_pressed = true;           // m 상태 true
                    return false;                // m을 출력하도록 함
                } else if (consonant && dot_count == 1) {
                    // h를 출력 (ㅗ)
                    tap_code(KC_H);             // h를 출력
                    reset_state();              // 상태 초기화
                    return false;
                } else if (consonant && dot_count == 2) {
                    // y를 출력 (ㅛ)
                    tap_code(KC_Y);             // y를 출력
                    reset_state();              // 상태 초기화
                    return false;
                }
                break;
				// 자음 키코드
            case KC_Q: case KC_W: case KC_E: case KC_R: case KC_T: 
            case KC_A: case KC_S: case KC_D: case KC_F: case KC_G: 
            case KC_Z: case KC_X: case KC_C: case KC_V:
            	//한글 자음용 탭댄스 
            case TD(0):	case TD(1):	case TD(2):	case TD(3):	case TD(4):
                // 자음이 눌리면 상태를 초기화
                reset_state();
                consonant = true;               // 자음 상태 true
                break;
			
			case KC_BSPC:
				reset_state();
				break;
				
            default:
                // 다른 키가 눌리면 모두 초기화
                reset_state();
                break;
        }
    }
    return true; // 기본 키 처리를 계속 진행
}
