
#define ID_WINDOW_0            (GUI_ID_USER + 0x00)
#define ID_BUTTON_0            (GUI_ID_USER + 0x01)  // a
#define ID_BUTTON_1            (GUI_ID_USER + 0x02)  // b
#define ID_BUTTON_2            (GUI_ID_USER + 0x03)  // c
#define ID_BUTTON_3            (GUI_ID_USER + 0x04)  // etc..
#define ID_BUTTON_4            (GUI_ID_USER + 0x05)
#define ID_BUTTON_5            (GUI_ID_USER + 0x06)
#define ID_BUTTON_6            (GUI_ID_USER + 0x07)
#define ID_BUTTON_7            (GUI_ID_USER + 0x08)
#define ID_BUTTON_8            (GUI_ID_USER + 0x09)
#define ID_BUTTON_9            (GUI_ID_USER + 0x0A)
#define ID_BUTTON_10           (GUI_ID_USER + 0x0B)
#define ID_BUTTON_11           (GUI_ID_USER + 0x0C)
#define ID_BUTTON_12           (GUI_ID_USER + 0x0D)
#define ID_BUTTON_13           (GUI_ID_USER + 0x0E)
#define ID_BUTTON_14           (GUI_ID_USER + 0x0F)
#define ID_BUTTON_15           (GUI_ID_USER + 0x10)
#define ID_BUTTON_16           (GUI_ID_USER + 0x11)
#define ID_BUTTON_17           (GUI_ID_USER + 0x12)
#define ID_BUTTON_18           (GUI_ID_USER + 0x13)
#define ID_BUTTON_19           (GUI_ID_USER + 0x14)
#define ID_BUTTON_20           (GUI_ID_USER + 0x15)
#define ID_BUTTON_21           (GUI_ID_USER + 0x16)
#define ID_BUTTON_22           (GUI_ID_USER + 0x17)
#define ID_BUTTON_23           (GUI_ID_USER + 0x18)
#define ID_BUTTON_24           (GUI_ID_USER + 0x19)
#define ID_BUTTON_25           (GUI_ID_USER + 0x1A)  // z
#define ID_BUTTON_26           (GUI_ID_USER + 0x1B)  // Back
#define ID_BUTTON_27           (GUI_ID_USER + 0x1C)  // Clr
#define ID_BUTTON_28           (GUI_ID_USER + 0x1D)  // Space

#define ID_WINDOW_1            (GUI_ID_USER + 0x20)
#define ID_EDIT_0              (GUI_ID_USER + 0x21)

#define BUTTON_X_SIZE           30
#define BUTTON_Y_SIZE           30

#define BUTTON_SPACING          5

#define BUTTON_X_POS(x)         BUTTON_SPACING + (x * (BUTTON_X_SIZE + BUTTON_SPACING))

#define OFFSET_SECOND_ROW_X     BUTTON_X_SIZE / 2 + BUTTON_SPACING
#define OFFSET_SECOND_ROW_Y     BUTTON_Y_SIZE + (BUTTON_SPACING * 2)

#define OFFSET_THIRD_ROW_X      BUTTON_X_SIZE + BUTTON_SPACING * 2
#define OFFSET_THIRD_ROW_Y     (BUTTON_Y_SIZE * 2) + (BUTTON_SPACING * 3)

#define COLOR_BUTTON_FRAME_0    GUI_MAKE_COLOR(0x1AC39D)
#define COLOR_BUTTON_FRAME_1    GUI_MAKE_COLOR(0x275BEA)

#define COLOR_BUTTON_BK_0       GUI_MAKE_COLOR(0x613600)
#define COLOR_BUTTON_BK_1       GUI_MAKE_COLOR(0x613600)