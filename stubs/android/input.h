#ifndef ANDROID_INPUT_H
#define ANDROID_INPUT_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct AInputEvent AInputEvent;
int32_t AInputEvent_getType(const AInputEvent* event);
int32_t AKeyEvent_getKeyCode(const AInputEvent* key_event);
int32_t AKeyEvent_getScanCode(const AInputEvent* key_event);
int32_t AKeyEvent_getAction(const AInputEvent* key_event);
int32_t AKeyEvent_getMetaState(const AInputEvent* key_event);
int32_t AMotionEvent_getAction(const AInputEvent* motion_event);
float AMotionEvent_getX(const AInputEvent* motion_event, size_t pointer_index);
float AMotionEvent_getY(const AInputEvent* motion_event, size_t pointer_index);
int32_t AMotionEvent_getButtonState(const AInputEvent* motion_event);
int32_t AMotionEvent_getToolType(const AInputEvent* motion_event, size_t pointer_index);
float AMotionEvent_getAxisValue(const AInputEvent* motion_event, int32_t axis, size_t pointer_index);

#define AINPUT_EVENT_TYPE_KEY 1
#define AINPUT_EVENT_TYPE_MOTION 2
#define AKEY_EVENT_ACTION_DOWN 0
#define AKEY_EVENT_ACTION_UP 1
#define AMOTION_EVENT_ACTION_MASK 0xff
#define AMOTION_EVENT_ACTION_DOWN 0
#define AMOTION_EVENT_ACTION_UP 1
#define AMOTION_EVENT_ACTION_MOVE 2
#define AMOTION_EVENT_ACTION_POINTER_INDEX_MASK 0xff00
#define AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT 8
#define AMOTION_EVENT_ACTION_BUTTON_PRESS 11
#define AMOTION_EVENT_ACTION_BUTTON_RELEASE 12
#define AMOTION_EVENT_ACTION_HOVER_MOVE 7
#define AMOTION_EVENT_ACTION_SCROLL 8
#define AMOTION_EVENT_BUTTON_PRIMARY 1
#define AMOTION_EVENT_BUTTON_SECONDARY 2
#define AMOTION_EVENT_BUTTON_TERTIARY 4
#define AMOTION_EVENT_TOOL_TYPE_UNKNOWN 0
#define AMOTION_EVENT_TOOL_TYPE_FINGER 1
#define AMOTION_EVENT_TOOL_TYPE_STYLUS 2
#define AMOTION_EVENT_TOOL_TYPE_MOUSE 3
#define AMOTION_EVENT_TOOL_TYPE_ERASER 4
#define AMOTION_EVENT_AXIS_HSCROLL 10
#define AMOTION_EVENT_AXIS_VSCROLL 9
#define AMETA_CTRL_ON 0x1000
#define AMETA_SHIFT_ON 0x01
#define AMETA_ALT_ON 0x02
#define AMETA_META_ON 0x10000

#ifdef __cplusplus
}
#endif
#endif
