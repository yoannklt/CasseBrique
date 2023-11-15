#include "EventsManager.h"
#include "../../core/GameManager.h"
#include "../rendering/Window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

EventsManager::EventsManager()
{
}

EventsManager::~EventsManager()
{
}

void EventsManager::handleSFMLEvents()
{
    while (GameManager::getWindow()->getWindow()->pollEvent(this->event))
    {
		this->trigger((this->*(EventsManager::SFMLMapper[this->event.type]))());
    }
}

void EventsManager::trigger(EventName eventName)
{
	for (EventCallbackData callbackData : eventCallbacksMap[eventName])
	{
		callbackData.callback();
	}
}

std::unordered_map <sf::Event::EventType, EventName(EventsManager::*)()> EventsManager::SFMLMapper {
	{sf::Event::EventType::KeyPressed, & EventsManager::getSFMLKeyPressedEventName},
	{ sf::Event::EventType::KeyReleased, &EventsManager::getSFMLKeyReleasedEventName },
	{ sf::Event::EventType::MouseButtonPressed, &EventsManager::getSFMLMouseButtonPressedEventName },
	{ sf::Event::EventType::MouseButtonReleased, &EventsManager::getSFMLMouseButtonReleasedEventName },
	{ sf::Event::EventType::Closed, &EventsManager::getSFMLClosedEventName }
};

std::unordered_map<sf::Keyboard::Key, EventName> EventsManager::SFMLKeyPressedTranslationMap = {
    {sf::Keyboard::Key::A, EventName::KEY_A_PRESSED},
    {sf::Keyboard::Key::B, EventName::KEY_B_PRESSED},
    {sf::Keyboard::Key::C, EventName::KEY_C_PRESSED},
    {sf::Keyboard::Key::D, EventName::KEY_D_PRESSED},
    {sf::Keyboard::Key::E, EventName::KEY_E_PRESSED},
    {sf::Keyboard::Key::F, EventName::KEY_F_PRESSED},
    {sf::Keyboard::Key::G, EventName::KEY_G_PRESSED},
    {sf::Keyboard::Key::H, EventName::KEY_H_PRESSED},
    {sf::Keyboard::Key::I, EventName::KEY_I_PRESSED},
    {sf::Keyboard::Key::J, EventName::KEY_J_PRESSED},
    {sf::Keyboard::Key::K, EventName::KEY_K_PRESSED},
    {sf::Keyboard::Key::L, EventName::KEY_L_PRESSED},
    {sf::Keyboard::Key::M, EventName::KEY_M_PRESSED},
    {sf::Keyboard::Key::N, EventName::KEY_N_PRESSED},
    {sf::Keyboard::Key::O, EventName::KEY_O_PRESSED},
    {sf::Keyboard::Key::P, EventName::KEY_P_PRESSED},
    {sf::Keyboard::Key::Q, EventName::KEY_Q_PRESSED},
    {sf::Keyboard::Key::R, EventName::KEY_R_PRESSED},
    {sf::Keyboard::Key::S, EventName::KEY_S_PRESSED},
    {sf::Keyboard::Key::T, EventName::KEY_T_PRESSED},
    {sf::Keyboard::Key::U, EventName::KEY_U_PRESSED},
    {sf::Keyboard::Key::V, EventName::KEY_V_PRESSED},
    {sf::Keyboard::Key::W, EventName::KEY_W_PRESSED},
    {sf::Keyboard::Key::X, EventName::KEY_X_PRESSED},
    {sf::Keyboard::Key::Y, EventName::KEY_Y_PRESSED},
    {sf::Keyboard::Key::Z, EventName::KEY_Z_PRESSED},

    {sf::Keyboard::Key::Num0, EventName::KEY_0_PRESSED},
    {sf::Keyboard::Key::Num1, EventName::KEY_1_PRESSED},
    {sf::Keyboard::Key::Num2, EventName::KEY_2_PRESSED},
    {sf::Keyboard::Key::Num3, EventName::KEY_3_PRESSED},
    {sf::Keyboard::Key::Num4, EventName::KEY_4_PRESSED},
    {sf::Keyboard::Key::Num5, EventName::KEY_5_PRESSED},
    {sf::Keyboard::Key::Num6, EventName::KEY_6_PRESSED},
    {sf::Keyboard::Key::Num7, EventName::KEY_7_PRESSED},
    {sf::Keyboard::Key::Num8, EventName::KEY_8_PRESSED},
    {sf::Keyboard::Key::Num9, EventName::KEY_9_PRESSED},
    {sf::Keyboard::Key::Escape, EventName::KEY_ESCAPE_PRESSED},
    {sf::Keyboard::Key::LControl, EventName::KEY_LCTRL_PRESSED},
    {sf::Keyboard::Key::LShift, EventName::KEY_LSHIFT_PRESSED},
    {sf::Keyboard::Key::LAlt, EventName::KEY_LALT_PRESSED},
    {sf::Keyboard::Key::LSystem, EventName::KEY_LSYSTEM_PRESSED},
    {sf::Keyboard::Key::RControl, EventName::KEY_RCTRL_PRESSED},
    {sf::Keyboard::Key::RShift, EventName::KEY_RSHIFT_PRESSED},
    {sf::Keyboard::Key::RAlt, EventName::KEY_RALT_PRESSED},
    {sf::Keyboard::Key::RSystem, EventName::KEY_RSYSTEM_PRESSED},
    {sf::Keyboard::Key::Menu, EventName::KEY_MENU_PRESSED},
    {sf::Keyboard::Key::LBracket, EventName::KEY_LBRACKET_PRESSED},
    {sf::Keyboard::Key::RBracket, EventName::KEY_RBRACKET_PRESSED},
    {sf::Keyboard::Key::Semicolon, EventName::KEY_SEMICOLON_PRESSED},
    {sf::Keyboard::Key::Comma, EventName::KEY_COMMA_PRESSED},
    {sf::Keyboard::Key::Period, EventName::KEY_PERIOD_PRESSED},
    {sf::Keyboard::Key::Apostrophe, EventName::KEY_APOSTROPHE_PRESSED},
    {sf::Keyboard::Key::Slash, EventName::KEY_SLASH_PRESSED},
    {sf::Keyboard::Key::Backslash, EventName::KEY_BACKSLASH_PRESSED},
    {sf::Keyboard::Key::Grave, EventName::KEY_GRAVE_PRESSED},
    {sf::Keyboard::Key::Equal, EventName::KEY_EQUAL_PRESSED},
    {sf::Keyboard::Key::Hyphen, EventName::KEY_HYPHEN_PRESSED},
    {sf::Keyboard::Key::Space, EventName::KEY_SPACE_PRESSED},
    {sf::Keyboard::Key::Enter, EventName::KEY_ENTER_PRESSED},
    {sf::Keyboard::Key::Backspace, EventName::KEY_BACKSPACE_PRESSED},
    {sf::Keyboard::Key::Tab, EventName::KEY_TAB_PRESSED},
    {sf::Keyboard::Key::PageUp, EventName::KEY_PAGE_UP_PRESSED},
    {sf::Keyboard::Key::PageDown, EventName::KEY_PAGE_DOWN_PRESSED},
    {sf::Keyboard::Key::End, EventName::KEY_END_PRESSED},
    {sf::Keyboard::Key::Home, EventName::KEY_HOME_PRESSED},
    {sf::Keyboard::Key::Insert, EventName::KEY_INSERT_PRESSED},
    {sf::Keyboard::Key::Delete, EventName::KEY_DELETE_PRESSED},
    {sf::Keyboard::Key::Add, EventName::KEY_ADD_PRESSED},
    {sf::Keyboard::Key::Subtract, EventName::KEY_SUBTRACT_PRESSED},
    {sf::Keyboard::Key::Multiply, EventName::KEY_MULTIPLY_PRESSED},
    {sf::Keyboard::Key::Divide, EventName::KEY_DIVIDE_PRESSED},
    {sf::Keyboard::Key::Left, EventName::KEY_ARROW_LEFT_PRESSED},
    {sf::Keyboard::Key::Right, EventName::KEY_ARROW_RIGHT_PRESSED},
    {sf::Keyboard::Key::Up, EventName::KEY_ARROW_UP_PRESSED},
    {sf::Keyboard::Key::Down, EventName::KEY_ARROW_DOWN_PRESSED},
    {sf::Keyboard::Key::Numpad0, EventName::KEY_NUMPAD_0_PRESSED},
    {sf::Keyboard::Key::Numpad1, EventName::KEY_NUMPAD_1_PRESSED},
    {sf::Keyboard::Key::Numpad2, EventName::KEY_NUMPAD_2_PRESSED},
    {sf::Keyboard::Key::Numpad3, EventName::KEY_NUMPAD_3_PRESSED},
    {sf::Keyboard::Key::Numpad4, EventName::KEY_NUMPAD_4_PRESSED},
    {sf::Keyboard::Key::Numpad5, EventName::KEY_NUMPAD_5_PRESSED},
    {sf::Keyboard::Key::Numpad6, EventName::KEY_NUMPAD_6_PRESSED},
    {sf::Keyboard::Key::Numpad7, EventName::KEY_NUMPAD_7_PRESSED},
    {sf::Keyboard::Key::Numpad8, EventName::KEY_NUMPAD_8_PRESSED},
    {sf::Keyboard::Key::Numpad9, EventName::KEY_NUMPAD_9_PRESSED},
    {sf::Keyboard::Key::F1, EventName::KEY_F1_PRESSED},
    {sf::Keyboard::Key::F2, EventName::KEY_F2_PRESSED},
    {sf::Keyboard::Key::F3, EventName::KEY_F3_PRESSED},
    {sf::Keyboard::Key::F4, EventName::KEY_F4_PRESSED},
    {sf::Keyboard::Key::F5, EventName::KEY_F5_PRESSED},
    {sf::Keyboard::Key::F6, EventName::KEY_F6_PRESSED},
    {sf::Keyboard::Key::F7, EventName::KEY_F7_PRESSED},
    {sf::Keyboard::Key::F8, EventName::KEY_F8_PRESSED},
    {sf::Keyboard::Key::F9, EventName::KEY_F9_PRESSED},
    {sf::Keyboard::Key::F10, EventName::KEY_F10_PRESSED},
    {sf::Keyboard::Key::F11, EventName::KEY_F11_PRESSED},
    {sf::Keyboard::Key::F12, EventName::KEY_F12_PRESSED},
    {sf::Keyboard::Key::F13, EventName::KEY_F13_PRESSED},
    {sf::Keyboard::Key::F14, EventName::KEY_F14_PRESSED},
    {sf::Keyboard::Key::F15, EventName::KEY_F15_PRESSED},
    {sf::Keyboard::Key::Pause, EventName::KEY_PAUSE_PRESSED}
    // Add other keys as needed
};

std::unordered_map<sf::Keyboard::Key, EventName> EventsManager::SFMLKeyReleasedTranslationMap = {
    {sf::Keyboard::Key::A, EventName::KEY_A_RELEASED},
    {sf::Keyboard::Key::B, EventName::KEY_B_RELEASED},
    {sf::Keyboard::Key::C, EventName::KEY_C_RELEASED},
    {sf::Keyboard::Key::D, EventName::KEY_D_RELEASED},
    {sf::Keyboard::Key::E, EventName::KEY_E_RELEASED},
    {sf::Keyboard::Key::F, EventName::KEY_F_RELEASED},
    {sf::Keyboard::Key::G, EventName::KEY_G_RELEASED},
    {sf::Keyboard::Key::H, EventName::KEY_H_RELEASED},
    {sf::Keyboard::Key::I, EventName::KEY_I_RELEASED},
    {sf::Keyboard::Key::J, EventName::KEY_J_RELEASED},
    {sf::Keyboard::Key::K, EventName::KEY_K_RELEASED},
    {sf::Keyboard::Key::L, EventName::KEY_L_RELEASED},
    {sf::Keyboard::Key::M, EventName::KEY_M_RELEASED},
    {sf::Keyboard::Key::N, EventName::KEY_N_RELEASED},
    {sf::Keyboard::Key::O, EventName::KEY_O_RELEASED},
    {sf::Keyboard::Key::P, EventName::KEY_P_RELEASED},
    {sf::Keyboard::Key::Q, EventName::KEY_Q_RELEASED},
    {sf::Keyboard::Key::R, EventName::KEY_R_RELEASED},
    {sf::Keyboard::Key::S, EventName::KEY_S_RELEASED},
    {sf::Keyboard::Key::T, EventName::KEY_T_RELEASED},
    {sf::Keyboard::Key::U, EventName::KEY_U_RELEASED},
    {sf::Keyboard::Key::V, EventName::KEY_V_RELEASED},
    {sf::Keyboard::Key::W, EventName::KEY_W_RELEASED},
    {sf::Keyboard::Key::X, EventName::KEY_X_RELEASED},
    {sf::Keyboard::Key::Y, EventName::KEY_Y_RELEASED},
    {sf::Keyboard::Key::Z, EventName::KEY_Z_RELEASED},

    {sf::Keyboard::Key::Num0, EventName::KEY_0_RELEASED},
    {sf::Keyboard::Key::Num1, EventName::KEY_1_RELEASED},
    {sf::Keyboard::Key::Num2, EventName::KEY_2_RELEASED},
    {sf::Keyboard::Key::Num3, EventName::KEY_3_RELEASED},
    {sf::Keyboard::Key::Num4, EventName::KEY_4_RELEASED},
    {sf::Keyboard::Key::Num5, EventName::KEY_5_RELEASED},
    {sf::Keyboard::Key::Num6, EventName::KEY_6_RELEASED},
    {sf::Keyboard::Key::Num7, EventName::KEY_7_RELEASED},
    {sf::Keyboard::Key::Num8, EventName::KEY_8_RELEASED},
    {sf::Keyboard::Key::Num9, EventName::KEY_9_RELEASED},
    {sf::Keyboard::Key::Escape, EventName::KEY_ESCAPE_RELEASED},
    {sf::Keyboard::Key::LControl, EventName::KEY_LCTRL_RELEASED},
    {sf::Keyboard::Key::LShift, EventName::KEY_LSHIFT_RELEASED},
    {sf::Keyboard::Key::LAlt, EventName::KEY_LALT_RELEASED},
    {sf::Keyboard::Key::LSystem, EventName::KEY_LSYSTEM_RELEASED},
    {sf::Keyboard::Key::RControl, EventName::KEY_RCTRL_RELEASED},
    {sf::Keyboard::Key::RShift, EventName::KEY_RSHIFT_RELEASED},
    {sf::Keyboard::Key::RAlt, EventName::KEY_RALT_RELEASED},
    {sf::Keyboard::Key::RSystem, EventName::KEY_RSYSTEM_RELEASED},
    {sf::Keyboard::Key::Menu, EventName::KEY_MENU_RELEASED},
    {sf::Keyboard::Key::LBracket, EventName::KEY_LBRACKET_RELEASED},
    {sf::Keyboard::Key::RBracket, EventName::KEY_RBRACKET_RELEASED},
    {sf::Keyboard::Key::Semicolon, EventName::KEY_SEMICOLON_RELEASED},
    {sf::Keyboard::Key::Comma, EventName::KEY_COMMA_RELEASED},
    {sf::Keyboard::Key::Period, EventName::KEY_PERIOD_RELEASED},
    {sf::Keyboard::Key::Apostrophe, EventName::KEY_APOSTROPHE_RELEASED},
    {sf::Keyboard::Key::Slash, EventName::KEY_SLASH_RELEASED},
    {sf::Keyboard::Key::Backslash, EventName::KEY_BACKSLASH_RELEASED},
    {sf::Keyboard::Key::Grave, EventName::KEY_GRAVE_RELEASED},
    {sf::Keyboard::Key::Equal, EventName::KEY_EQUAL_RELEASED},
    {sf::Keyboard::Key::Hyphen, EventName::KEY_HYPHEN_RELEASED},
    {sf::Keyboard::Key::Space, EventName::KEY_SPACE_RELEASED},
    {sf::Keyboard::Key::Enter, EventName::KEY_ENTER_RELEASED},
    {sf::Keyboard::Key::Backspace, EventName::KEY_BACKSPACE_RELEASED},
    {sf::Keyboard::Key::Tab, EventName::KEY_TAB_RELEASED},
    {sf::Keyboard::Key::PageUp, EventName::KEY_PAGE_UP_RELEASED},
    {sf::Keyboard::Key::PageDown, EventName::KEY_PAGE_DOWN_RELEASED},
    {sf::Keyboard::Key::End, EventName::KEY_END_RELEASED},
    {sf::Keyboard::Key::Home, EventName::KEY_HOME_RELEASED},
    {sf::Keyboard::Key::Insert, EventName::KEY_INSERT_RELEASED},
    {sf::Keyboard::Key::Delete, EventName::KEY_DELETE_RELEASED},
    {sf::Keyboard::Key::Add, EventName::KEY_ADD_RELEASED},
    {sf::Keyboard::Key::Subtract, EventName::KEY_SUBTRACT_RELEASED},
    {sf::Keyboard::Key::Multiply, EventName::KEY_MULTIPLY_RELEASED},
    {sf::Keyboard::Key::Divide, EventName::KEY_DIVIDE_RELEASED},
    {sf::Keyboard::Key::Left, EventName::KEY_ARROW_LEFT_RELEASED},
    {sf::Keyboard::Key::Right, EventName::KEY_ARROW_RIGHT_RELEASED},
    {sf::Keyboard::Key::Up, EventName::KEY_ARROW_UP_RELEASED},
    {sf::Keyboard::Key::Down, EventName::KEY_ARROW_DOWN_RELEASED},
    {sf::Keyboard::Key::Numpad0, EventName::KEY_NUMPAD_0_RELEASED},
    {sf::Keyboard::Key::Numpad1, EventName::KEY_NUMPAD_1_RELEASED},
    {sf::Keyboard::Key::Numpad2, EventName::KEY_NUMPAD_2_RELEASED},
    {sf::Keyboard::Key::Numpad3, EventName::KEY_NUMPAD_3_RELEASED},
    {sf::Keyboard::Key::Numpad4, EventName::KEY_NUMPAD_4_RELEASED},
    {sf::Keyboard::Key::Numpad5, EventName::KEY_NUMPAD_5_RELEASED},
    {sf::Keyboard::Key::Numpad6, EventName::KEY_NUMPAD_6_RELEASED},
    {sf::Keyboard::Key::Numpad7, EventName::KEY_NUMPAD_7_RELEASED},
    {sf::Keyboard::Key::Numpad8, EventName::KEY_NUMPAD_8_RELEASED},
    {sf::Keyboard::Key::Numpad9, EventName::KEY_NUMPAD_9_RELEASED},
    {sf::Keyboard::Key::F1, EventName::KEY_F1_RELEASED},
    {sf::Keyboard::Key::F2, EventName::KEY_F2_RELEASED},
    {sf::Keyboard::Key::F3, EventName::KEY_F3_RELEASED},
    {sf::Keyboard::Key::F4, EventName::KEY_F4_RELEASED},
    {sf::Keyboard::Key::F5, EventName::KEY_F5_RELEASED},
    {sf::Keyboard::Key::F6, EventName::KEY_F6_RELEASED},
    {sf::Keyboard::Key::F7, EventName::KEY_F7_RELEASED},
    {sf::Keyboard::Key::F8, EventName::KEY_F8_RELEASED},
    {sf::Keyboard::Key::F9, EventName::KEY_F9_RELEASED},
    {sf::Keyboard::Key::F10, EventName::KEY_F10_RELEASED},
    {sf::Keyboard::Key::F11, EventName::KEY_F11_RELEASED},
    {sf::Keyboard::Key::F12, EventName::KEY_F12_RELEASED},
    {sf::Keyboard::Key::F13, EventName::KEY_F13_RELEASED},
    {sf::Keyboard::Key::F14, EventName::KEY_F14_RELEASED},
    {sf::Keyboard::Key::F15, EventName::KEY_F15_RELEASED},
    {sf::Keyboard::Key::Pause, EventName::KEY_PAUSE_RELEASED}
    // Add other keys as needed
};


std::unordered_map<sf::Mouse::Button, EventName> EventsManager::SFMLMouseButtonPressedTranslationMap = {
    {sf::Mouse::Left, EventName::MOUSE_LEFT_PRESSED},
    {sf::Mouse::Right, EventName::MOUSE_RIGHT_PRESSED},
    {sf::Mouse::Middle, EventName::MOUSE_MIDDLE_PRESSED}
};

std::unordered_map<sf::Mouse::Button, EventName> EventsManager::SFMLMouseButtonReleasedTranslationMap = {
    {sf::Mouse::Left, EventName::MOUSE_LEFT_RELEASED},
    {sf::Mouse::Right, EventName::MOUSE_RIGHT_RELEASED},
    {sf::Mouse::Middle, EventName::MOUSE_MIDDLE_RELEASED}
};