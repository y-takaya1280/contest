//=============================================================================
//
// �w�i���� [bg.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "bg.h"
#include "input.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexBG(void);
void SetVertexBG(void);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static LPDIRECT3DTEXTURE9		g_pD3DTexture = NULL;	// �e�N�X�`���ւ̃|�C���^
static VERTEX_2D				g_vertexWk[NUM_VERTEX];	// ���_���i�[���[�N

static D3DXVECTOR3				g_pos;					// �w�i�̈ʒu

char* BG_TEXTURE[] = {
	""


};

//=============================================================================
// ����������
//=============================================================================
HRESULT InitBG(int type)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	
	// �e�N�X�`���[�̏��������s���H
	if (type == 0)
	{
		// �e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(pDevice,					// �f�o�C�X�ւ̃|�C���^
			BG_TEXTURE_FILE,		// �t�@�C���̖��O
			&g_pD3DTexture);		// �ǂݍ��ރ������[
	}

	g_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// ���_���̍쐬
	MakeVertexBG();

	g_pos.x = -GetPlayer()->pos.x / 4.0f;

	SetVertexBG();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitBG(void)
{
	if(g_pD3DTexture != NULL)
	{	// �e�N�X�`���̊J��
		g_pD3DTexture->Release();
		g_pD3DTexture = NULL;
	}

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateBG(int type)
{
	// ���t���[�����s���鏈��

	SetVertexBG();
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawBG(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	
	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pD3DTexture);

	// �|���S���̕`��
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_POLYGON, g_vertexWk, sizeof(VERTEX_2D));
}

//=============================================================================
// ���_�̍쐬
//=============================================================================
HRESULT MakeVertexBG(void)
{
	// ���_���W�̐ݒ�
	SetVertexBG();

	// rhw�̐ݒ�
	g_vertexWk[0].rhw =
	g_vertexWk[1].rhw =
	g_vertexWk[2].rhw =
	g_vertexWk[3].rhw = 1.0f;

	// ���ˌ��̐ݒ�
	g_vertexWk[0].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	g_vertexWk[1].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	g_vertexWk[2].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);
	g_vertexWk[3].diffuse = D3DCOLOR_RGBA(255, 255, 255, 255);

	// �e�N�X�`�����W�̐ݒ�
	g_vertexWk[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	g_vertexWk[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	g_vertexWk[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	g_vertexWk[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	return S_OK;
}

//=============================================================================
// ���_���W�̐ݒ�
//=============================================================================
void SetVertexBG(void)
{
	// ���_���W�̐ݒ�
	g_vertexWk[0].vtx = D3DXVECTOR3(BG_POS_X, BG_POS_Y, 0.0f) + g_pos;
	g_vertexWk[1].vtx = D3DXVECTOR3(BG_POS_X + BG_SIZE_W, BG_POS_Y, 0.0f) + g_pos;
	g_vertexWk[2].vtx = D3DXVECTOR3(BG_POS_X, BG_POS_Y + BG_SIZE_H, 0.0f) + g_pos;
	g_vertexWk[3].vtx = D3DXVECTOR3(BG_POS_X + BG_SIZE_W, BG_POS_Y + BG_SIZE_H, 0.0f) + g_pos;
}
