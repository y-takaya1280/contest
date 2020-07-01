//=============================================================================
//
// マップエディター [Edit.cpp]
// Author : 髙屋雄平
//
//=============================================================================
#include"Edit.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************

#define MAX_MATERIAL (1024)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************

EditMAP g_Edit[MAX_MATERIAL];



char *g_MapMaterialName[MAX_MATERIALTYPE] = {



};

LPDIRECT3DTEXTURE9		g_pD3DTexture[MAX_MATERIALTYPE];	// テクスチャへのポインタ



void InitEditMap(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int i = 0; i < MAX_MATERIALTYPE; i++)
	{
		// テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,			// デバイスへのポインタ
			g_MapMaterialName[i],					// ファイルの名前
			&g_pD3DTexture[i]);						// 読み込むメモリー
	}

	for (int i = 0; i < MAX_MATERIAL; i++)			//初期化
	{
		switch (i)
		{
		case 0:										//最初の時

			g_Edit[i].lastp = NULL;					//ひとつ前のアドレスはないためNULL
			g_Edit[i].nextp = &g_Edit[i + 1];		//ひとつ後のアドレス

			break;

		case MAX_MATERIAL - 1:						//最後の時
			g_Edit[i].lastp = &g_Edit[i - 1];		//ひとつ前のアドレス
			g_Edit[i].nextp = NULL;					//ひとつ後のアドレスはないためNULL

			break;

		default:
			g_Edit[i].lastp = &g_Edit[i - 1];		//ひとつ前のアドレス
			g_Edit[i].nextp = &g_Edit[i + 1];		//ひとつ後のアドレス

			break;

		}

		g_Edit[i].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Edit[i].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Edit[i].scl = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		g_Edit[i].matType.type = 0;
		g_Edit[i].matType.hit = true;

	}

}

void UninitEditMap(void)
{
	for (int i = 0; i < MAX_MATERIALTYPE; i++)
	{
		//テクスチャーの解放
		g_pD3DTexture[i] = NULL;
	}

	for (int i = 0; i < MAX_MATERIAL; i++)
	{
		//リスト構造の解放
		g_Edit[i].nextp = NULL;
		g_Edit[i].lastp = NULL;
	}

}
void UpdateEditMap(void)
{





}
void DrawEditMap(void)
{


}
