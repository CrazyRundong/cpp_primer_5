// Ҫ��
// ��ѯ���ַ��������������ַ���A��B��A�ĳ��ȴ���B���ҳ�B�ַ�����A�е�һ�γ��ֵ�λ�á�

#include<stdio.h>

int Instring(char *P)  // �ַ������뺯��
{
	int L = 0;
	char a;
	a = getchar();
	L++;
	*P = a;
	P++;
	while (a != '\n') {
		a = getchar();
		if (a == '\n')
			break;
		L++;
		*P = a;
		P++;
	}
	return L;  // L��¼�����ַ����ĳ���
}


void main() {
	char *A, *B, *P1, *P2, a, b;
	int i, L1, L2;
	A = &a;
	B = &b;
	P1 = A;                                     //Ԥ���ַ����׵�ַ
	P2 = B;
	printf("�������һ���ַ������Իس�����");
	L1 = Instring(A);
	printf("������ڶ����ַ������Իس�����");
	L2 = Instring(B);

	if (L1 < L2)                               //�ܽ���������A
	{
		char *Temp;
		Temp = P1;
		P1 = P2;
		P2 = Temp;

		int temp;
		temp = L1;
		L1 = L2;
		L2 = temp;
	}

	int flag, L, num;
	char *LA, *LB;

	for (i = 0; i <= L1 - L2; i++)                //˳��Ƚϣ�ֻ��Ƚ�L1-L2+1��
	{
		LA = A + i;                             //LA Ϊʵʱ���µ�A����ʼ�ж�λ��
		LB = B;                               //LB ΪB����ʼλ��
		flag = 1;
		L = 0;
		while (flag == 1) {
			if (*LA == *LB) {
				LA++;
				LB++;
				L++;                          //L ��¼��ǰ�Ѽ����ַ�������
				if (L == L2) {
					num = i + 1;              //num ��¼B������A����ʼλ��
					break;
				}
			} else
				flag = 0;
		}
	}

	if (flag == 0)
		printf("�޷���A�����ҵ���Ӧ��B��");
	getchar();
	getchar();
}
