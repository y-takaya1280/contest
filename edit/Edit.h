//=============================================================================
//
// マップエディター [Edit.h]
// Author : 髙屋雄平
//
//=============================================================================
#pragma once
//*************************************
//インクルード
//*************************************
#include "main.h"

//********************************
//構造体定義
//********************************
class Material
{
public:
	int type;							//ステージパーツの種類
	bool hit;							//当たり判定の有無

};


class EditMAP 
{

public:
	
	D3DXVECTOR3 pos;					//位置
	D3DXVECTOR3 rot;					//回転
	D3DXVECTOR3 scl;					//規模

	Material matType;

	EditMAP* nextp;						//次のアドレス　（双方向非循環型）
	EditMAP* lastp;						//前のアドレス　 (双方向非循環型）


};

enum MATRIALTYPE
{

	MATERIAL_A,
	MAX_MATERIALTYPE

};

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

void InitEditMap(void);
void UninitEditMap(void);
void UpdateEditMap(void);
void DrawEditMap(void);
