// �ǽð� ����̹� ��Ʈ�� �ڵ� ����
#pragma once

// �Ϲ�
#define		CF_CTRL							0x0000
#define		CF_CTRL_BSOD_NOW				0x0001 // ALIAS="BSOD �߻�"

// ��ŷ����ȭ ����
#define		HD_CTRL							0x0100
#define		HD_CTRL_ON						0x0101 // ALIAS="��ŷ����ȭ Ȱ��ȭ"
#define		HD_CTRL_OFF						0x0102 // ALIAS="��ŷ����ȭ ��Ȱ��ȭ"
#define		HD_CTRL_STATUS					0x0103 // ALIAS="��ŷ����ȭ ���� ǥ��"

// �ڰ���ȣ ����
#define		SP_CTRL						    0x0200
#define		SP_CTRL_PROCESS_PROTECT_ON  	0x0201 // ALIAS="���μ��� �ڰ���ȣ Ȱ��ȭ"
#define		SP_CTRL_PROCESS_PROTECT_OFF 	0x0202 // ALIAS="���μ��� �ڰ���ȣ ��Ȱ��ȭ"
#define		SP_CTRL_PROCESS_PROTECT_STATUS	0x0203 // ALIAS="���μ��� �ڰ���ȣ ���� ǥ��"
#define		SP_CTRL_PROCESS_PROTECT_BSOD    0x0204 // ALIAS="���μ��� ���� ���� �� BSOD"
#define		SP_CTRL_THREAD_PROTECT_ON		0x0205 // ALIAS="������ �ڰ���ȣ Ȱ��ȭ"
#define		SP_CTRL_THREAD_PROTECT_OFF      0x0206 // ALIAS="������ �ڰ���ȣ ��Ȱ��ȭ"
#define		SP_CTRL_THREAD_PROTECT_STATUS   0x0207 // ALIAS="������ �ڰ���ȣ ���� ǥ��"
#define		SP_CTRL_FILE_PROTECT_ON			0x0208 // ALIAS="���� �ڰ���ȣ Ȱ��ȭ"
#define		SP_CTRL_FILE_PROTECT_OFF        0x0209 // ALIAS="���� �ڰ���ȣ ��Ȱ��ȭ"
#define		SP_CTRL_FILE_PROTECT_STATUS     0x020A // ALIAS="���� �ڰ���ȣ ���� ǥ��"
#define		SP_CTRL_FILE_NOTIFY_ON			0x020B // ALIAS="���� ���� �˸� Ȱ��ȭ"
#define		SP_CTRL_FILE_NOTIFY_OFF         0x020C // ALIAS="���� ���� �˸� ��Ȱ��ȭ"
#define		SP_CTRL_FILE_NOTIFY_STATUS      0x020D // ALIAS="���� ���� �˸� ���� ǥ��"


// ���μ��� ���̺����
#define		PT_CTRL							0x0300
#define		PT_CTRL_DISPLAY_PROCESS_TABLE	0x0301 // ALIAS="���μ��� ���̺� ǥ��"

// ���� Ÿ�� �˻�
#define		FTC_CTRL						0x0400
#define		FTC_CTRL_DISPLAY_EXTENSION_LIST	0x0401 // ALIAS="�˻��� Ȯ���� ��� ǥ��"

// ���� ��ĵ
#define		FS_CTRL							0x0500
#define		FS_CTRL_STATUS					0x0501 // ALIAS="���� ��ĵ ���� ǥ��"

// ���� �Ŵ���
#define		VM_CTRL							0x0600
#define		VM_CTRL_LIST					0x0601 // ALIAS="���� ��� ǥ��"

// ���� ��ĵ ���
#define		FSR_CTRL						0x0700
#define		FSR_CTRL_CLEAR_TABLE			0x0701 // ALIAS="��ĵ �ؽ� ���̺� Ŭ����"

// ��� ��å
#define		PP_CTRL							0x0800
#define		PP_CTRL_POLICY_LIST				0x0801 // ALIAS="��� ��å ����Ʈ ǥ��"

// ���� ����
#define		FM_CTRL							0x0900
#define		FM_CTRL_BSOD_ON_BLOCK			0x0901 // ALIAS="���Ϻ�ȣ ���� ���ܽ� BSOD"
#define     FM_CTRL_PROTECTOR_STATUS        0x0902 // ALIAS="���Ϻ�ȣ ���� ǥ��"