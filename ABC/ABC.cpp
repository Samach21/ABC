#include<stdio.h>

int check01(char, char, char);
int insert(int, int, int, int, int);
int min(int, int, int);
int med(int, int, int);
int max(int, int, int);

int main()
{
	int p[3];
	char o[3];
	int* n = p;
	char* m = o;
	int whatcase;
	int abc[3];
	int* mn = abc;
	for (int i = 0, j = 0; i < 3; i++, j++)
	{
		if (j >= 0 && j <= 2)
		{
			if (scanf_s("%d", &p[i]) != 1)
			{
				printf("ERROR");
				return -1;
			}
			if (i > 0)
			{
				if (p[i] == p[i - 1])
				{
					printf("ERROR");
					return -1;
				}
				if (i > 1)
				{
					if (p[i] == p[i - 2])
					{
						printf("ERROR");
						return -1;
					}
				}
			}
		}
		if (j == 2)
		{
			i = -1;
		}
		else if (j >= 3 && j <= 6)
		{
			scanf_s("%c", &o[i]);
			int a = o[i];
			if (a == 10)
			{
				i--;
			}
			else if (o[i] != 'A'&& o[i] != 'B' && o[i] != 'C')
			{
				printf("ERROR");
				return -1;
			}
		}
	}
	whatcase = check01(*m, *(m + 1), *(m + 2));
	for (int i = 0; i < 3; i++)
	{
		abc[i] = insert(i, whatcase, *n, *(n + 1), *(n + 2));
		printf("%d ", abc[i]);
	}
	return 0;
}

int check01(char x1, char x2, char x3)
{
	switch (x1)
	{
	case 'A':
		switch (x2)
		{
		case 'B':
			return 1;
			break;
		case 'C':
			return 2;
			break;
		default:
			return 0;
			break;
		}
		break;
	case 'B':
		switch (x2)
		{
		case 'A':
			return 3;
			break;
		case 'C':
			return 4;
			break;
		default:
			return 0;
			break;
		}
		break;
	case 'C':
		switch (x2)
		{
		case 'B':
			return 6;
			break;
		case 'A':
			return 5;
			break;
		default:
			return 0;
			break;
		}
		break;
	default:
		return 0;
		break;
	}
}

int insert(int i, int c, int x1, int x2, int x3)
{
	switch (c)
	{
	case 1:
		switch (i)
		{
		case 0:
			return min(x1, x2, x3);
			break;
		case 1:
			return med(x1, x2, x3);
			break;
		case 2:
			return max(x1, x2, x3);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (i)
		{
		case 0:
			return min(x1, x2, x3);
			break;
		case 1:
			return max(x1, x2, x3);
			break;
		case 2:
			return med(x1, x2, x3);
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (i)
		{
		case 0:
			return med(x1, x2, x3);
			break;
		case 1:
			return min(x1, x2, x3);
			break;
		case 2:
			return max(x1, x2, x3);
			break;
		default:
			break;
		}
		break;
	case 4:
		switch (i)
		{
		case 0:
			return med(x1, x2, x3);
			break;
		case 1:
			return max(x1, x2, x3);
			break;
		case 2:
			return min(x1, x2, x3);
			break;
		default:
			break;
		}
		break;
	case 5:
		switch (i)
		{
		case 0:
			return max(x1, x2, x3);
			break;
		case 1:
			return min(x1, x2, x3);
			break;
		case 2:
			return med(x1, x2, x3);
			break;
		default:
			break;
		}
		break;
	case 6:
		switch (i)
		{
		case 0:
			return max(x1, x2, x3);
			break;
		case 1:
			return med(x1, x2, x3);
			break;
		case 2:
			return min(x1, x2, x3);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

int min(int x, int y, int z)
{
	int r;
	if (x < y && x < z)
	{
		r = x;
	}
	else if (y < z && y < x)
	{
		r = y;
	}
	else if (z < x && z < y)
	{
		r = z;
	}
	return r;
}

int med(int x, int y, int z)
{
	int r;
	if ((x < y && x > z) || (x > y && x < z))
	{
		r = x;
	}
	else if ((y < z && y > x) || (y > z && y < x))
	{
		r = y;
	}
	else if ((z < x && z > y) || (z > x && z < y))
	{
		r = z;
	}
	return r;
}

int max(int x, int y, int z)
{
	int r;
	if (x > y && x > z)
	{
		r = x;
	}
	else if (y > z && y > x)
	{
		r = y;
	}
	else if (z > x && z > y)
	{
		r = z;
	}
	return r;
}
