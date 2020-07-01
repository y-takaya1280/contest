//=============================================================================
//
// �t�F�[�h���� [fade.cpp]
// Author : �����Y��
//
//=============================================================================
#include "main.h"
#include "fade.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	FADE_RATE		(0.02f)		// �t�F�[�h�W��

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexFade(void);
void SetColor(D3DCOLOR col);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static LPDIRECT3DTEXTURE9		g_p3DTextureFade = NULL;		// �e�N�X�`���ւ̃|�C���^
static VERTEX_2D				g_vertexWkFade[NUM_VERTEX];		// ���_���i�[���[�N

static D3DXCOLOR				g_color;
static FADE						g_eFade = FADE_IN;
static MODE						g_eScene = MODE_TITLE;			// ���ɔ�ԗ\���Scene
static int						g_sno = -1;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitFade(int type)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ���_���̐ݒ�
	MakeVertexFade();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitFade(void)
{
	if(g_p3DTextureFade != NULL)
	{// �e�N�X�`���̊J��
		g_p3DTextureFade->Release();
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateFade(void)
{
	if(g_eFade != FADE_NONE)
	{// �t�F�[�h������
		if(g_eFade == FADE_OUT)
		{// �t�F�[�h�A�E�g����
			g_color.a += FADE_RATE;		// ���l�����Z���ĉ�ʂ������Ă���
			if(g_color.a >= 1.0f)
			{

				// �t�F�[�h�C�������ɐ؂�ւ�
				g_color.a = 1.0f;
				g_eFade = FADE_MUSIC_STOP;

				// BGM��~
				//StopSound();
			}

			// �F��ݒ�
			SetColor(g_color);
		}
		else if (g_eFade == FADE_MUSIC_STOP)
		{
			// ��Ԃ�؂�
			SetMode(g_eScene);

			// BGM�Đ�
			if (g_sno > -1)
			{
				//PlaySound(g_sno);
			}

			g_eFade = FADE_IN;
		}
		else if(g_eFade == FADE_IN)
		{// �t�F�[�h�C������
			g_color.a -= FADE_RATE;		// ���l�����Z���ĉ�ʂ𕂂��オ�点��
			if(g_color.a <= 0.0f)
			{
				// �t�F�[�h�����I��
				g_color.a = 0.0f;
				g_eFade = FADE_NONE;

			}

			// �F��ݒ�
			SetColor(g_color);
		}
	}
}

//=============================================================================
// �t�F�[�h���
//=============================================================================
void DrawFade()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

	// �|���S���̕`��
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, NUM_POLYGON, g_vertexWkFade, sizeof(VERTEX_2D));
}

//=============================================================================
// ���_�̍쐬
//=============================================================================
HRESULT MakeVertexFade(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// �e�N�X�`���̃p�[�X�y�N�e�B�u�R���N�g�p
	g_vertexWkFade[0].rhw =
	g_vertexWkFade[1].rhw =
	g_vertexWkFade[2].rhw =
	g_vertexWkFade[3].rhw = 1.0f;

	// ���ˌ��̐ݒ�
	g_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	g_vertexWkFade[0].diffuse = g_color;
	g_vertexWkFade[1].diffuse = g_color;
	g_vertexWkFade[2].diffuse = g_color;
	g_vertexWkFade[3].diffuse = g_color;

	// ���_���W�̐ݒ�
	g_vertexWkFade[0].vtx = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_vertexWkFade[1].vtx = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	g_vertexWkFade[2].vtx = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	g_vertexWkFade[3].vtx = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	// �e�N�X�`�����W�̐ݒ�
	g_vertexWkFade[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	g_vertexWkFade[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	g_vertexWkFade[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	g_vertexWkFade[3].tex = D3DXVECTOR2(1.0f, 1.0f);	

	return S_OK;
}

//=============================================================================
// �F��ݒ�
//=============================================================================
void SetColor(D3DCOLOR col)
{
	// ���ˌ��̐ݒ�
	g_vertexWkFade[0].diffuse = col;
	g_vertexWkFade[1].diffuse = col;
	g_vertexWkFade[2].diffuse = col;
	g_vertexWkFade[3].diffuse = col;
}

//=============================================================================
// �t�F�[�h�̏�Ԑݒ�
//=============================================================================
void SetFade(FADE fade, MODE next, int sno )
{
	g_eFade = fade;
	g_eScene = next;
	g_sno = sno;
	
}

//=============================================================================
// �t�F�[�h�̏�Ԏ擾
//=============================================================================
FADE GetFade(void)
{
	return g_eFade;
}
