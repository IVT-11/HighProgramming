#include <stdio.h> // ����������� ����������� ����������, ���� �����-������
#include <stdlib.h> // ����������� ����������� ����������, ��� ������ � ���������
#include <math.h> // ����������� �������������� ����������

double f(double ); // �������� ������� �� ���������� ����� ����� �������������
double f(double x) // ������� �� ���������� ����� ����� �������������
{
//return 1/4*log((1+x)/(1-x))+1/2*atanf(x); � ����� ������� �� ���������
return log((1+x)*1.0/(1-x))/4+atan(x)/2; // ������� ���������� ��������� 
}

double row(double ); // �������� ������� �� ���������� ������ ����� �������������
double row(double x) // ������� �� ���������� ������ ����� �������������
{
int count=0; // ����������, ������� ������� ���-�� ���������
double n=0,s=0,eps=1e-14; // ���������� ������������� ����
{
while(abs(f(x))-abs(s)>eps) // �������� ������ �� ����� �������� ���������,
// ������� ������� ������� ����� ������ � ����� ��������� � ������������ � �������� ���������
{
s+=pow(x,4*n+1)/(4*n+1.0); // ������� ����� ���� ��������� �������� �������
n++; // ��������� ������������� �� 1
count++; // ��������� ��� �������� ���-�� ���������
}
printf("\n���-�� ��������� = %d\n",count); // ����� ���-�� ���������
return s; // ������� ���������� ��������� � 
}
}

int main () // ������� ������ ������ ���������
{
double n; // ���������� ������������� ����
printf("������� �������� x = "); // ���� ��������
scanf ("%lf",&n); // ��������� ��������� ��������

while(1) // ���� �� �������� ����� ���������� ��������
{
if(n>-1 && n<1) // �������, ��� ������� ������������� �����������
{
printf("\n%.15lf = %.15lf\n", f(n),row(n)); // ����� ���������
break; // ����� �� ����� ����� ������ ���������
}
else // �������, ��� ������� ������������� �� �����������
{
printf("������� x � �������� �� -1 �� 1\nx = "); // ������������ ����
// ��������� ������ �������� ��� ��� �������� �������
scanf ("%lf",&n); // ��������� ��������� ��������
}
}

return 0; // ������� ���������� �����
}