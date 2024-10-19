/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "vial.h"
#include "dynamic_keymap.h"

enum custom_keycodes{
	IN = QK_KB_0,
	ARAE_A,
	JI
};

#ifdef VIAL_ENABLE
void keyboard_post_init_user(void) {
    struct {
        uint8_t index;
        vial_tap_dance_entry_t entry;
    } td_entries[] = {
        {0, {KC_R, RSFT(KC_R), KC_Z, KC_NO, 200}},	//��1:�� , ��2:�� , Ȧ��:��
        {1, {KC_S, KC_NO, KC_F, KC_NO, 200}},	//��1:�� , ��2:��
        {2, {KC_E, RSFT(KC_E), KC_X, KC_NO, 200}},	//��1:�� , ��2:�� , Ȧ��:��
        {3, {KC_Q, RSFT(KC_Q), KC_V, KC_NO, 200}},	//��1:�� , ��2:�� , Ȧ��:��
        {4, {KC_T, RSFT(KC_T), KC_G, KC_NO, 200}},	//��1:�� , ��2:�� , Ȧ��:��
        {5, {KC_W, RSFT(KC_W), KC_C, KC_NO, 200}},	//��1:�� , ��2:�� , Ȧ��:��
        {6, {KC_D, KC_NO, KC_A, KC_NO, 200}},	//��1:�� , ��2:��
        
        {7, {KC_DOT, KC_NO, KC_COMM, KC_NO, 200}},	//��1:. , ��2:,
        {8, {RSFT(KC_SLSH), KC_NO, RSFT(KC_1), KC_NO, 200}},	//��1:? , ��2:'!'
        
        {9, {KC_Q, KC_NO, KC_Z, KC_NO, 200}},	//��1:Q , ��2:Z
        {10, {KC_A, KC_C, KC_B, KC_NO, 200}},	//��1:A , ��2:B , Ȧ��:C
        {11, {KC_D, KC_F, KC_E, KC_NO, 200}},	//��1:D , ��2:E , Ȧ��:F
        {12, {KC_G, KC_I, KC_H, KC_NO, 200}},	//��1:G , ��2:H , Ȧ��:I
        {13, {KC_J, KC_L, KC_K, KC_NO, 200}},	//��1:J , ��2:K , Ȧ��:L
        {14, {KC_M, KC_O, KC_N, KC_NO, 200}},	//��1:M , ��2:N , Ȧ��:O
        {15, {KC_P, KC_S, KC_R, KC_NO, 200}},	//��1:P , ��2:R , Ȧ��:S
        {16, {KC_T, KC_V, KC_U, KC_NO, 200}},	//��1:T , ��2:U , Ȧ��:V
        {17, {KC_W, KC_Y, KC_X, KC_NO, 200}},	//��1:W , ��2:X , Ȧ��:Y
        
        {18, {RSFT(KC_2), KC_NO, RSFT(KC_3), KC_NO, 200}},	//��1:@ , ��2:#
        {19, {RSFT(KC_4), KC_NO, RSFT(KC_5), KC_NO, 200}},	//��1:$ , ��2:%
        {20, {RSFT(KC_6), KC_NO, RSFT(KC_7), KC_NO, 200}},	//��1:^ , ��2:&
        {21, {KC_MINS, KC_NO, KC_EQL, KC_NO, 200}},	//��1:- , ��2:=
        {22, {RSFT(KC_9), KC_NO, RSFT(KC_0), KC_NO, 200}},	//��1:( , ��2:)
        {23, {KC_LBRC, KC_NO, KC_RBRC, KC_NO, 200}},	//��1:[ , ��2:]
        {24, {KC_SCLN, KC_NO, KC_QUOT, KC_NO, 200}},	//��1:; , ��2:'
        
        {25, {KC_NO, KC_NO, KC_NO, KC_NO, 200}},
        {26, {KC_NO, KC_NO, KC_NO, KC_NO, 200}},
        {27, {KC_NO, KC_NO, KC_NO, KC_NO, 200}},
        {28, {KC_NO, KC_NO, KC_NO, KC_NO, 200}},
        {29, {KC_NO, KC_NO, KC_NO, KC_NO, 200}},
        {30, {KC_NO, KC_NO, KC_NO, KC_NO, 200}},
        {31, {KC_NO, KC_NO, KC_NO, KC_NO, 200}}
    };

    for (int i = 0; i < sizeof(td_entries) / sizeof(td_entries[0]); i++) {
        dynamic_keymap_set_tap_dance(td_entries[i].index, &td_entries[i].entry);
    }
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( // ���е� 
		TO(0), TO(1), TO(2), TO(3),
		KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
		
		KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS,
		KC_KP_4, KC_KP_5, KC_KP_6,
		KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT,
		KC_KP_0, KC_PDOT
	),
	
	[1] = LAYOUT( // õ���� 
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

// ���¸� �����ϱ� ���� ���� ���� ����
static bool l_pressed = false;  // l�� ���ȴ��� ���θ� ����
static bool k_replaced = false; // k�� ��ü�ߴ��� ���θ� ����
static bool i_replaced = false; // i�� ��ü�ߴ��� ���θ� ����
static bool m_pressed = false;  // m�� ���ȴ��� ���θ� ����
static bool n_replaced = false; // n�� ��ü�ߴ��� ���θ� ����
static bool consonant = false;  // ���� ���� ���θ� ����
static uint8_t dot_count = 0;   // �� ī��Ʈ
static bool j_replaced = false; // j�� ��ü�ߴ��� ���θ� ����
static bool u_replaced = false; // u�� ��ü�ߴ��� ���θ� ����
static bool b_replaced = false; // b�� ��ü�ߴ��� ���θ� ����
static bool nj_replaced = false; // nj�� ��ü�ߴ��� ���θ� ����

// ���¸� �ʱ�ȭ�ϴ� �Լ�
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
    dot_count = 0;  // arae_a ī��Ʈ �ʱ�ȭ
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case IN:
                if (k_replaced) {
                    // i�� ����� o�� ��� (��)
                    tap_code(KC_BSPC);      // �齺���̽��� i�� ����
                    tap_code(KC_O);         // o�� ���
                    reset_state();          // ���� �ʱ�ȭ
                    return false;           // l�� ��µ��� �ʵ��� ��
                } else if (i_replaced) {
                    // i�� ����� O�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� i�� ����
                    register_code(KC_LSFT);     // Shift�� ���� ����
                    tap_code(KC_O);             // o�� ���
                    unregister_code(KC_LSFT);   // Shift�� �� ����
                    reset_state();              // ���� �ʱ�ȭ
                    return false;
                } else if (consonant && dot_count == 1) {
                    // j�� ��� (��)
                    tap_code(KC_J);             // j�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    j_replaced = true;
                    return false;
                } else if (consonant && dot_count == 2) {
                    // u�� ��� (��)
                    tap_code(KC_U);             // u�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    u_replaced = true;
                    return false;
                } else if (j_replaced) {
                    // p�� ��� (��)
                    tap_code(KC_BSPC);
                    tap_code(KC_P);             // p�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    return false;
                } else if (u_replaced) {
                    // P�� ��� (��)
                    tap_code(KC_BSPC);
                    register_code(KC_LSFT);     // Shift�� ���� ����
                    tap_code(KC_P);             // p�� ���
                    unregister_code(KC_LSFT);   // Shift�� �� ����
                    reset_state();              // ���� �ʱ�ȭ
                    return false;
                } else if(!b_replaced && !nj_replaced && dot_count == 0) {
                    // l�� ��� (��)
                    tap_code(KC_L);             // l�� ���
                    l_pressed = true;           // l ���� true
                    return false;                // l�� ����ϵ��� ��
                }else if (b_replaced) {
                    // b�� ����� nj�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� b�� ����
                    tap_code(KC_N);             // n�� ���
                    tap_code(KC_J);             // j�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    nj_replaced = true;         // l ���� true
                    return false;
                }else if (nj_replaced) {
                    // i�� ����� O�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� j�� ����
                    tap_code(KC_P);             // p�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    return false;
                }
                break;

            case ARAE_A:
                if (l_pressed && !k_replaced) {
                    // l�� ����� k�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� l�� ����
                    tap_code(KC_K);             // k�� ���
                    k_replaced = true;          // k ���� true
                    dot_count = 0;              // �� �ʱ�ȭ
                    return false;
                } else if (l_pressed && k_replaced) {
                    // k�� ����� i�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� k�� ����
                    tap_code(KC_I);             // i�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    i_replaced = true;          // i ���� true
                    return false;
                } else if (m_pressed && !n_replaced) {
                    // m�� ����� n�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� m�� ����
                    tap_code(KC_N);             // n�� ���
                    n_replaced = true;          // n ���� true
                    dot_count = 0;              // �� �ʱ�ȭ
                    return false;
                } else if (m_pressed && n_replaced) {
                    // n�� ����� b�� ��� (��)
                    tap_code(KC_BSPC);          // �齺���̽��� n�� ����
                    tap_code(KC_B);             // b�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    b_replaced = true;          // b ���� true
                    return false;
                } else if (consonant) {
            		dot_count++;
				    return false;
				    
                } else if (dot_count == 3) {
                    // �� ī��Ʈ �ʱ�ȭ
                    dot_count = 0;
                    consonant =  false;
                    return false;
                }
                break;

            case JI:
                // m�� ��� (��)
                if (dot_count == 0) {
                	tap_code(KC_M);             // m�� ���
                    m_pressed = true;           // m ���� true
                    return false;                // m�� ����ϵ��� ��
                } else if (consonant && dot_count == 1) {
                    // h�� ��� (��)
                    tap_code(KC_H);             // h�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    return false;
                } else if (consonant && dot_count == 2) {
                    // y�� ��� (��)
                    tap_code(KC_Y);             // y�� ���
                    reset_state();              // ���� �ʱ�ȭ
                    return false;
                }
                break;
				// ���� Ű�ڵ�
            case KC_Q: case KC_W: case KC_E: case KC_R: case KC_T: 
            case KC_A: case KC_S: case KC_D: case KC_F: case KC_G: 
            case KC_Z: case KC_X: case KC_C: case KC_V:
            	//�ѱ� ������ �Ǵ� 
            case TD(0):	case TD(1):	case TD(2):	case TD(3):	case TD(4):
                // ������ ������ ���¸� �ʱ�ȭ
                reset_state();
                consonant = true;               // ���� ���� true
                break;
			
			case KC_BSPC:
				reset_state();
				break;
				
            default:
                // �ٸ� Ű�� ������ ��� �ʱ�ȭ
                reset_state();
                break;
        }
    }
    return true; // �⺻ Ű ó���� ��� ����
}
