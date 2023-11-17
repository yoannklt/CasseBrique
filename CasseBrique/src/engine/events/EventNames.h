#pragma once

typedef enum EventNames {

	//KEYBOARD EVENTS
	//Keyboard Keys Pressed
	KEY_UNKNOWN_PRESSED = 0,  // Unknown key or non-alphanumeric keys

	//CUSTOM EVENTS
	BALL_CREATED,
	BALL_DESTROYED,
	BRICK_TOUCH,
	BRICK_DESTROY,

	// Alphanumeric keys
	KEY_A_PRESSED,
	KEY_B_PRESSED,
	KEY_C_PRESSED,
	KEY_D_PRESSED,
	KEY_E_PRESSED,
	KEY_F_PRESSED,
	KEY_G_PRESSED,
	KEY_H_PRESSED,
	KEY_I_PRESSED,
	KEY_J_PRESSED,
	KEY_K_PRESSED,
	KEY_L_PRESSED,
	KEY_M_PRESSED,
	KEY_N_PRESSED,
	KEY_O_PRESSED,
	KEY_P_PRESSED,
	KEY_Q_PRESSED,
	KEY_R_PRESSED,
	KEY_S_PRESSED,
	KEY_T_PRESSED,
	KEY_U_PRESSED,
	KEY_V_PRESSED,
	KEY_W_PRESSED,
	KEY_X_PRESSED,
	KEY_Y_PRESSED,
	KEY_Z_PRESSED,

	// Numeric keys
	KEY_0_PRESSED,
	KEY_1_PRESSED,
	KEY_2_PRESSED,
	KEY_3_PRESSED,
	KEY_4_PRESSED,
	KEY_5_PRESSED,
	KEY_6_PRESSED,
	KEY_7_PRESSED,
	KEY_8_PRESSED,
	KEY_9_PRESSED,

	// Numeric Pad keys pressed
	KEY_NUMPAD_0_PRESSED,
	KEY_NUMPAD_1_PRESSED,
	KEY_NUMPAD_2_PRESSED,
	KEY_NUMPAD_3_PRESSED,
	KEY_NUMPAD_4_PRESSED,
	KEY_NUMPAD_5_PRESSED,
	KEY_NUMPAD_6_PRESSED,
	KEY_NUMPAD_7_PRESSED,
	KEY_NUMPAD_8_PRESSED,
	KEY_NUMPAD_9_PRESSED,

	// Function keys
	KEY_F1_PRESSED,
	KEY_F2_PRESSED,
	KEY_F3_PRESSED,
	KEY_F4_PRESSED,
	KEY_F5_PRESSED,
	KEY_F6_PRESSED,
	KEY_F7_PRESSED,
	KEY_F8_PRESSED,
	KEY_F9_PRESSED,
	KEY_F10_PRESSED,
	KEY_F11_PRESSED,
	KEY_F12_PRESSED,
	KEY_F13_PRESSED,
	KEY_F14_PRESSED,
	KEY_F15_PRESSED,

	// Special keys
	KEY_TAB_PRESSED,
	KEY_ENTER_PRESSED,
	KEY_LSHIFT_PRESSED,
	KEY_RSHIFT_PRESSED,
	KEY_LCTRL_PRESSED,
	KEY_RCTRL_PRESSED,
	KEY_LALT_PRESSED,
	KEY_RALT_PRESSED,
	KEY_SPACE_PRESSED,
	KEY_ESCAPE_PRESSED,
	KEY_BACKSPACE_PRESSED,
	KEY_LSYSTEM_PRESSED,
	KEY_RSYSTEM_PRESSED,
	KEY_LBRACKET_PRESSED,
	KEY_RBRACKET_PRESSED,
	KEY_SEMICOLON_PRESSED,
	KEY_COMMA_PRESSED,
	KEY_PERIOD_PRESSED,
	KEY_APOSTROPHE_PRESSED,
	KEY_SLASH_PRESSED,
	KEY_BACKSLASH_PRESSED,
	KEY_GRAVE_PRESSED,
	KEY_EQUAL_PRESSED,
	KEY_ADD_PRESSED,
	KEY_SUBTRACT_PRESSED,
	KEY_DIVIDE_PRESSED,
	KEY_MULTIPLY_PRESSED,
	KEY_MENU_PRESSED,
	KEY_HYPHEN_PRESSED,
	KEY_CAPS_LOCK_PRESSED,
	KEY_INSERT_PRESSED,
	KEY_PAUSE_PRESSED,
	KEY_DELETE_PRESSED,
	KEY_HOME_PRESSED,
	KEY_END_PRESSED,
	KEY_PAGE_UP_PRESSED,
	KEY_PAGE_DOWN_PRESSED,
	KEY_ARROW_UP_PRESSED,
	KEY_ARROW_DOWN_PRESSED,
	KEY_ARROW_LEFT_PRESSED,
	KEY_ARROW_RIGHT_PRESSED,

	//Keyboard Keys Released
	KEY_UNKNOWN_RELEASED,  // Unknown key or non-alphanumeric keys released

	// Alphanumeric keys released
	KEY_A_RELEASED,
	KEY_B_RELEASED,
	KEY_C_RELEASED,
	KEY_D_RELEASED,
	KEY_E_RELEASED,
	KEY_F_RELEASED,
	KEY_G_RELEASED,
	KEY_H_RELEASED,
	KEY_I_RELEASED,
	KEY_J_RELEASED,
	KEY_K_RELEASED,
	KEY_L_RELEASED,
	KEY_M_RELEASED,
	KEY_N_RELEASED,
	KEY_O_RELEASED,
	KEY_P_RELEASED,
	KEY_Q_RELEASED,
	KEY_R_RELEASED,
	KEY_S_RELEASED,
	KEY_T_RELEASED,
	KEY_U_RELEASED,
	KEY_V_RELEASED,
	KEY_W_RELEASED,
	KEY_X_RELEASED,
	KEY_Y_RELEASED,
	KEY_Z_RELEASED,

	// Numeric keys released
	KEY_0_RELEASED,
	KEY_1_RELEASED,
	KEY_2_RELEASED,
	KEY_3_RELEASED,
	KEY_4_RELEASED,
	KEY_5_RELEASED,
	KEY_6_RELEASED,
	KEY_7_RELEASED,
	KEY_8_RELEASED,
	KEY_9_RELEASED,

	// Numeric Pad keys released
	KEY_NUMPAD_0_RELEASED,
	KEY_NUMPAD_1_RELEASED,
	KEY_NUMPAD_2_RELEASED,
	KEY_NUMPAD_3_RELEASED,
	KEY_NUMPAD_4_RELEASED,
	KEY_NUMPAD_5_RELEASED,
	KEY_NUMPAD_6_RELEASED,
	KEY_NUMPAD_7_RELEASED,
	KEY_NUMPAD_8_RELEASED,
	KEY_NUMPAD_9_RELEASED,

	// Function keys released
	KEY_F1_RELEASED,
	KEY_F2_RELEASED,
	KEY_F3_RELEASED,
	KEY_F4_RELEASED,
	KEY_F5_RELEASED,
	KEY_F6_RELEASED,
	KEY_F7_RELEASED,
	KEY_F8_RELEASED,
	KEY_F9_RELEASED,
	KEY_F10_RELEASED,
	KEY_F11_RELEASED,
	KEY_F12_RELEASED,
	KEY_F13_RELEASED,
	KEY_F14_RELEASED,
	KEY_F15_RELEASED,

	// Special keys released
	KEY_TAB_RELEASED,
	KEY_ENTER_RELEASED,
	KEY_LSHIFT_RELEASED,
	KEY_RSHIFT_RELEASED,
	KEY_LCTRL_RELEASED,
	KEY_RCTRL_RELEASED,
	KEY_LALT_RELEASED,
	KEY_RALT_RELEASED,
	KEY_SPACE_RELEASED,
	KEY_ESCAPE_RELEASED,
	KEY_BACKSPACE_RELEASED,
	KEY_LSYSTEM_RELEASED,
	KEY_RSYSTEM_RELEASED,
	KEY_LBRACKET_RELEASED,
	KEY_RBRACKET_RELEASED,
	KEY_SEMICOLON_RELEASED,
	KEY_COMMA_RELEASED,
	KEY_PERIOD_RELEASED,
	KEY_APOSTROPHE_RELEASED,
	KEY_SLASH_RELEASED,
	KEY_BACKSLASH_RELEASED,
	KEY_GRAVE_RELEASED,
	KEY_EQUAL_RELEASED,
	KEY_ADD_RELEASED,
	KEY_SUBTRACT_RELEASED,
	KEY_DIVIDE_RELEASED,
	KEY_MULTIPLY_RELEASED,
	KEY_MENU_RELEASED,
	KEY_HYPHEN_RELEASED,
	KEY_CAPS_LOCK_RELEASED,
	KEY_INSERT_RELEASED,
	KEY_PAUSE_RELEASED,
	KEY_DELETE_RELEASED,
	KEY_HOME_RELEASED,
	KEY_END_RELEASED,
	KEY_PAGE_UP_RELEASED,
	KEY_PAGE_DOWN_RELEASED,
	KEY_ARROW_UP_RELEASED,
	KEY_ARROW_DOWN_RELEASED,
	KEY_ARROW_LEFT_RELEASED,
	KEY_ARROW_RIGHT_RELEASED,

	//MOUSE EVENTS
	MOUSE_LEFT_PRESSED,
	MOUSE_RIGHT_PRESSED,
	MOUSE_MIDDLE_PRESSED,

	MOUSE_LEFT_RELEASED,
	MOUSE_RIGHT_RELEASED,
	MOUSE_MIDDLE_RELEASED,

	MOUSE_MOVE,
	MOUSE_SCROLL_UP,
	MOUSE_SCROLL_DOWN,

	//WINDOW EVENTS
	CLOSE_WINDOW,
	CLOSE_WINDOW_BUTTON,
	
	EVENT_NAMES_COUNT
} EventName;
