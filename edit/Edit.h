//=============================================================================
//
// �}�b�v�G�f�B�^�[ [Edit.h]
// Author : �����Y��
//
//=============================================================================
#pragma once
//*************************************
//�C���N���[�h
//*************************************
#include "main.h"

//********************************
//�\���̒�`
//********************************
class Material
{
public:
	int type;							//�X�e�[�W�p�[�c�̎��
	bool hit;							//�����蔻��̗L��

};


class EditMAP 
{

public:
	
	D3DXVECTOR3 pos;					//�ʒu
	D3DXVECTOR3 rot;					//��]
	D3DXVECTOR3 scl;					//�K��

	Material matType;

	EditMAP* nextp;						//���̃A�h���X�@�i�o������z�^�j
	EditMAP* lastp;						//�O�̃A�h���X�@ (�o������z�^�j


};

enum MATRIALTYPE
{

	MATERIAL_A,
	MAX_MATERIALTYPE

};

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

void InitEditMap(void);
void UninitEditMap(void);
void UpdateEditMap(void);
void DrawEditMap(void);
