//=============================================================================
//
// �}�b�v�G�f�B�^�[ [Edit.cpp]
// Author : �����Y��
//
//=============================================================================
#include"Edit.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************

#define MAX_MATERIAL (1024)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************

EditMAP g_Edit[MAX_MATERIAL];



char *g_MapMaterialName[MAX_MATERIALTYPE] = {



};

LPDIRECT3DTEXTURE9		g_pD3DTexture[MAX_MATERIALTYPE];	// �e�N�X�`���ւ̃|�C���^



void InitEditMap(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int i = 0; i < MAX_MATERIALTYPE; i++)
	{
		// �e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(pDevice,			// �f�o�C�X�ւ̃|�C���^
			g_MapMaterialName[i],					// �t�@�C���̖��O
			&g_pD3DTexture[i]);						// �ǂݍ��ރ������[
	}

	for (int i = 0; i < MAX_MATERIAL; i++)			//������
	{
		switch (i)
		{
		case 0:										//�ŏ��̎�

			g_Edit[i].lastp = NULL;					//�ЂƂO�̃A�h���X�͂Ȃ�����NULL
			g_Edit[i].nextp = &g_Edit[i + 1];		//�ЂƂ�̃A�h���X

			break;

		case MAX_MATERIAL - 1:						//�Ō�̎�
			g_Edit[i].lastp = &g_Edit[i - 1];		//�ЂƂO�̃A�h���X
			g_Edit[i].nextp = NULL;					//�ЂƂ�̃A�h���X�͂Ȃ�����NULL

			break;

		default:
			g_Edit[i].lastp = &g_Edit[i - 1];		//�ЂƂO�̃A�h���X
			g_Edit[i].nextp = &g_Edit[i + 1];		//�ЂƂ�̃A�h���X

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
		//�e�N�X�`���[�̉��
		g_pD3DTexture[i] = NULL;
	}

	for (int i = 0; i < MAX_MATERIAL; i++)
	{
		//���X�g�\���̉��
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
