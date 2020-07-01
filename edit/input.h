//=============================================================================
//
// üÍ [input.h]
// Author : ûü®Y½
//
//=============================================================================
#pragma once


//*****************************************************************************
// }Nè`
//*****************************************************************************

// vOª¯·éÆ«Ég¤
#define	USE_KEYBOARD										// é¾·éÆL[{[hÅìÂ\ÉÈé
#define	USE_MOUSE											// é¾·éÆ}EXÅìÂ\ÉÈé
#define	USE_PAD												// é¾·éÆpbhÅìÂ\ÉÈé


/* game padîñ */
#define BUTTON_UP		0x00000001l	// ûüL[ã(.IY<0)
#define BUTTON_DOWN		0x00000002l	// ûüL[º(.IY>0)
#define BUTTON_LEFT		0x00000004l	// ûüL[¶(.IX<0)
#define BUTTON_RIGHT	0x00000008l	// ûüL[E(.IX>0)
#define BUTTON_A		0x00000010l	// `{^(.rgbButtons[0]&0x80)
#define BUTTON_B		0x00000020l	// a{^(.rgbButtons[1]&0x80)
#define BUTTON_C		0x00000040l	// b{^(.rgbButtons[2]&0x80)
#define BUTTON_X		0x00000080l	// w{^(.rgbButtons[3]&0x80)
#define BUTTON_Y		0x00000100l	// x{^(.rgbButtons[4]&0x80)
#define BUTTON_Z		0x00000200l	// y{^(.rgbButtons[5]&0x80)
#define BUTTON_L		0x00000400l	// k{^(.rgbButtons[6]&0x80)
#define BUTTON_R		0x00000800l	// q{^(.rgbButtons[7]&0x80)
#define BUTTON_START	0x00001000l	// rs`qs{^(.rgbButtons[8]&0x80)
#define BUTTON_M		0x00002000l	// l{^(.rgbButtons[9]&0x80)
#define GAMEPADMAX		4			// ¯ÉÚ±·éWCpbhÌÅåðZbg


//*****************************************************************************
// vg^Cvé¾
//*****************************************************************************
HRESULT InitInput(HINSTANCE hInst, HWND hWnd);
void UninitInput(void);
void UpdateInput(void);

//---------------------------- keyboard
bool GetKeyboardPress(int nKey);
bool GetKeyboardTrigger(int nKey);
bool GetKeyboardRepeat(int nKey);
bool GetKeyboardRelease(int nKey);

//---------------------------- mouse
BOOL IsMouseLeftPressed(void);      // ¶NbNµ½óÔ
BOOL IsMouseLeftTriggered(void);    // ¶NbNµ½uÔ
BOOL IsMouseRightPressed(void);     // ENbNµ½óÔ
BOOL IsMouseRightTriggered(void);   // ENbNµ½uÔ
BOOL IsMouseCenterPressed(void);    // NbNµ½óÔ
BOOL IsMouseCenterTriggered(void);  // NbNµ½uÔ
long GetMouseX(void);               // }EXªXûüÉ®¢½Îl
long GetMouseY(void);               // }EXªYûüÉ®¢½Îl
long GetMouseZ(void);               // }EXzC[ª®¢½Îl

//---------------------------- game pad
BOOL IsButtonPressed(int padNo,DWORD button);
BOOL IsButtonTriggered(int padNo,DWORD button);



