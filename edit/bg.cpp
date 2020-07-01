//=============================================================================
//
// 背景処理 [bg.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "bg.h"
#include "input.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexBG(void);
void SetVertexBG(void);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static LPDIRECT3DTEXTURE9		g_pD3DTexture = NULL;	// テクスチャへのポインタ
static VERTEX_2D				g_vertexWk[NUM_VERTEX];	// 頂点情報格納ワーク

static D3DXVECTOR3				g_pos;					// 背景の位置

char* BG_TEXTURE[] = {
	""


};

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitBG(int type)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	
	// テクスチャーの初期化を行う？
	if (type == 0)
	{
		// テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,					// デバイスへのポインタ
			BG_TEXTURE_FILE,		// ファイルの名前
			&g_pD3DTexture);		// 読み込むメモリー
	}

	g_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// 頂点情報の作成
	MakeVertexBG();

	g_pos.x = -GetPlayer()->pos.x / 4.0f;

	SetVertexBG();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitBG(void)
{
	if(g_pD3DTexture != NULL)
	{	// テクスチャの開放
		g_pD3DTexture->Release();
		g_pD3DTexture = NULL;
	}

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateBG(int type)
{
	// 毎フレーム実行する処理

	SetVertexBG();
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawBG(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	
	// 頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	// テクスチャの設定
	pDevice->SetTexture(0, g_pD3DTexture);

	// ポリゴンの描画
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_POLYGON, g_vertexWk, sizeof(VERTEX_2D));
}

//=============================================================================
// 頂点の作成
//=============================================================================
HRESULT MakeVertexBG(void)
{
	// 頂点座標の設定
	SetVertexBG();

	// rhwの設定
	g_vertexWk[0].rhw =
	g_vertexWk[1].rhw =
	g_vertexWk[2].rhw =
	g_vertexWk[3].rhw = 1.0f;

	// 反射光の設定
	g_vertexWk[0].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	g_vertexWk[1].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	g_vertexWk[2].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	g_vertexWk[3].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);

	// テクスチャ座標の設定
	g_vertexWk[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	g_vertexWk[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	g_vertexWk[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	g_vertexWk[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	return S_OK;
}

//=============================================================================
// 頂点座標の設定
//=============================================================================
void SetVertexBG(void)
{
	// 頂点座標の設定
	g_vertexWk[0].vtx = D3DXVECTOR3(BG_POS_X, BG_POS_Y, 0.0f) + g_pos;
	g_vertexWk[1].vtx = D3DXVECTOR3(BG_POS_X + BG_SIZE_W, BG_POS_Y, 0.0f) + g_pos;
	g_vertexWk[2].vtx = D3DXVECTOR3(BG_POS_X, BG_POS_Y + BG_SIZE_H, 0.0f) + g_pos;
	g_vertexWk[3].vtx = D3DXVECTOR3(BG_POS_X + BG_SIZE_W, BG_POS_Y + BG_SIZE_H, 0.0f) + g_pos;
}
